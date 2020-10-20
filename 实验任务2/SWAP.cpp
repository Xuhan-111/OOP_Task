#include "_SWAP_.h"

void SWAP(int& x, int& y)
{
	int t = x;
	x = y;
	y = t;
}
void SWAP(double& x, double& y)
{
	double t = x;
	x = y;
	y = t;
}