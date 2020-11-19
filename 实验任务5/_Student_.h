#pragma once
#include "_Student_.h"
#include <cstring>
#include <string>
#include<iostream>

using namespace std;
typedef long long LL;
class Student
{
private:
	string name;
	bool gender;
	LL stuid;
	int birthday_y;
	int birthday_m;
	int birthday_d;
	string address;
	int score[7];
public:
	Student() { }
	Student(string na, bool sex, LL ide, int ye, int mo, int da, string add, int* s1)
	{
		name = na;
		gender = sex;
		stuid = ide;
		birthday_y = ye;
		birthday_m = mo;
		birthday_d = da;
		address = add;
		score[1] = s1[1];
		score[2] = s1[2];
		score[3] = s1[3];
		score[4] = s1[4];
		score[5] = s1[5];
		score[6] = s1[6];
	}
	Student(const Student& stu)
	{
		name = stu.name;
		gender = stu.gender;
		stuid = stu.stuid;
		birthday_y = stu.birthday_y;
		birthday_m = stu.birthday_m;
		birthday_d = stu.birthday_d;
		address = stu.address;
		for (int i = 1; i <= 6; i++)
		{
			score[i] = stu.score[i];
		}
	}
	void changescore(int pos, int x)
	{
		score[pos] = x;
	}
	string getname()
	{
		return name;
	}
	LL getid()
	{
		return stuid;
	}
	string getadd()
	{
		return address;
	}
	bool getgender()
	{
		return gender;
	}
	void getbirthday()
	{
		cout << "出生日期:" << birthday_y << "-" << birthday_m << "-" << birthday_d;
	}
	void getscore()
	{
		cout << "六科成绩:";
		for (int i = 1; i <= 6; i++)
		{
			cout << score[i] << (i == 6 ? '\n' : ' ');
		}
	}
	void getall()
	{
		cout << "姓名:" << name << " 学号:" << stuid << " 性别:" << (gender == 0 ? "女 " : "男 ");
		getbirthday();
		cout << " 家庭住址:" << getadd() << " ";
		getscore();
	}
	~Student() { }
};

void work4();
