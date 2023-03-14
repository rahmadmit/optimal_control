#pragma once
#include "Matrix.h"
# include "Derivatives.h"

using Callable = Vector (*) (Vector, double);

class RK4_Solver
{
private:
	Callable call;
	Vector start;
	int size;
public:
	RK4_Solver();
	RK4_Solver(Callable func_ptr, Vector init);

	// ��������
	Vector solve(double end); // ���������� ������ ��������� ���
	Vector nevyazki(double end, Vector nev); // ���������� ������ �������
	Matrix full_solve(double end); // ���������� ������ �������

	Matrix reverse_solve(double end, Vector fin);

	~RK4_Solver();
};

