#include "_Stack_.h"
#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>

using namespace std;

void work1()
{
	cout << "-----------------作业1-----------------" << endl << endl;
	int n;
	cout << "输入创建栈的大小" << endl;
	cin >> n;
	Stack st = Stack(n);
	int q;
	cout << "对当前栈进行操作" << endl;
	cout << "输入1入栈" << endl;
	cout << "输入2弹栈" << endl;
	cout << "输入3返回栈顶元素" << endl;
	cout << "输入4判空" << endl;
	cout << "输入5判满" << endl;
	cout << "输入6清空栈" << endl;
	cout << "输入0退出" << endl;
	while (1)
	{
		int t;
		cin >> q;
		if (q == 1)//入栈
		{
			if (!st.full())
			{
				cout << "请输入要入栈的元素" << endl;
				cin >> t;
				st.push_back(t);
				cout << t << "已入栈" << endl;
			}
			else
			{
				cout << "栈满，请先弹出部分元素或清空栈" << endl;
			}
		}
		if (q == 2)//出栈
		{
			if (!st.empty())
			{
				cout << "栈顶元素已出栈" << endl;
				st.pop_back();
			}
			else
			{
				cout << "栈空，请先入栈部分元素" << endl;
			}

		}
		if (q == 3)//top
		{
			if (!st.empty())
			{
				cout << "当前栈顶元素为" << st.top() << endl;
			}
			else
			{
				cout << "栈空，请先入栈部分元素" << endl;
			}
		}
		if (q == 4)//空
		{
			if (st.empty())
			{
				cout << "栈空" << endl;
			}
			else
			{
				cout << "栈非空" << endl;
			}
		}
		if (q == 5)//满
		{
			if (st.full())
			{
				cout << "栈满" << endl;
			}
			else
			{
				cout << "栈非满" << endl;
			}
		}
		if (q == 6)
		{
			st.clear();
			cout << "栈已清空" << endl;
		}
		if (q == 0)
		{
			break;
		}
	}
	cout << endl;
	cout << "-----------------作业1-----------------" << endl;
}
