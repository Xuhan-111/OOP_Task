//example2_05.cpp：局部变量随用随定义及作用域问题示例。
#include <iostream>
#include <iomanip>
using namespace std;             //使用C++的标准名字空间
int main()
{
	int arr[3] = { 0 }, i = 123;  
	cout << "i=" << i << endl;       
                        
		for (int i = 0; i < 2; i++)     
			arr[i] = (i + 5) * 10 + 3;
		cout << "i=" << i << endl;    
		arr[2]++;
		cout << "i=" << i << endl;                            

	cout << "i=" << i << endl;       
	int sum = 0;                
	for (i = 0; i < 3; i++)           
		sum += arr[i];
	cout << "i=" << i << endl;       
	for (i = 0; i < 3; i++)       	
		cout << setw(4) << arr[i];   
	cout << endl;
	cout << "i=" << i << ",sum=" << sum << endl;  
	return 0;
}
/*
运行结果：
i=123
i=123
i=123
i=123
i=3
  53  63   1
i=3,sum=117
*/

/*
程序分析：
在c++ 11版本的编译器下，该程序可以运行。由于去掉了原有的大括号，
在第10行for循环中定义的第二个i变量只在该for循环中生效。
在第18行进入for循环前所有的i均为函数开头所定义的i，其值为123。
出18行for循环后，i值变为3。
*/
