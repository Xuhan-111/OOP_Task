#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include "_Student_.h"
#include "_Point_.h"
#include "_Mystring_.h"
#include "_Stack_.h"
#include "_Triangle_.h"

using namespace std;
typedef  long long LL;
const int N = 1007;


LL read()
{
    LL x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch>'9')
    {
        if (ch == '-')
        {
            w = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return w * x;
}

int main()
{
	work1();
	work2();
	work3();
	work4();
	work5();
	return 0;
}
