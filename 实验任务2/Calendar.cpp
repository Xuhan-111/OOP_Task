#include "_Calendar_.h"
#include <cmath>
#include <iostream>


int mon[20] = { 0, 31, 59 ,90, 120, 151, 181, 212, 243, 273, 304, 334, 365,0 };

void rili(int nian, int yue, int ri)
{
	bool frun = 0;
	int ans = 0;
	int zhou = 0;
	if (nian % 400 == 0)//�ж�����1�����Ա�400���������
	{
		frun = 1;
	}
	else if (nian % 4 == 0 && nian % 100 != 0)//�ж�����2�����Ա�4���������ܱ�100���������
	{
		frun = 1;
	}
	if (yue > 2 && frun)//������2��֮��+1
	{
		ans += 1;
	}
	yue -= 1;
	ans += mon[yue];
	ans += ri;
	if (ans % 7 == 0)//�ж���
	{
		zhou = ans / 7;
	}
	else
	{
		zhou = ceil(ans / 7.0) + 1;
	}
	std::cout << nian << "��" << yue << "��" << ri << "���Ǹ���ĵ� " << ans << " ���ڸ���ĵ�" << zhou << "��" << std::endl;
}