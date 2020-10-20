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
/* 
example2_01 精度控制
*/
int digit(int n)
{
	int cnt = 0;
	while (n)
	{
		n = n / 10;
		cnt++;
	}
	return cnt;
}
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
	char c;
	int a;
	float f;
	cin >> c >> a >> f;
	a += c;
	f += 2 * a;
	cout.precision(digit((int)(f)) + 1);
	cout << "c=" << c << " a=" << a << " f=" << f << endl;
	return 0;
}
