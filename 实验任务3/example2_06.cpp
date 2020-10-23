//example2_06.cpp：域解析符使全局变量真正具有全局作用域
#include <iostream>
#include <iomanip>
using namespace std;                   		                    
int main()
{
	int sum = 5000;
	int arr[3] = { 10,20,30 };
	{                               
		int i, sum = 0;                    
		for (i = 0; i < 3; i++)
			sum += arr[i];                  
		cout << "sum=" << sum << endl;      
		sum += sum;	                   
		cout << "全局sum=" << sum << endl;  
	}                                
	sum *= 2;                           
	cout << "sum=" << sum << endl;           
	sum = 200;   //直接对sum进行赋值，而非定义，否则报错为重定义                    
	cout << "sum=" << sum << endl;           
	sum += sum;           	          
	cout << "全局sum=" << sum << endl;   
	return 0;
}
/*
原运行结果：
sum=60
全局sum=5060
sum=10120
sum=200
全局sum=10320
思考与练习中运行结果：将原程序19行的定义赋值改为赋值
sum=60
全局sum=120
sum=10000
sum=200
全局sum=400
*/
/*
删除sum前的域解析符，并将19行的定义改为赋值后方可运行程序，因原19行的sum
与函数开头定义的sum在同一程序块中，无法定义两个相同名称的变量。
输出第一个sum是程序块中定义的sum=10+20+30=60。
第一个全局sum也为程序块中定义的sum=60+60=120。
出程序块后，所有sum均为函数开头定义的sum
*/
