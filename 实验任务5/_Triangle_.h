#pragma once
#include "_Triangle_.h"
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

template <typename T>
class Triangle
{
private:
	T eda;
	T edb;
	T edc;
public:
	Triangle(T aa, T bb, T cc)
	{
		eda = aa;
		edb = bb;
		edc = cc;
		if (eda > edb)
		{
			swap(eda, edb);
		}
		if (eda > edc)
		{
			swap(eda, edc);
		}
		if (edb > edc)
		{
			swap(edb, edc);
		}

	}
	Triangle()
	{
		eda = 0;
		edb = 0;
		edc = 0;
	}
	bool isTriangle()
	{
		if (eda + edb > edc && eda + edc > edb && edb + edc > eda && eda - edb < edc && eda - edc < edb && edb - edc < eda)
		{
			return 1;
		}
		return 0;
	}
	T Cri()
	{
		return eda + edb + edc;
	}
	double Area()
	{
		double x = (eda + edb + edc) * 1.0;
		x /= 2.0;
		double ans = x * (x - eda) * (x - edb) * (x - edc);
		return sqrt(ans);
	}
	int gettype()
	{
		if (edc * edc > (edb * edb + eda * eda))
		{
			return 1;
		}
		else if (edc * edc < (edb * edb + eda * eda))
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}
	T geta()
	{
		return eda;
	}
	T getb()
	{
		return edb;
	}
	T getc()
	{
		return edc;
	}
};

void work3();
