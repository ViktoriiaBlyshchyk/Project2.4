#pragma once
#include <iostream>
#include <string> 
#include <sstream>

using namespace std;

class Vector
{
	int size;
	int* n;

public:
	Vector();
	Vector(int);
	Vector(const Vector&);
	~Vector();

	int GetVector() const { return size; }
	void SetVector(int value) { size = value; }

	Vector& operator = (const Vector&);
	operator string() const;

	int& operator [] (const int i) { return n[i]; }
	const int& operator [] (const int i) const { return n[i]; }

	friend ostream& operator << (ostream& out, const Vector& v);
	friend istream& operator >> (istream& in, Vector& v);

	friend Vector operator + (Vector&, Vector&);
	friend bool operator == (Vector&, Vector&);
	double norm();
};

