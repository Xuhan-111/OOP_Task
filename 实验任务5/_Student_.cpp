#include"_Student_.h"
#include<iostream>
#include<cstdio>
#include<string>


using namespace std;

typedef long long LL;

void work4()
{
	cout << "-----------------作业4-----------------" << endl;
	cout << endl;
	string na;
	bool gen;
	LL id;
	int y;
	int m;
	int d;
	string add;
	int sc[7];
	cout << "创建一个学生类" << endl;
	cout << "输入姓名:";
	cin >> na;
	cout << "输入性别（1为男，0为女):";
	cin >> gen;
	cout << "输入学号:";
	cin >> id;
	cout << "输入生日（按年月日排列，空格分隔）";
	cin >> y >> m >> d;
	cout << "输入家庭住址:";
	cin >> add;
	cout << "输入六科成绩，空格分隔:";
	for (int i = 1; i <= 6; ++i)
	{
		cin >> sc[i];
	}
	Student stu(na, gen, id, y, m, d, add, sc);
	cout << "该学生信息创建完成" << endl;
	int n;
	stu.getall();
	cout << "输入1询问学生姓名" << endl;
	cout << "输入2询问学生性别" << endl;
	cout << "输入3询问学生学号" << endl;
	cout << "输入4询问学生生日" << endl;
	cout << "输入5询问学生住址" << endl;
	cout << "输入6询问学生成绩" << endl;
	cout << "输入0退出" << endl;
	cout << "请输入一个数字" << endl;
	while (cin >> n)
	{
		if (n == 1)
		{
			cout << stu.getname() << endl;
		}
		else if (n == 2)
		{
			cout << (stu.getgender() == 1 ? "男" : "女") << endl;
		}
		else if (n == 3)
		{
			cout << stu.getid() << endl;
		}
		else if (n == 4)
		{
			stu.getbirthday();
			cout << endl;
		}
		else if (n == 5)
		{
			cout << stu.getadd() << endl;
		}
		else if (n == 6)
		{
			int x;
			cin >> x;
			stu.getscore();
		}
		else if (n == 0)
		{
			break;
		}
		else
		{
			cout << "非法输入" << endl;
		}
		cout << "请输入一个数字:";
	}
	cout << endl;
	cout << "-----------------作业4-----------------" << endl;
}
