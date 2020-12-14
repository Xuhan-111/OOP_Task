#include <iostream>
using namespace std;

class Base
{
private:
	int b;
public:
	Base(int x) :b(x)
	{

	}
	int getb()
	{
		return b;
	}

};

class Derived :public Base
{
private:
	int d;
public:
	Derived(int x, int y) :Base(x), d(y)
	{

	}
	int getd()
	{
		return d;
	}
};

int main()
{
	Base b1(11);
	Derived d1(22, 33);
	Base* pb1 = &d1;
	cout << "pb1->getd() = " << ((Derived*)pb1)->getd() << endl;
	Derived* pd = &d1;
	Derived* pb2 = pd;
	cout << "pb2->getd() = " << ((Derived*)pb2)->getd() << endl;
	Base& rb = d1;
	cout << "rb.getd() = " << ((Derived&)rb).getd() << endl;
	return 0;
}

