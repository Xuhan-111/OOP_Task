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

using namespace std;
typedef  long long LL;
const int N = 1e6;

void getfib(LL* fibb,int x)
{
	for (int i = 3; i <= x; ++i)
	{
		fibb[i] = fibb[i - 1] + fibb[i - 2];
	}
}

int main()
{
    cout << "作业1:斐波那契数列前n项" << endl;
    int n;
    cout << "请输入一个数n" << endl;
    cin >> n;
    LL* fib = new LL[n + 7]{ 0,1,1 };
    getfib(fib, n);
    for (int i = 1; i <= n; ++i)
    {
        cout << fib[i] << (i == n ? '\n' : ' ');
    }
    delete[] fib;
	return 0;
}
