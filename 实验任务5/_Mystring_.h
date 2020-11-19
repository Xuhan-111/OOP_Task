#pragma once
#include "_Mystring_.h"
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include<iostream>
#include <cstdio>

using namespace std;

class MyString
{
private:
	int my_string_len;
public:
	char my_string[1007];
	MyString()
	{
		memset(my_string, '\0', sizeof(my_string));
		my_string_len = 0;
	}
	MyString(const char* b)
	{
		int len = strlen(b);
		for (int i = 0; i < len; ++i)
		{
			my_string[i] = b[i];
		}
		my_string_len = len;
	}
	MyString(const char b)
	{
		my_string_len = 1;
		my_string[0] = b;
	}
	int length() const
	{
		return my_string_len;
	}
	void add(const char* str)
	{
		int len = strlen(str);
		for (int i = 0; i < len; ++i)
		{
			my_string[my_string_len++] = str[i];
		}
	}
	void add(const char str)
	{
		my_string[my_string_len++] = str;
	}
	void add(const MyString& str)
	{
		int len = str.length();
		for (int i = my_string_len, j = 0; j < len; ++j, ++i)
		{
			my_string[i] = str.my_string[j];
		}
		my_string_len += str.my_string_len;
	}
	void posdelete(const int pos)
	{
		for (int i = pos; i < my_string_len - 1; ++i)
		{
			my_string[i] = my_string[i + 1];
		}
		my_string_len--;
	}
	int compare(const MyString& sss)
	{
		int i = 0;
		int len = min(sss.length(), my_string_len);
		while (i < len)
		{
			if (sss.my_string[i] < my_string[i])
			{
				return -1;
			}
			if (sss.my_string[i] > my_string[i])
			{
				return 1;
			}
			++i;
		}
		if (sss.length() < my_string_len)
		{
			return -1;
		}
		if (sss.length() > my_string_len)
		{
			return 1;
		}
		if (sss.length() == my_string_len)
		{
			return 0;
		}
	}
	int find(const MyString& str)
	{
		int len1 = my_string_len;
		int len2 = str.length();
		int i = 0, j = 0;
		while (i < len1 && j < len2)
		{
			if (my_string[i] == str.my_string[j])
			{
				++i;
				++j;
			}
			else
			{
				i = i - j + 1;
				j = 0;
			}
		}
		if (j > len2)
		{
			return i - len2 + 1;
		}
		return -1;

	}
	bool find(const char b)
	{
		for (int i = 0; i < my_string_len; ++i)
		{
			if (my_string[i] == b)
			{
				return 1;
			}
			return 0;
		}
	}
	void change(int pos, char b)
	{
		my_string[pos] = b;
	}
	void reverse()
	{
		for (int i = 0; i < my_string_len / 2; ++i)
		{
			char t = my_string[i];
			my_string[i] = my_string[my_string_len - i - 1];
			my_string[my_string_len - i - 1] = t;
		}
	}
	friend ostream& operator<<(ostream&, MyString&);//重载输出运算符
};

void work2();
