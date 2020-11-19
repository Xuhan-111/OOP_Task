#include "_Point_.h"
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

double  sigment_len(Point a, Point b)
{
	double x = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	return sqrt(x);
}

void work5()
{
	cout << "-----------------作业5-----------------" << endl;
	cout << endl;
	int x, y;
	cout << "输入第一个点的坐标x1,y1:" << endl;
	cin >> x >> y;
	Point a(x, y);
	cout << "输入第二个点坐标x2,y2:" << endl;
	cin >> x >> y;
	Point b(x, y);
	cout << "点a(" << a.getx() << "," << a.gety() << ")" << endl;
	cout << "点b(" << b.getx() << "," << b.gety() << ")" << endl;
	cout << "距离：" << sigment_len(a, b) << endl;
	cout << endl;
	cout << "输入1改变点a坐标" << endl;
	cout << "输入2改变点b坐标" << endl;
	cout << "输入3获得线段ab长度" << endl;
	cout << "输入0退出" << endl;
	cout << "请输入一个数" << endl;
	int n;
	while (cin >> n)
	{
		if (n == 1)
		{
			cout << "请输入a点的新坐标x，y" << endl;
			int xx, yy;
			cin >> xx >> yy;
			a.changex(xx);
			a.changey(yy);
			cout << "线段ab的长度为：" << sigment_len(a, b) << endl;
		}
		else if (n == 2)
		{
			cout << "请输入b点的新坐标x，y" << endl;
			int xx, yy;
			cin >> xx >> yy;
			b.changex(xx);
			b.changey(yy);
			cout << "线段ab的长度为：" << sigment_len(a, b) << endl;
		}
		else if (n == 3)
		{
			cout << "线段ab的长度是：" << sigment_len(a, b) << endl;
		}
		else if (n == 0)
		{
			break;
		}
		else
		{
			cout << "非法输入" << endl;
		}
		cout << "请输入一个数" << endl;
	}
	cout << endl;
	cout << "-----------------作业5-----------------" << endl;
}
