#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <ctime>
using namespace std;
typedef  long long LL;
const int N = 1e6;
const double EPS = 1e-6;

double a, b;
double getfun(double x)
{
	return a * x + b;
}

void bs(double l, double r,double &ans)
{

	double mid = (l + r) * 0.5;
	double res = getfun(mid);
	while (fabs(res) > EPS)
	{
		if (res > 0)
		{
			l = mid;
		}
		else
		{
			r = mid;
		}
		mid = (r + l) * 0.5;
		res = getfun(mid);
	}
	ans = mid;
}
int main()
{
	srand(time(NULL));
	cout << "作业2：二分查找函数的根" << endl;
	cout << "输入一次函数的两个参数a，b" << endl;
	cin >> a >> b ;
	while (a == 0)
	{
		cout << "这个方程不可能有根的，换一个吧" << endl;
		cout << "请再输入一次" << endl;
		cin >> a >> b;
	}
	int ll = rand(), rr = rand();
	while (getfun(ll) * getfun(rr) > 0)
	{
		ll = rand();
		rr = rand();
		ll *= -1;
		if (ll > rr)
		{
			swap(ll, rr);
		}
	}
	double ans = 0;
	bs(ll, rr, ans);
	cout << "已经找到函数的一个根为：";
	printf("%.9lf\n", ans);
	return 0;
}
