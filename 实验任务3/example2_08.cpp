//example2_08_1.cpp: 用宏定义实现两数相乘
#include <iostream>
using namespace std;
#define  Multiply(x,y)  (x) * (y)   
int  main()
{
	int a = Multiply(3 + 4, 2 + 3); 
	cout << "a=" << a << endl;
	return 0;
}
/*
将宏参数的两边加上括号即可这时候的宏展开为int a=(3+4)*(2+3)
就可以得到35的结果了。
*/
