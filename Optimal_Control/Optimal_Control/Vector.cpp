#include "stdafx.h"
#include "Vector.h"


Vector::Vector()
{
	size = 0;
	num = {};
}

Vector::Vector(int s)
{
	size = s;
	num = DVector (s);
}

Vector::Vector(DVector v)
{
	size = v.size();
	num = v;
}

Vector::Vector(const Vector & v)
{
	size = v.size;
	num = v.num;
}


int Vector::get_size()
{
	return this->size;
}

double Vector::get_max()
{
	double m = fabs(num[0]);
	for (double i : num)
	{
		if (fabs(i) > m) m = fabs(i);
	}
	return m;
}


Vector& Vector::operator = (const Vector & v)
{
	// TODO: вставьте здесь оператор return
	size = v.size;
	num = v.num;
	return *this;
}

double & Vector::operator()(int index)
{
	// TODO: вставьте здесь оператор return
	if (index > size) throw out_of_range("Out of range exception");
	return num[index];
}

Vector Vector::operator+(Vector v2)
{
	assert (this->size == v2.size);
	Vector res = Vector(v2.size);
	for (int i = 0; i < v2.size; ++i) {
		res(i) = this->num[i] + v2.num[i];
	}
	return res;
}

Vector Vector::operator-(Vector v2)
{
	assert(this->size == v2.size);
	Vector res = Vector(v2.size);
	for (int i = 0; i < v2.size; ++i) {
		res(i) = this->num[i] - v2.num[i];
	}
	return res;
}

Vector Vector::operator*(double mul)
{
	Vector res = Vector(this->size);
	for (int i = 0; i < this->size; ++i) {
		res(i) = this->num[i] * mul;
	}
	return res;
}

Vector Vector::operator/(double mul)
{
	Vector res = Vector(this->size);
	for (int i = 0; i < this->size; ++i) {
		res(i) = this->num[i] / mul;
	}
	return res;
}

double Vector::operator*(Vector v2)
{
	assert(this->size == v2.size);
	double s = 0.0;
	for (int i = 0; i < v2.size; ++i)
	{
		s += this->num[i] * v2.num[i];
	}
	return s;
}

Vector::~Vector()
{
	size = 0;
	num = {};
}

Vector operator*(double mul, Vector v)
{
	return v * mul;
}

ostream& operator<< (ostream & out, const Vector & v)
{
	// TODO: вставьте здесь оператор return
	out << "[";
	for (double i: v.num)
	{
		out << setw(20) << setprecision(10) << i;
	}
	out << "]";
	return out;
	 
}
