#include "stdafx.h"
#include "classic_newton.h"

Vector RK4(double psi_u_norm, double psi_v_norm, double psi_R_norm, double T_norm)
{
	RK4_Solver solver = RK4_Solver(func, Vector({ u0,v0,R0,phi0,psi_u0 * psi_u_norm,  psi_v0 * psi_v_norm, psi_R0 * psi_R_norm, 0.0 }));
	double T = T0 * T_norm;
	Vector res = solver.solve(T);
	return Vector({ res(0), (res(1) - v1) / v1, (res(2) - R1) / R1, H(res) });
}

Matrix form_residuals_matrix(double psi_u_norm, double psi_v_norm, double psi_R_norm, double T_norm)
{
	return Matrix(
		{ 
			RK4(psi_u_norm, psi_v_norm, psi_R_norm, T_norm),
			RK4(psi_u_norm + dx, psi_v_norm, psi_R_norm, T_norm),
			RK4(psi_u_norm, psi_v_norm + dx, psi_R_norm, T_norm),
			RK4(psi_u_norm, psi_v_norm, psi_R_norm + dx, T_norm),
			RK4(psi_u_norm, psi_v_norm, psi_R_norm, T_norm + dx),
		}
	);
}

Matrix form_Jacobi_matrix(Matrix residuals)
{
	return Matrix(
		{
			(residuals(1) - residuals(0)) / dx,
			(residuals(2) - residuals(0)) / dx,
			(residuals(3) - residuals(0)) / dx,
			(residuals(4) - residuals(0)) / dx,
		}
	).transpose();
}

ClassicNewtonResponse classic_newton(double psi_u_norm, double psi_v_norm, double psi_R_norm, double T_norm)
{
	Matrix residuals = form_residuals_matrix(psi_u_norm, psi_v_norm, psi_R_norm, T_norm);
	Matrix A = form_Jacobi_matrix(residuals);
	Vector B = A * Vector({ psi_u_norm, psi_v_norm, psi_R_norm, T_norm }) - residuals(0);
	ClassicNewtonResponse res = make_tuple(A, B, residuals(0));
	return res;
}