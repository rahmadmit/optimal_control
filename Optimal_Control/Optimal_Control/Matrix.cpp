#include "stdafx.h"
#include "Matrix.h"


Matrix::Matrix()
{
	size_r = 0;
	size_c = 0;
	arr = {};
}

Matrix::Matrix(int s)
{
	size_r = s;
	size_c = s;
	arr = vector <Vector> (s);
	for (Vector& i : arr)
	{
		i = Vector(s);
	}
}

Matrix::Matrix(int s_r, int s_c)
{
	size_r = s_r;
	size_c = s_c;
	arr = DMatrix(s_r);
	for (Vector& i : arr)
	{
		i = Vector(size_c);
	}
}

Matrix::Matrix(vector<Vector> m)
{
	size_r = m.size();
	size_c = m[0].get_size();
	arr = DMatrix(size_r);
	for (int i = 0; i < size_r; ++i)
	{
		assert(size_c == m[i].get_size());
		arr[i] = m[i];
	}
}

Matrix::Matrix(vector<DVector> m)
{
	size_r = m.size();
	size_c = m[0].size();
	arr = DMatrix(size_r);
	for (int i = 0; i < size_r; ++i)
	{
		assert(size_c == m[i].size());
		arr[i] = Vector(m[i]);
	}
}

Matrix::Matrix(const Matrix & m)
{
	size_r = m.size_r;
	size_c = m.size_c;
	arr = m.arr;
}

double & Matrix::operator()(int index_r, int index_c)
{
	// TODO: вставьте здесь оператор return
	if (index_r > size_r and index_c > size_c ) throw out_of_range("Out of range exception");
	return arr[index_r](index_c);
}

Vector & Matrix::operator()(int index_r)
{
	// TODO: вставьте здесь оператор return
	if (index_r > size_r) throw out_of_range("Out of range exception");
	return arr[index_r];
}

Matrix Matrix::operator*(double mul)
{
	Matrix res = Matrix(*this);
	for (Vector& i: res.arr)
	{
		i = mul * i;
	}
	return res;
}

Vector Matrix::operator*(Vector v)
{
	Matrix m = *this;
	assert (m.size_c == v.get_size());
	int s = v.get_size();
	Vector res = Vector(s);
	for (int i = 0; i < s; ++i)
	{
		double sum = 0.0;
		for (int j = 0; j < s; ++j)
		{
			sum += m(i, j) * v(j);
		}
		res(i) = sum;
	}
	return res;
}

Matrix Matrix::transpose()
{
	Matrix res = Matrix(this->size_c, this->size_r);
	for (int i=0; i<res.size_r; ++i)
	{
		for (int j = 0; j < res.size_c; ++j)
		{
			res(i, j) = (*this)(j, i);
		}
	}
	return res;
}


Matrix::~Matrix()
{
	size_r = 0;
	size_c = 0;
	arr = {};
}

Matrix operator*(double mul, Matrix m)
{
	return m * mul;
}

ostream & operator<<(ostream & out, const Matrix & m)
{
	// TODO: вставьте здесь оператор return
	for (Vector i : m.arr)
	{
		out << "[" << i << "]" << endl;
	}
	return out;
}

Vector LU_Solve(Matrix m, Vector v)
{
	assert(m.size_r == m.size_c and m.size_c == v.size);
	int size = v.size;
	Matrix L = Matrix(size), U = Matrix(size);

	// LU разложение
	for (int i = 0; i < size; ++i)
	{
		U(0, i) = m(0, i);
		L(i, 0) = m(i, 0) / m(0, 0);
	}
	for (int i = 1; i < size; ++i)
	{
		L(i, i) = 1.0;
		for (int j = i; j < size; ++j)
		{
			double sum = 0;
			for (int k = 0; k < i; ++k)
			{
				sum += L(i, k) * U(k, j);
			}
			U(i, j) = m(i, j) - sum;
		}

		for (int j = i + 1; j < size; ++j)
		{
			L(j, i) = m(j, i) / U(i, i);
			double sum = 0;
			for (int k = 0; k < i; ++k)
			{
				sum += L(j, k) * U(k, i) / U(i, i);
			}
			L(j, i) -= sum;
		}
	}

	// решение СЛАУ
	Vector res = Vector(size), y = Vector(size);
	// L*y = v
	y(0) = v(0);
	for (int i = 1; i < size; ++i)
	{
		double sum = 0;
		for (int j = 0; j < i; ++j)
		{
			sum += L(i, j) * y(j);
		}
		y(i) = v(i) - sum;
	}

	// U*x = y
	res(size - 1) = y(size - 1) / U(size - 1, size - 1);
	for (int i = size - 2; i >= 0; --i)
	{
		double sum = 0;
		for (int j = size - 1; j > i; --j)
		{
			sum += U(i, j) * res(j);
		}
		res(i) = (y(i) - sum) / U(i, i);
	}
	return res;
}
