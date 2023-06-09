// Optimal_Control.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Vector.h"
#include "Matrix.h"
#include "RK4_Solver.h"
#include "Derivatives.h"
#include "classic_newton.h"
#include "modified_newton.h"
#include <iostream>
#include <cmath>

using namespace std;

Vector test_func(Vector X, double t)
{
	return Vector({ t * X(1), -t * X(0) });
}


int main()
{
	// Тесты на все модули
	/*
	// Вектора
	Vector a = Vector();
	Vector b = Vector(5);
	vector <double> test = { 1,2,3,4,5 };
	vector <double> test2 = { 10,9,8,7,6 };
	Vector c = Vector(test);
	Vector d = c;
	Vector e = Vector(test2);
	Vector g = e / -3;
	double h = e * b;
	cout << g << endl;
	Vector right = Vector({-1, 0, 1, 0});

	// Матрицы
	Matrix aa = Matrix();
	Matrix ab = Matrix(2);
	Matrix ac = Matrix(2, 4);
	Matrix ad = Matrix({ Vector({2,-1,-2,9}), Vector({-4,6,3,4}), Vector({-4,-2,8,1}), Vector({3,8,-12,3}) });
	Matrix ae = Matrix(ad);
	ae(1, 2) = 34;
	aa = 2 * ad * -3;
	ab = ad.transpose();
	// ad(0) = Vector(c);
	cout << ad * right << endl << right << endl;
	cout << LU_Solve(ad, right);

	// Производные
	double da = d_u(29.8E3, R0, 3.14159265359 / 2.0);
	double db = d_v(0.0, 29.8E3, R0, 3.14159265359 / 2.0);
	double dc = d_R(0.0);
	double dd = d_phi(29.8E3, R0);
	Vector de = func(Vector({0.0, 29.8E3, R0, 0.0, 695.0, 1383.0, -0.0025, 0.0}), 1.0);

	cout << endl << 60 * 60 * 24 * 365 * de;

	// Рунге-Кутта 4
	RK4_Solver test_solver(test_func, Vector({ 0.0, 1.0 }));
	cout << test_solver.solve(3.14159265359);
	RK4_Solver true_solver(func, Vector({0.0, 29.8E3, R0, 0.0, 717.248748832952, 1329.8093023358601, 0.0002498093229989106, 0.0}));
	cout << true_solver.solve(403.5150312037879 * 60 * 60 * 24);
	cout << RK4(1.0320125882488518, 0.9615396256947651, -2.498093229989106, 1.0087875780094697);
	*/



	cout << endl << endl << endl << endl;
	double psi_u = 1.0, psi_v = 1.0, psi_R = 1.0, T = 1.0;
	for (int i = 0; i < 250; ++i)
	{
		Vector new_param = modified_newton(psi_u, psi_v, psi_R, T);
		psi_u = new_param(0);
		psi_v = new_param(1);
		psi_R = new_param(2);
		T = new_param(3);

		cout << "After " << i << " iteration: " << psi_u0 * psi_u << " " << psi_v0 * psi_v << " " << psi_R0 * psi_R << " " << T0 * T << endl;


		Vector nev = RK4(psi_u, psi_v, psi_R, T);
		cout << nev << nev.get_max() << endl;
		if (nev.get_max() < 0.000001)
		{
			cout << "Finish calculation!";
			cout << "Flight time: " << T0 * T / 86400.0;
			RK4_final_print(psi_u, psi_v, psi_R, T);
			break;
		}
	}
	system("pause");
    return 0;
}

