#include <cstdlib>
#include <cstdio>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <ctime>

using namespace std;
typedef  long long LL;
const int N = 1e6;
const double EPS = 1e-6;

int stdsearch(int x,int l=1, int r=1000)
{
	int mid = (l + r) / 2;
	int cnt = 0;
	while (mid != x)
	{
		cnt++;
		if (mid >= x)
		{
			r = mid;
		}
		else
		{
			l = mid;
		}
		mid = (r + l) / 2;
	}
	return cnt;
}

int main()
{
	cout << "作业3：好玩的猜数游戏" << endl;
	cout << "为了减小游戏时间，所有数都会在1000以内" << endl;
	cout << "输入1开始游戏" << endl;
	srand(time(NULL));
	int q;
	cin >> q;
	while (1)
	{
		if (q == 1)
		{
			int x = rand() % 1000;
			cout << x << endl;
			int cnt = stdsearch(x) + abs(rand() % 4);
			cout << "我想到了一个数x,请你猜一猜。但是你只有" << cnt << "次机会" << endl;
			int T;
			cin >> T;
			while (cnt>=1)
			{
				cnt--;
				if (T >= 1000)
				{
					cout << "太大了，再来试一次吧，这次不算" << endl;
					cin >> T;
					continue;
				}
				if (T > x)
				{
					cout << "高了,";
				}
				else if (T < x)
				{
					cout << "低了，";
				}
				else if (T == x)
				{
					cout << "太棒了！就是这个数" << endl;
					break;
				}
				if (cnt >=1)
				{
					cout << "再试一次吧。不过，你只有 " << cnt << " 次机会了" << endl;
					cin >> T;
				}
				else
				{
					cout << "很遗憾你没有机会了" << endl;
					break;
				}
			}
		}
		else
		{
			cout << "游戏结束" << endl;
			break;
		}
		cout << "输入1继续，或输入其他值结束" << endl;
		cin >> q;
	}
	return 0;
}
