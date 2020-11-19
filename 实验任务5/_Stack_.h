#pragma once
#include "_Stack_.h"
#include<string>
#include<cstring>

class Stack
{
private:
	int st[1007];
	int tt;
	int maxx;
public:
	Stack(int n)
	{
		memset(st, 0, sizeof(st));
		maxx = n;
		tt = -1;
	}
	void push_back(int x)
	{
		tt++;
		st[tt] = x;
	}
	int top()
	{
		return st[tt];
	}
	void pop_back()
	{
		st[tt] = 0;
		tt--;
	}
	bool empty()
	{
		if (tt == -1)
		{
			return 1;
		}
		return 0;
	}
	bool full()
	{
		if (tt == maxx)
		{
			return 1;
		}
		return 0;
	}
	void clear()
	{
		memset(st, 0, sizeof(st));
		tt = -1;
	}
};

void work1();
