#include "_Triangle_.h"
#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

void work3()
{
	cout << "-----------------作业3-----------------" << endl << endl;
	int a, b, c;
	cout << "请输入三条整数型的边" << endl;
	cin >> a >> b >> c;
	double da, db, dc;
	cout << "请输入三条浮点型的边" << endl;
	cin >> da >> db >> dc;
	Triangle <int> T_int(a, b, c);
	Triangle <double> T_double(da, db, dc);
	if (T_int.isTriangle())
	{
		cout << "三边为" << T_int.geta() << " " << T_int.getb() << " " << T_int.getc() << "的三角形"
			<< "周长为:" << T_int.Cri() << " 面积为:" << T_int.Area() << endl;
		int type = T_int.gettype();
		cout << "该三角形是";
		if (type > 0)
		{
			cout << "钝角三角形" << endl;
		}
		else if (type == 0)
		{
			cout << "直角三角形" << endl;
		}
		else
		{
			cout << "锐角三角形" << endl;
		}
	}
	else
	{
		cout << "长度为" << T_int.geta() << " " << T_int.getb() << " " << T_int.getc() << " 的三边不能组成三角形";
	}
	if (T_double.isTriangle())
	{
		cout << "三边为" << T_double.geta() << " " << T_double.getb() << " " << T_double.getc() << "的三角形"
			<< "周长为:" << T_double.Cri() << " 面积为:" << T_double.Area() << endl;
		int type = T_double.gettype();
		cout << "该三角形是";
		if (type > 0)
		{
			cout << "钝角三角形" << endl;
		}
		else if (type == 0)
		{
			cout << "直角三角形" << endl;
		}
		else
		{
			cout << "锐角三角形" << endl;
		}
	}
	else
	{
		cout << "长度为" << T_double.geta() << " " << T_double.getb() << " " << T_double.getc() << " 的三边不能组成三角形";
	}
	cout << endl;
	cout << "-----------------作业3-----------------" << endl;
}
