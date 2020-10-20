#include "_Triangle_.h"
#include <cmath>

int Triangle_Area(const double* a, const double* b, const double* c, double& ans)
{
	if (*a + *b > * c && *b + *c > * a && *a + *c > * b && *a - *b < *c && *a - *c < *b && *c - *b < *a)
	{
		double p = *a + *b + *c;
		p /= 2;
		double S = sqrt(p * (p - *a) * (p - *b) * (p - *c));
		ans = S;
		return 1;
	}
	return 0;
}

