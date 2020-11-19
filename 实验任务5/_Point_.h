#pragma once
#include "_Point_.h"
#include<cmath>

class Point
{
public:
	double x;
	double y;
	friend class sigment;
	Point(double X = 0, double Y = 0)
	{
		x = X;
		y = Y;
	}
	void changex(double X)
	{
		x = X;
	}
	void changey(double Y)
	{
		y = Y;
	}
	double getx()
	{
		return x;
	}
	double gety()
	{
		return y;
	}
};
class sigment
{
private:
	Point a;
	Point b;
public:
	friend double sigment_len();
};

void work5();
