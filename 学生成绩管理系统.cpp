/*************************************************
** 题目 : Student Information Management System
** 作者 : Xushihao
** 创建 : 2020-9-22 / 19:37
/**************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;
typedef  long long LL;
const int N = 1e6;

struct node
{
	string name;
	string xuehao;
	int qimo;
	int pingshi;
	int shiyan;
	double zong;
};
node student[N];
int n; 
double sum = 0, sum1 = 0, sum2 = 0;
ifstream input("data.txt");
bool cmp(node a, node b)
{
	return a.zong > b.zong;
}
void in(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		input >> student[i].xuehao >> student[i].name >> student[i].pingshi >> student[i].shiyan >> student[i].qimo;
		student[i].zong = 0.2 * student[i].pingshi + 0.2 * student[i].shiyan + 0.6 * student[i].qimo;
		sum += student[i].zong;
	}
}
void output(int i)
{
	printf("排名: %d 学号:", i);
	cout << student[i].xuehao << " 姓名:" << student[i].name;
	printf(" 平时成绩：%d 实验成绩：%d 期末成绩：%d 总成绩：%.2lf\n", student[i].pingshi, student[i].shiyan, student[i].qimo, student[i].zong);
}
void getfc()
{
	sum1 = sum / n;
	for (int i = 1; i <= n; ++i)
	{
		double x = student[i].zong - sum1;
		sum2 += x * x;
	}
	sum2 /= n;
	sum2 = sqrt(sum2);
}
void search(string s)
{
	bool f = 0;
	int i;
	for (i = 1; i <= n; ++i)
	{
		if (student[i].xuehao == s)
		{
			f = 1;
			break;
		}
	}
	if (f)
		output(i);
	else
		cout << "未找到学号为 " << s << " 的学生" << endl;
}
void paixu()
{
	sort(student + 1, student + 1 + n, cmp);
}
void insert()
{
	node tmp;
	bool f=1;
	cin >> tmp.xuehao >> tmp.name >> tmp.pingshi >> tmp.shiyan >> tmp.qimo;
	tmp.zong = 0.2 * tmp.pingshi + 0.2 * tmp.shiyan + 0.6 * tmp.qimo;
	for(int i=1;i<=n;++i)
	{
		if(student[i].xuehao==tmp.xuehao)
		{
			f=0;
			break;
		}
	}
	if(f)
	{
		n++;
		student[n]=tmp;
		sum += student[n].zong;
		paixu();
		getfc();
		cout<<"已添加学号为 "<<tmp.xuehao<<" 的学生"<<endl;
	} 
	else
	{
		cout<<"学号为 "<<tmp.xuehao<<" 的学生已存在"<<endl; 
	}
}
void del(string s)
{
	int i;
	bool f = 0;
	for (i = 1; i <= n; ++i)
	{
		if (student[i].xuehao == s)
		{
			f = 1;
			break;
		}
	}
	if (f)
	{
		sum-=student[i].zong;
		for (; i < n; ++i)
		{
			student[i] = student[i + 1];
		}
		n--;
		paixu();
		getfc();
		cout << "已删除学号为 " << s << " 的学生信息" << endl;
	}
	else
	{
		cout << "未找到学号为 " << s << " 的学生信息，请检查输入是否正确" << endl;
	}

}
int main()
{
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(0);
	input >> n;
	in(n);
	getfc();
	paixu();
	cout << "现有学生成绩为:" << endl;
	for (int i = 1; i <= n; ++i)
	{
		output(i);
	}
	cout << "输入数字1添加学生" << endl;
	cout << "输入数字2查询学生" << endl;
	cout << "输入数字3删除学生" << endl;
	cout << "输入数字4打印学生平均成绩与方差" << endl;
	cout << "输入数字5打印所有学生信息" << endl;
	cout << "输入数字0退出" << endl;
	int x;
	while (cin >> x)
	{
		if (x == 0)
		{
			break;
		}
		if (x == 1)
		{
			cout << "请依次输入学生学号、姓名、平时成绩、实验成绩、期末成绩" << endl;
			insert();
		}
		if (x == 2)
		{
			cout << "请输入要查询的学生学号" << endl;
			string ss;
			cin >> ss;
			search(ss);

		}
		if (x == 3)
		{
			cout << "请输入要删除的学生学号" << endl;
			string ss;
			cin >> ss;
			del(ss);
		}
		if (x == 4)
		{
			getfc();
			printf("该班级学生的总成绩均值为：%.2lf 标准方差为：%.2lf\n", sum1, sum2);
		}
		if (x == 5)
		{
			for (int i = 1; i <= n; ++i)
			{
				output(i);
			}
		}
	}
	return 0;
}
