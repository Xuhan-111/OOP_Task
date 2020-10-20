#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include "_Calendar_.h"
#include "_SWAP_.h"
#include "_Triangle_.h"
#include "Quadric_Equation.h"

using namespace std;

typedef long long LL;
#define endl '\n';

void help()
{
	cout << "输入数字1进行任务1：解一元二次方程" << endl;
	cout << "输入数字2进行任务2：计算三角形面积" << endl;
	cout << "输入数字3进行任务3：交换两数" << endl;
	cout << "输入数字4进行任务4：日期计算（暂时不支持计算周）" << endl;
	cout << "输入数字5获取输入帮助" << endl;
	cout << "输入数字0退出" << endl;
	cout << endl;
}
int main()
{
	double xx, yy, zz;
	int a, b, c;
	int T;
	cout << "面向对象的程序设计及C++实验任务二" << endl;
	help();
	cout << "请输入一个数字选取实验" << endl;
	while (cin >> T)
	{
		if (T == 1)
		{
			cout << "任务1：请输入一个一元二次方程的三个系数a,b,c" << endl;
			cin >> a >> b >> c;
			S_Quadric(a, b, c);
			cout << endl;
		}
		else if (T == 2)
		{
			cout << "任务2：输入三角形三边a,b,c" << endl;
			cin >> xx >> yy >> zz;
			double ans1;
			if (Triangle_Area(&xx, &yy, &zz, ans1))
			{
				cout << "该三角形的面积是" << ans1 << endl;
				cout << endl;
			}
			else
			{
				cout << "输入错误,无法构成三角形" << endl;
				cout << endl;
			}
		}
		else if (T == 3)
		{
			cout << "任务3：交换两数，请输入两数" << endl;
			cin >> a >> b;
			cout << "交换前a=" << a << " b=" << b << endl;
			SWAP(a, b);
			cout << "交换后a=" << a << " b=" << b << endl;
			cout << endl;
		}
		else if (T == 4)
		{
			cout << "任务4：输入年月日判断是该年的第几天，在该年的第几周" << endl;
			cin >> a >> b >> c;
			rili(a, b, c);
			cout << endl;
		}
		else if (T == 5)
		{
			help();
		}
		else if (T == 0)
		{
			break;
		}
		cout << "请输入一个数字选取实验" << endl;
	}

	return 0;
}
