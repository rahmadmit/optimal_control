#include "stdafx.h"
#include "modified_newton.h"

double local_norm(Matrix jacoby, Vector residuals)
{
	double n = 0.0;
	int size = residuals.get_size();

	for (int i = 0; i < size; ++i)
	{
		double z = 0.0;
		for (int j = 0; j < size; ++j)
		{
			z += jacoby(i, j) * jacoby(i, j);
		}
		n += residuals(i) * residuals(i) / z;
	}
	return sqrt(n);
}

Vector modified_newton(double psi_u_norm, double psi_v_norm, double psi_R_norm, double T_norm)
{
	Vector shooting_param = Vector({ psi_u_norm, psi_v_norm, psi_R_norm, T_norm });
	cout << "BEFORE: " << shooting_param << endl;
	ClassicNewtonResponse t = classic_newton(psi_u_norm, psi_v_norm, psi_R_norm, T_norm);
	Matrix jacoby = get<0>(t);
	Vector b = get<1>(t);
	Vector base_resid = get<2>(t);
	

	Vector classic_shooting_param = LU_Solve(jacoby, b);
	cout << "AFTER: " << classic_shooting_param << endl << "BASE RESID: " << base_resid << endl << "JACOBY: " << jacoby << endl << "Right Wing:" << b << endl;

	Vector step = (classic_shooting_param - shooting_param) / 100.0;
	double norm = local_norm(jacoby, base_resid);
	cout << norm << endl;


	for (int i = 1; i < 100; ++i)
	{
		Vector buff = shooting_param + step * i;
		double based_norm = local_norm(jacoby, RK4(buff(0), buff(1), buff(2), buff(3)));
		cout << i << "    " << based_norm << "\n";
		if (norm < based_norm)
		{
			cout << i << endl;
			return shooting_param + step * (i - 1);
		}
		norm = based_norm;
	}
	return classic_shooting_param;
}

