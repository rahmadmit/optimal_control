#pragma once
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <assert.h>


using namespace std;
using DVector = vector<double>;

class Matrix;

class Vector
{
private:
	int size;
	DVector num;
public:
	// конструкторы
	Vector();
	Vector(int s);
	Vector(DVector v);
	Vector(const Vector& v);

	// вспомогательные вещи
	int get_size();
	double get_max();

	// перегрузка операторов
	Vector& operator = (const Vector& v);
	double& operator () (int index);
	Vector operator + (Vector v2);
	Vector operator - (Vector v2);
	Vector operator * (double mul);
	friend Vector operator * (double mul, Vector v);
	Vector operator / (double mul);
	double operator * (Vector v2);
	friend ostream& operator << (ostream &out, const Vector& v);

	// решение СЛАУ
	friend Vector LU_Solve(Matrix m, Vector v);
	~Vector();
};

