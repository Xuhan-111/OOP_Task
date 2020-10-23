#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;
typedef  long long LL;
const int maxn = 1e6;
#define endl '\n';

/*
example2_05_1 思考与练习1
*/
int main()
{
	int sum = 0;
	int arr[3] = { 0 }, i = 123;      
	cout << "i=" << i << endl;        

	{                           
		for (int i = 0; i < 2; i++)     
			arr[i] = (i + 5) * 10 + 3;
		cout << "i=" << i << endl;     
		arr[2]++;
		cout << "i=" << i << endl;   
	}                           

	cout << "i=" << i << endl;                     
	for (i = 0; i < 3; i++)           
		sum += arr[i];
	cout << "i=" << i << endl;       
	for (i = 0; i < 3; i++)       	 
		cout << setw(4) << arr[i];
	cout << endl;
	cout << "i=" << i << ",sum=" << sum << endl; 
	return 0;
	return 0;
}

/*
程序分析：
局部变量随用随定义，如果将sum变量移至函数开头，不会对程序的运行结果
产生任何影响。只是，在函数前半段未进行对sum的操作时，该变量一直没有
发挥作用
*/
