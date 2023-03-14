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

	// решатель
	Vector solve(double end); // возвращает только последний шаг
	Vector nevyazki(double end, Vector nev); // возвращает только невязки
	Matrix full_solve(double end); // возвращает полное решение

	Matrix reverse_solve(double end, Vector fin);

	~RK4_Solver();
};

