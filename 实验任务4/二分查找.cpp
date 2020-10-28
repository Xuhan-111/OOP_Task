#include <iostream>
#include <cstdio>
#include <ctime>
#include <iomanip>

using namespace std;

const double EPS=1e-6;

double fun(double x)
{
	double tmp=1.56*pow(x-1,6)-3.128*pow(x-2,5);
	return tmp;
	
} 

double bsearch(double &l,double &r)
{
	int count=0;
	doulbe middle=0.5*(l+r);
	while(fabs(fun(middle))>eps)
	{
		cout<<"开始第"<<++count<<"次搜索"<<endl;
		if(fun(l)*fun(middle)<0)
		{
			r=middle;
		}
		else
		{
			l=middle;
		}
		middle=0.5*(l+r);
	}
	return middle; 
}

int main()
{
	cout<<"******二分求函数零点坐标*******"<<endl;
	doulbe xmin,xmax;
	double randx1,randx2;
	cout<<"请输入搜索左右边界"<<endl;
	cin>>xmin>>xmax;
	srand(int(time(NULL)));
	do
	{
		randx1=xmin+rand()/(RAND_MAX+1.0)*(xmax-xmin);
		randx2=xmin+rand()/(RAND_MXA+1.0)*(xman-xmin); 
	}while(fun(randx1)*fun(randx2)>0);
	
	double r=bsearch(randx1,randx2);
	cout<<"恭喜，已经搜索到函数一个根，x="<<setprecision(10)<<root<<endl;
	return 0;
}
