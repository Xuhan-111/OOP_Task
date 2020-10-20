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
const int N = 1e6;
#define endl '\n';
/* 
example2_04 名字空间使用
*/
namespace one
{
	const int M = 200;
	int inf = 10;
}

namespace two
{
	int x;
	int inf = -100;
}
using namespace one;
using namespace two;
int main()
{
//	std::ios::sync_with_stdio(false);
//  std::cin.tie(0);
//  std::cout.tie(0);
	x = -100;
	cout << one::inf << endl;
	cout << M << endl;
	two::inf *= 2;
	cout << two::inf << endl;
	cout <<x << endl;
	return 0;
}
/*
程序分析：
在源程序中，在namespace one 和 namespace two中均定义了相同名字的变量inf
如果直接使用inf，则不能分清究竟是哪一个名字空间。所以需要使用域解析符来标记
指明来自的名字空间。如果在main函数前已经声明using namespace one/two
则两名字空间中独有的变量可以直接使用。如未声明，必须使用域解析符来使用。

*/
