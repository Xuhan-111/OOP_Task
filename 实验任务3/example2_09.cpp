//example2_09.cpp：重载函数示例
#include <iostream>
using namespace std;
int square(int x = 10)
{
	return x * x;
}
float square(float x)                       	
{
	return x * x;
}
double square(double x = 1.5)                 	
{
	return x * x;
}
int main()
{
	cout << "square()=" << square() << endl;       	
	cout << "square(10)=" << square(10) << endl;    	
	cout << "square(2.5f)=" << square(2.5f) << endl;  	
	cout << "square(1.1)=" << square(1.1) << endl;   
	return 0;
}
/*
当int版本的square函数增加一个默认值x=10，调用该函数将不再需要提供任何实参
而double版本的square函数也可不用任何实参就可调用。这时编译器会报错。
18行，对重载函数的调用不明确。
*/
