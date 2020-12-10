#include<iostream>

using namespace std;

class Base
{
private:
	int x;
public:
	Base(int i=0)
	{
		x = i;
		cout << "constructing Base\n";
	}
	void show()
	{
		cout << "x = " << x << endl;
	}
};

class Derived :public Base
{
private:
	Base d;
public:
	Derived(int i) :d(i)
//	Derived(int i) :Base(i), d(i)
	{
		Base(i);
		cout << "constructing Derived\n";
	}
};

int main()
{
	Derived obj(100);
	obj.show();
	return 0;
}
