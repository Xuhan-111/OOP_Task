#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<string>

using namespace std;
#define  LL long long;
#define endl '\n';
const int N = 1e6;
const int MXAN = 1e5;
const string un = "山东师范大学";

class Graduate
{
private:
	string name;
	bool gender;
	int id;
	double score;
	string research;
	string tutor;
	const string university;
	static int num;
	static double sum;
	static double average;

public:
	Graduate();
	Graduate(string na, bool gen, int idd, double sco, string res, string tu, string uni);
	Graduate(const Graduate& a);
	void out();
	void output() const;
	string getname();
	static const double outaverage();
	friend char getlevel(Graduate);
	~Graduate();

};

Graduate::Graduate() :university(un)
{
	cout << "请输入学生姓名：" << endl;
	cin >> name;
	cout << "请输入学生学号：" << endl;
	cin >> id;
	cout << "请输入学生性别，0为男，1为女" << endl;
	cin >> gender;
	cout << "请输入学生入学成绩" << endl;
	cin >> score;
	cout << "请输入研究领域" << endl;
	cin >> research;
	cout << "请输入指导教师" << endl;
	cin >> tutor;
	sum += score;
	num++;
	average= sum / num;
}

Graduate::Graduate(string na, bool gen, int idd, double sco, string res, string tu, string uni) :university(uni)
{
	name = na;
	gender = gen;
	id = idd;
	score = sco;
	research = res;
	tutor = tu;
	sum += score;
	num++;
	average = sum / num;
}

Graduate::Graduate(const Graduate& a)
{
	name = a.name;
	gender = a.gender;
	id = a.id;
	score = a.score;
	research = a.research;
	tutor = a.tutor;
	sum += score;
	num++;
	average = sum / num;
}

void Graduate::out()
{
	cout << "学生姓名：" << name << endl;
	cout << "学生学号：" << id << endl;
	cout << "学生性别: " << (gender ? "女" : "男") << endl;
	cout << "学生入学成绩: " << score << endl;
	cout << "研究领域: " << research << endl;
	cout << "指导教师: " << tutor << endl;
	cout << "就读学校：" << university << endl;
	cout << endl;
}

void Graduate::output() const
{
	cout << "学生姓名：" << name << endl;
	cout << "学生学号：" << id << endl;
	cout << "学生性别: " << (gender ? "女" : "男") << endl;
	cout << "学生入学成绩: " << score << endl;
	cout << "研究领域: " << research << endl;
	cout << "指导教师: " << tutor << endl;
	cout << "就读学校：" << university << endl;
	cout << endl;
}

string Graduate::getname()
{
	return name;
}

const double Graduate::outaverage()
{
	return average;
}

Graduate::~Graduate()
{
	num--;
	sum -= score;
}

char getlevel(Graduate a)
{
	if (a.score >= 90)
	{
		return 'A';
	}
	else if (a.score >= 80)
	{
		return 'B';
	}
	else if (a.score >= 70)
	{
		return 'C';
	}
	else if (a.score >= 60)
	{
		return 'D';
	}
	else
	{
		return 'E';
	}
}

int Graduate::num = 0;
double Graduate::average = 0;
double Graduate::sum = 0;

int main()
{
	Graduate Stu1("Xiaoming", 1, 20191111, 90.10, "CS", "Zhanglaoshi", un);
	Graduate Stu2("Xiaozhang", 1,20200022, 55.34, "CS", "Liulaoshi", "山财");
	Graduate Stu3;
	cout << "-----------------任务6-----------------------" << endl;
	Stu1.out();
	Stu2.output();
	Stu3.out();
	cout << "平均成绩:" << Graduate::outaverage() << endl;
	cout << "成绩等级" << endl;
	cout << Stu1.getname() << "：" << getlevel(Stu1) << endl;
	cout << Stu2.getname() << "：" << getlevel(Stu2) << endl;
	cout << Stu3.getname() << "：" << getlevel(Stu3) << endl;
	return 0;
}
