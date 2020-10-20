#include "_Calendar_.h"
#include <cmath>
#include <iostream>


int mon[20] = { 0, 31, 59 ,90, 120, 151, 181, 212, 243, 273, 304, 334, 365,0 };

void rili(int nian, int yue, int ri)
{
	bool frun = 0;
	int ans = 0;
	int zhou = 0;
	if (nian % 400 == 0)//判断闰年1，可以被400整除的年份
	{
		frun = 1;
	}
	else if (nian % 4 == 0 && nian % 100 != 0)//判断闰年2，可以被4整除但不能被100整除的年份
	{
		frun = 1;
	}
	if (yue > 2 && frun)//闰年且2月之后，+1
	{
		ans += 1;
	}
	yue -= 1;
	ans += mon[yue];
	ans += ri;
	if (ans % 7 == 0)//判断周
	{
		zhou = ans / 7;
	}
	else
	{
		zhou = ceil(ans / 7.0) + 1;
	}
	std::cout << nian << "年" << yue << "月" << ri << "日是该年的第 " << ans << " 天在该年的第" << zhou << "周" << std::endl;
}