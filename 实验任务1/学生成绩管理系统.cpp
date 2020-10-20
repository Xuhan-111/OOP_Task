/*************************************************
** ��Ŀ : Student Information Management System
** ���� : Xushihao
** ���� : 2020-9-22 / 19:37
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
	printf("����: %d ѧ��:", i);
	cout << student[i].xuehao << " ����:" << student[i].name;
	printf(" ƽʱ�ɼ���%d ʵ��ɼ���%d ��ĩ�ɼ���%d �ܳɼ���%.2lf\n", student[i].pingshi, student[i].shiyan, student[i].qimo, student[i].zong);
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
		cout << "δ�ҵ�ѧ��Ϊ " << s << " ��ѧ��" << endl;
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
		cout<<"�����ѧ��Ϊ "<<tmp.xuehao<<" ��ѧ��"<<endl;
	} 
	else
	{
		cout<<"ѧ��Ϊ "<<tmp.xuehao<<" ��ѧ���Ѵ���"<<endl; 
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
		cout << "��ɾ��ѧ��Ϊ " << s << " ��ѧ����Ϣ" << endl;
	}
	else
	{
		cout << "δ�ҵ�ѧ��Ϊ " << s << " ��ѧ����Ϣ�����������Ƿ���ȷ" << endl;
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
	cout << "����ѧ���ɼ�Ϊ:" << endl;
	for (int i = 1; i <= n; ++i)
	{
		output(i);
	}
	cout << "��������1���ѧ��" << endl;
	cout << "��������2��ѯѧ��" << endl;
	cout << "��������3ɾ��ѧ��" << endl;
	cout << "��������4��ӡѧ��ƽ���ɼ��뷽��" << endl;
	cout << "��������5��ӡ����ѧ����Ϣ" << endl;
	cout << "��������0�˳�" << endl;
	int x;
	while (cin >> x)
	{
		if (x == 0)
		{
			break;
		}
		if (x == 1)
		{
			cout << "����������ѧ��ѧ�š�������ƽʱ�ɼ���ʵ��ɼ�����ĩ�ɼ�" << endl;
			insert();
		}
		if (x == 2)
		{
			cout << "������Ҫ��ѯ��ѧ��ѧ��" << endl;
			string ss;
			cin >> ss;
			search(ss);

		}
		if (x == 3)
		{
			cout << "������Ҫɾ����ѧ��ѧ��" << endl;
			string ss;
			cin >> ss;
			del(ss);
		}
		if (x == 4)
		{
			getfc();
			printf("�ð༶ѧ�����ܳɼ���ֵΪ��%.2lf ��׼����Ϊ��%.2lf\n", sum1, sum2);
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
