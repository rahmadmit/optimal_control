#include "stdafx.h"
#include "RK4_Solver.h"


RK4_Solver::RK4_Solver()
{
	call = nullptr;
	start = Vector();
	size = 0;
}

RK4_Solver::RK4_Solver(Callable func_ptr, Vector init)
{
	call = func_ptr;
	start = init;
	size = init.get_size();
}


Vector RK4_Solver::solve(double end)
{
	RK4_Solver solver = *this;
	Matrix result = solver.full_solve(end);
	return result(1000);
}

Vector RK4_Solver::nevyazki(double end, Vector nev)
{
	RK4_Solver solver = *this;
	Vector result = solver.solve(end);
	return result - nev;
}

Matrix RK4_Solver::full_solve(double end)
{
	int s = this->size;
	Matrix result = Matrix(1001, s);
	result(0) = this->start;
	double h = 0.001;
	for (int i = 1; i < 1001; i++)
	{
		Vector k1 = call(result(i - 1), end);
		Vector k2 = call(result(i - 1) + h * k1 / 2.0, end);
		Vector k3 = call(result(i - 1) + h * k2 / 2.0, end);
		Vector k4 = call(result(i - 1) + h * k3, end);

		Vector dy = h * (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;

		result(i) = result(i - 1) + dy;
	}

	return result;
}

Matrix RK4_Solver::reverse_solve(double end, Vector fin)
{
	int s = this->size;
	Matrix result = Matrix(1001, s);
	result(1000) = fin;
	double h = 0.001;
	for (int i = 999; i >= 0; i--)
	{
		Vector k1 = call(result(i + 1), end);
		Vector k2 = call(result(i + 1) - h * k1 / 2.0, end);
		Vector k3 = call(result(i + 1) - h * k2 / 2.0, end);
		Vector k4 = call(result(i + 1) - h * k3, end);

		Vector dy = h * (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;

		result(i) = result(i + 1) - dy;
	}

	return result;
}

RK4_Solver::~RK4_Solver()
{
}
