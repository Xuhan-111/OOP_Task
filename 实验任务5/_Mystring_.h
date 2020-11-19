#include "_Mystring_.h"
#include<iostream>
#include <cstdio>
#include<algorithm>

using namespace std;

const int N = 1007;

ostream& operator<<(ostream& out, MyString& b)
{
	int i;
	for (i = 0; i < b.my_string_len; ++i)
	{
		cout.width(1);
		cout << b.my_string[i];
	}
	return out;
}

void work2()
{
	cout << "-----------------作业2-----------------" << endl << endl;
	char s1[N];
	char s2[N];
	cout << "输入字符串a" << endl;
	cin >> s1;
	cout << "输入字符串b" << endl;
	cin >> s2;
	MyString a(s1);
	MyString b(s2);
	cout << "字符串 " << a << " 的长度是" << b.length() << endl;
	cout << "字符串 " << b << " 的长度是" << b.length() << endl;
	MyString c('c');
	cout << "字符串 " << c << " 的长度是" << c.length() << endl;
	a.add(b);
	cout << "a,b两串相加:" << a << "长度为" << a.length() << endl;
	c.add('c');
	cout << "c串加'c' " << c << endl;
	a.posdelete(0);
	cout << "删除a串的第一个字符后:" << a << endl;
	a.change(0, 'c');
	cout << "将a串的第一个字符改为c:" << a << endl;
	int fl = a.compare(b);
	if (fl > 0)
	{
		cout << "a串的字典序大于b" << endl;
	}
	else if (fl == 0)
	{
		cout << "a串的字典序等于b" << endl;
	}
	else
	{
		cout << "a串的字典序小于b" << endl;
	}
	a.reverse();
	cout << "反转a串";
	cout << a << endl;
	int f = a.find(b);
	if (f != -1)
	{
		cout << "a串与b串在" << f << "字符处匹配" << endl;
	}
	else
	{
		cout << "b串不是a串的一个子串" << endl;
	}
	cout << endl;
	cout << "-----------------作业2-----------------" << endl;
}

