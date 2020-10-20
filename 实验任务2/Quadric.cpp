#include "Quadric_Equation.h"
#include <cmath>
#include <iostream>

void S_Quadric(int a, int b, int c)
{
	int tmp1 = b * b - 4 * a * c;
	bool fl = 0;
	double x1, x2;
	if (tmp1 < 0)//��deltaС��0������ʵ��
	{
		fl = 0;
	}
	else if (tmp1 == 0)
	{
		x1 = -1.0 * (b / (2 * a));
		x2 = x1;
		fl = 1;
	}
	else
	{
		double tmp = sqrt(tmp1);
		x1 = (-1.0 * b + tmp) / (2.0 * a);
		x2 = (-1.0 * b - tmp) / (2.0 * a);
		fl = 2;
	}
	if (fl == 0)
	{
		std::cout << "�÷�����ʵ��" << std::endl;
	}
	else if (fl == 1)
	{
		std::cout << "�÷���������ͬʵ��x1=x2=" << x1 << std::endl;
	}
	else if (fl == 2)
	{
		std::cout << "�÷�����������ʵ��x1=" << x1 << "x2=" << x2 << std::endl;
	}
}