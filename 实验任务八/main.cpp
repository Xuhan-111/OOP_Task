#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<set>
#include<queue>

using namespace std;
typedef long long LL;
#define  endl '\n';
const int N = 1007;

class Array
{
private:
	int size;
	int* p;
public:
	Array()
	{
		size = 0;
		p = NULL;
	}
	Array(int s, int* a)
	{
		size = s;
		p = new int[size + 7];
		for (int i = 0; i <= s; ++i)
		{
			p[i] = a[i];
		}
	}
	Array(int s, int x)
	{
		size = s;
		p = new int[size + 7];
		for (int i = 0; i < s; ++i)
		{
			p[i] = x;
		}
	}
	Array(const Array& aa)
	{
		size = aa.size;
		p = new int[size];
		for (int i = 0; i < size; ++i)
		{
			p[i] = aa.p[i];
		}
	}
	~Array()
	{
		delete[] p;
	}
	int length()
	{
		return size;
	}
	int& operator[](const int pp)
	{
		return p[pp];
	}
	Array& operator =(const Array& aa)
	{
		if (&aa == this)
		{
			return *this;
		}
		if (p != NULL)
		{
			delete[] p;
		}
		size = aa.size;
		if (size > 0)
		{
			this->p = new int[size + 7];
		}
		for (int i = 0; i < size; ++i)
		{
			this->p[i] = aa.p[i];
		}
		return (*this);
	}
	Array operator+ (const Array& aa)
	{
		Array tmp;
		tmp.size = size + aa.size;
		if (tmp.size > 0)
		{
			tmp.p = new int[tmp.size + 7];
		}
		int ii = 0;
		for (int i = 0; i < size; ++i)
		{
			tmp.p[ii++] = p[i];
		}
		for (int i = 0; i < aa.size; ++i)
		{
			tmp.p[ii++] = aa.p[i];
		}
		return tmp;
	}
	friend Array operator -(Array& a1, Array& a2);
};

Array operator - (Array& a1, Array& a2)
{
	Array tmp;
	tmp.p = new int[a1.size + 7];
	int ii = 0;
	set<int>s;
	queue<int>q;
	for (int i = 0; i < a1.size; ++i)
	{
		q.push(a1.p[i]);
	}
	for (int i = 0; i < a2.size; ++i)
	{
		s.insert(a2.p[i]);
	}
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		if (!s.count(now))
		{
			tmp.p[ii++] = now;
		}
	}
	tmp.size = ii;
	while (ii < a1.size)
	{
		tmp.p[ii++] = 0;
	}
	return tmp;
}

class Shapes
{
public:
	virtual void display() = 0;

};

class Rectangle :public Shapes
{
public:
	void display()
	{
		cout << "矩形" << endl;
	}
};

class Cricle :public Shapes
{
public:
	void display()
	{
		cout << "圆形" << endl;
	}
};

void task2()
{
	cout << "-----------------------任务二------------------" << endl;

	int a[] = {1,2,3,4,5,6};
	int b[] = { 2,3,4,5,6,7 };
	Array a1(6, a);
	Array a2(6, b);
	cout << endl;
	cout<<"[]的重载" << endl;
	for (int i = 0; i < a1.length(); ++i)
	{
		cout << a1[i] << (i == a1.length() - 1 ? '\n' : ' ');
	}
	cout << endl;
	cout << "+的重载" << endl;
	a1 = a2 + a1;
	for (int i = 0; i < a1.length(); ++i)
	{
		cout << a1[i] << (i == a1.length() - 1 ? '\n' : ' ');
	}
	cout << endl;
	cout << "- 的重载" << endl;
	Array a3 = a1 - a2;
	for (int i = 0; i < a3.length(); ++i)
	{
		cout << a3[i] << (i == a3.length() - 1 ? '\n' : ' ');
	}
	cout << "-----------------------任务二------------------" << endl;
	cout << endl;
}

void task3()
{
	cout << "-----------------------任务三------------------" << endl;
	Shapes* p[3];
	Rectangle r;
	Cricle c;
	p[1] = &r;
	p[2] = &c;
	p[1]->display();
	p[2]->display(); 
	cout << "-----------------------任务三------------------" << endl;
}

int main()
{
	task2();
	task3();
	return 0;
}
