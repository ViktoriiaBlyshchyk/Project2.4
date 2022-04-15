#include "Vector.h"

Vector::Vector() 
{
	n = 0;
	size = 0;
}

Vector::Vector(int v) : size(v)
{
	n = new int[size];
	for (int i = 0; i < size; i++)
		n[i] = 0;
}

Vector::Vector(const Vector& v) : size(v.size)
{
	n = new int[size];
	for (int i = 0; i < size; i++)
		n[i] = v.n[i];
}

Vector::~Vector()
{
	delete[] n;
}

Vector& Vector::operator = (const Vector& v)
{
	if (&v == this) return *this; 
	size = v.size;
	delete[] n;

	n = new int[size];
	for (int i = 0; i < size; i++)
		n[i] = v.n[i];
	return *this;
}

Vector::operator string() const
{
	stringstream sout;
	sout << "vector[ " << size << " ] = ( ";
	for (int i = 0; i < size; i++)
		sout << n[i] << ", ";
	sout << ")" << endl;

	return sout.str();
}

ostream& operator << (ostream& out, const Vector& v)
{
	out << string(v);
	return out;
}

istream& operator >> (istream& in, Vector& v)
{
	for (int i = 0; i < v.size; i++)
	{
		cout << "vector[ " << i << " ] = "; in >> v[i];
	}
	cout << endl;
	return in;
}

Vector operator + (Vector& x, Vector& y)
{
	Vector v(x.size);
	if (x.size == y.size)
	{
		for (int i = 0; i < x.size; i++)
			v[i] = x[i] + y[i];
		return v;
	}
	return false;
}

bool operator == (Vector& x, Vector& y)
{
	if (x.size == y.size)
	{
		for (int i = 0; i < x.size; i++)
		{
			if (x[i] = y[i])
				return true;
		}
	}
	return false;
}

double Vector::norm()
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += (n[i] * n[i]);
	}
	return sqrt(sum);
}