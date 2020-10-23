//example2_07.cpp：形式参数带默认参数值的函数定义及调用示例
#include <iostream>
using namespace std;
//原程序
void Fun(int i, int j = 5, int k = 10);

int main()
{
	Fun(20);                    									
	Fun(20, 30);                 	
	Fun(20, 30, 40);               	
	return 0;
}

void Fun(int i, int j, int k)        
{
	cout << i << "  " << j << "  " << k << endl;
}

/*
原程序运行结果：
20  5  10
20  30  10
20  30  40
现运行结果：
①error，Fun(20)只提供了一个参数，而实际需要至少两个参数
②
20  5  10
20  30  10
20  30  40
③error Fun(int i, int j = 5, int k)函数形参默认值设置有误，
没有做到“一刀两断”
④error Fun(int i = 1, int j, int k = 10);函数形参默认值设置有误，
没有做到“一刀两断”
*/
