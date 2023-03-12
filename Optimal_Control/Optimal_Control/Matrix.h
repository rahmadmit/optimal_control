#pragma once
#include <vector>
#include <iostream>
#include <iomanip>
#include <assert.h>
#include "Vector.h"

using DMatrix = vector<Vector>;
using namespace std;

class Matrix
{
private:
	int size_r;
	int size_c;
	DMatrix arr;
public:
	// конструкторы
	Matrix();
	Matrix(int s);
	Matrix(int s_r, int s_c);
	Matrix(vector<DVector> m);
	Matrix(vector<Vector> m);
	Matrix(const Matrix& m);

	//перегрузка операторов
	double& operator () (int index_r, int index_c);
	Vector& operator () (int index_r);
	Matrix operator * (double mul);
	friend Matrix operator * (double mul, Matrix m);
	Vector operator * (Vector v);
	Matrix transpose();

	friend ostream& operator << (ostream &out, const Matrix& m);

	// решение СЛАУ
	friend Vector LU_Solve(Matrix m, Vector v);
	~Matrix();
};

