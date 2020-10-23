#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <cstring>

using namespace std;
typedef  long long LL;
const int maxn = 1e6;
#define endl '\n';


bool cmp(double a, double b)//sort 排序控制函数，从大到小排列
{
	return a > b;
}
bool check(double a, double b, double c)//判断三角形是否合法
{
	if (a + b > c && a + c > b && b + c > a && abs(a - b) < c && abs(b - c) < a && abs(c - a) < b)
	{
		return 1;
	}
	return 0;
}
double solve(double a, double b, double c)//使用海伦公式计算三角形面积
{
	double p = (a + b + c) / 2;
	double ans = p * (p - a) * (p - b) * (p - c);
	return sqrt(ans);
}
double ans1[10];//储存最大周长答案
double ans2[10];//储存最大面积答案
int main()
{
	cout << "请输入一个数n代表要输入的边数" << endl;
	int n;
	cin >> n;
	double* a = new double[n + 7];//创建a数组，为防止可能的越界，多增加了7个空间。
	for (int i = 1; i <= n; ++i)//读入n条边
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, cmp);//使用sort排序，cmp控制sort的排序方式，为从大到小排序
	for (int i = 1; i <= n - 2; ++i)//for 循环遍历n-2条边
	{
		if (a[i] >= a[i + 1] + a[i + 2])
		{
			//由于是从大到小排序，直接判断最大边是否大于两小边之和
			//即可判断这三边能否构成三角形
			continue;
		}
		else//如果可以构成三角形，则三角形一定是周长最大的三角形
		{
			ans1[1] = a[i];
			ans1[2] = a[i + 1];
			ans1[3] = a[i + 2];
			break;
		}
		}
	cout << "最大周长：" << ans1[1] + ans1[2] + ans1[3] << " 选择(" << ans1[3] << " " << ans1[2] << " " << ans1[1] << ")" << endl;
	double res = -1;//用于储存最大的面积，由于要使用max函数，因此初值要尽量小
	for (int i = 1; i <= n - 2; ++i)
	{
		if (check(a[i], a[i + 1], a[i + 2]))//使用check函数判断三角形是否合法
		{
			double mianji = solve(a[i], a[i + 1], a[i + 2]);//使用solve函数计算面积
			if (res < mianji)//记录最大面积对应的三角形三边长度
			{
				res = mianji;
				ans2[1] = a[i];
				ans2[2] = a[i + 1];
				ans2[3] = a[i + 2];
			}
		}
	}
	delete [] a;//释放a数组的空间
	cout << "最大面积：" << res << " 选择(" << ans2[3] << " " << ans2[2] << " " << ans2[1] << ")" << endl;
	return 0;
}
