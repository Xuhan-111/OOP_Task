#include <iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>

using namespace std;

class base
{
public:
	int a;
	base(int aa,int bb,int cc);
	~base();
	void print();
	static int statistic()
	{
		return count;
	}

protected:
	int b;
private:
	int c;
	static int count;

};

base::base(int aa,int bb,int cc)
{
	a = aa;
	b = bb;
	c = cc;
	count++;
	cout << "base 构造函数被调用,当前count=" << count << endl;
}

base::~base()
{
	count--;
	cout << "base 析构函数被调用" << endl;
}

void base::print()
{
	cout << "base: a=" << a << " b=" << b << " c=" << c << endl;
}
int base::count = 0;

class derived1 :public base
{
public:
	derived1(int aa, int bb, int cc) :base(aa, bb, cc)
	{
		cout << "derived1 构造函数被调用" << endl;
	}
	void show()
	{
		cout << "derived1: a=" << a << " b=" << b << " c 不可访问" << endl;
		base::print();
	}
	~derived1()
	{
		cout << "derived1 析构函数被调用" << endl;
	}
};

class derived2 :protected base
{
public:
	derived2(int aa, int bb, int cc) :base(aa, bb, cc)
	{
		cout << "derived2 构造函数被调用" << endl;
	}
	void show()
	{
		cout << "derived2: a=" << a << " b=" << b << " c 不可访问" << endl;
		base::print();
	}
	~derived2()
	{
		cout << "derived2 析构函数被调用" << endl;
	}
};

class derived3 :private base
{
public:
	derived3(int aa, int bb, int cc) :base(aa, bb, cc)
	{
		cout << "derived3 构造函数被调用" << endl;
	}
	void show()
	{
		cout << "derived2: a=" << a << " b=" << b << " c 不可访问" << endl;
		base::print();
	}
	~derived3()
	{
		cout << "derived3 析构函数被调用" << endl;
	}
};

class grandderived1 :protected derived2
{
public:
	grandderived1(int aa, int bb, int cc) :derived2(aa, bb, cc)
	{
		cout << "grandderived1 构造函数被调用" << endl;
	}
	void show()
	{
		cout << "grandderived1 a=" << a << " b=" << b << " c 不可访问" << endl;
		derived2::show();
	}
	~grandderived1()
	{
		cout << "grandderived1 析构函数被调用" << endl;
	}
};

class grandderived2 :private derived3
{
public:
	grandderived2(int aa, int bb, int cc) :derived3(aa, bb, cc)
	{
		cout << "grandderived1 构造函数被调用" << endl;
	}
	void show()
	{
		cout << "grandderived2 a 不可访问" << " b 不可访问" << "c 不可访问" << endl;
		derived3::show();
	}
	~grandderived2()
	{
		cout << "grandderived1 析构函数被调用" << endl;
	}
};

class Location
{
public:
	int x;
	int y;
	Location(int X=0,int Y=0)
	{
		x = X;
		y = Y;
	}
	void move(int xx, int yy)
	{
		x = xx;
		y = yy;
	}
	void show()
	{
		cout << "x=" << x << " y=" << y;
	}
	~Location(){ }

};
class Point :public Location
{
public:
	int z;
	Point(int X = 0, int Y = 0, int Z = 0) :Location(X, Y)
	{
		z = Z;
	}
	void move(int xx, int yy, int zz)
	{
		z = zz;
		Location::move(xx, yy);
	}
	void show()
	{
		Location::show();
		cout << " z=" << z << endl;
	}
	~Point() { }
};

class Sphere :public Point
{
public:
	int r;
	Sphere(int R = 0, int X = 0, int Y = 0, int Z = 0) :Point(X, Y, Z)
	{
		r = R;
	}
	Sphere(const Point& pp, int R = 0) :Point(pp.x, pp.y, pp.z)
	{
		r = R;
	}
	void move(int xx, int yy, int zz)
	{
		Point::move(xx, yy, zz);
	}
	void change(int rr)
	{
		r = rr;
	}
	void show()
	{
		cout << "半径=" << r << " 圆心：";
		Point::show();
	}
};

void task1()
{
	base b(1, 2, 3);
	cout << "创建基类base b" << endl;
	b.print();
	cout << "sizeof(b)=" << sizeof(b) << endl;
	cout << endl;
	derived1 d1(1, 2, 3);
	cout << "创建public 子类d1" << endl;
	d1.show();
	cout << "sizeof(d1)=" << sizeof(d1) << endl;
	cout << endl;
	derived2 d2(1, 2, 3);
	cout << "创建protected子类d2" << endl;
	d2.show();
	cout << "sizeof(d2)=" << sizeof(d2) << endl;
	cout << endl;
	derived3 d3(1, 2, 3);
	cout << "创建private子类d3" << endl;
	d3.show();
	cout << "sizeof(d3)=" << sizeof(d3) << endl;
	cout << endl;
	grandderived1 g1(1, 2, 3);
	cout << "创建protected 孙子类g1" << endl;
	g1.show();
	cout << "sizeof(g1)=" << sizeof(g1) << endl;
	cout << endl;
	grandderived2 g2(1, 2, 3);
	cout << "创建private 孙子类g2" << endl;
	g2.show();
	cout << "sizeof(g2)=" << sizeof(g2) << endl;
	cout << endl;
	cout << "结束" << endl;
	
}

void task2()
{
	Location L(3, 4);
	cout << "创建Location类 L" << endl;
	L.show();
	cout << endl;
	cout << "L 移动到(5,6)" << endl;
	L.move(5, 6);
	L.show();
	cout << endl;
	cout << endl;
	Point p(3, 4, 5);
	cout << "创建Point类 p" << endl;
	p.show();
	cout << "p 移动到(5,6,7)" << endl;
	p.move(5, 6, 7);
	p.show();
	cout << endl;
	Sphere S(p, 7);
	cout << "创建Sphere类 S，使用Point类p" << endl;
	S.show();
	cout << "S 移动到(8,9,10)" << endl;
	S.move(8, 9, 10);
	S.show();
}
int main()
{
	cout << "-------------------------任务1-------------------------" << endl << endl;
	task1();
	cout << endl<<"-------------------------任务1-------------------------" <<endl;
	cout << "-------------------------任务2-------------------------" << endl << endl;
	task2();
	cout << endl << "-------------------------任务2-------------------------" << endl;
	return 0;
}
