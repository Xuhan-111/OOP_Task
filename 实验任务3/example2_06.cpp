//example2_06.cpp：域解析符使全局变量真正具有全局作用域
#include <iostream>
#include <iomanip>
using namespace std;                   //使用C++的标准名字空间
int sum = 5000; 		                 //定义全局变量sum      
int main()
{
	int sum = 200;
	int arr[3] = { 10,20,30 };
	{                                
		int i, sum = 0;                                  
		for (i = 0; i < 3; i++)
			sum += arr[i];                 
		cout << "sum=" << sum << endl;       
		::sum += sum;	                   
		cout << "全局sum=" << ::sum << endl;  
	}                                
	sum *= 2;                            
	cout << "sum=" << sum << endl;                                   	
	cout << "sum=" << sum << endl;          
	::sum += sum;           	          	
	cout << "全局sum=" << ::sum << endl;     
	return 0;
}
/*
原程序运行结果:
sum=60
全局sum=5060
sum=10120
sum=200
全局sum=10320
修改后程序运行结果:
sum=60
全局sum=5060
sum=400
sum=400
全局sum=5460
*/
/*
程序分析：
调整后sum=200是第一个被定义的局部变量。在小程序块中定义了第二个局部变量
sum。因此第一个输出语句输出的是对arr数组中数据求和的结果，为60。由于使用了
域解析符，第二个输出语句输出的是修改后的全局变量sum值，为5060。
小程序块结束，第二个全局变量sum作用结束。之后的sum*=2是对局部变量sum的
修改，之后的两个输出语句输出的均为局部变量sum的值，为400。::sum+=sum;
语句中，左边的sum显然是全局变量sum，右边则为局部变量sum，即为5060+400=5460。
最后一条输出语句输出的是全局变量sum的值，为5460。
*/
