#include<iostream>

using namespace std;

class A
{
public:
	A(int a = 0)
	{
		x = a;
		cout << "A: x = " << a << endl;
	}
private:
	int x;
};

class B
{
public:
	B(int a, int b, int c)//: a2(b),a1(a)
	{
		a1.x = a;//A类中的x为私有成员，无法在类外访问，该处编译无法通过
		a2.x = b;
		y = c;
		cout << "B: y = " << c << endl;
	}
private:
	A a1, a2;
	int y;
};

int main()
{
	B obj(10, 20, 30);
	return 0;
}
