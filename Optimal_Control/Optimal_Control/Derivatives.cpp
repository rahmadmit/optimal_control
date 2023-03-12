#include "stdafx.h"
#include "Derivatives.h"

double d_u(double v, double R, double theta)
{
	return v * v / R - A0 * R0 * R0 / R / R + alpha * R0 * R0 / R / R * cos(theta) * cos(theta) * cos(theta);
}

double d_v(double u, double v, double R, double theta)
{
	return -u * v / R - alpha * (R0 * R0 / R / R) * cos(theta) * cos(theta) * sin(theta);
}

double d_R(double u)
{
	return u;
}

double d_phi(double v, double R)
{
	return v / R;
}

double d_psi_u(double psi_r, double psi_v, double v, double R)
{
	return -psi_r + psi_v * v / R;
}

double d_psi_v(double psi_u, double v, double R, double psi_v, double u)
{
	return -2 * psi_u * v / R + psi_v * u / R;
}

double d_psi_R(double psi_u, double v, double R, double theta, double psi_v, double u)
{
	return -psi_u * (
		-v * v / R / R
		+ 2 * A0 * R0 * R0 / R / R / R
		- 2 * alpha * R0 * R0 / R / R / R * cos(theta) * cos(theta) * cos(theta)
		) - psi_v * (
			u * v / R / R
			+ 2 * alpha * R0 * R0 / R / R / R * sin(theta) * cos(theta) * cos(theta)
			);
}

double d_psi_phi()
{
	return 0.0;
}

double angle(double psi_u, double psi_v)
{
	return atan((3 * psi_u - sqrt(9 * psi_u * psi_u + 8 * psi_v * psi_v)) / (4 * psi_v));
}

Vector func(Vector X, double T)
{
	int size = X.get_size();
	double theta = angle(X(4), X(5));
	return Vector(
		{ 
			T * d_u(X(1), X(2), theta),
			T * d_v(X(0), X(1), X(2), theta),
			T * d_R(X(0)),
			T * d_phi(X(1), X(2)),
			T * d_psi_u(X(6), X(5), X(1), X(2)),
			T * d_psi_v(X(4), X(1), X(2), X(5), X(0)),
			T * d_psi_R(X(4), X(1), X(2), theta, X(5), X(0)),
			T * d_psi_phi()
		}
	);
}

double H(Vector X)
{
	double theta = angle(X(4), X(5));
	return (
		X(4) * d_u(X(1), X(2), theta)
		+ X(5) * d_v(X(0), X(1), X(2), theta)
		+ X(6) * d_R(X(0))
		- 1
	);
}
