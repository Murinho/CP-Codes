// thetta er ekki nogu nakvaemt!!!!!!
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <assert.h>
#define rep(E, F) for (E = 0; E < (F); E++)
int min(int a, int b) { if (a > b) return b; return a; }
int max(int a, int b) { if (a < b) return b; return a; }
double get_double();
int get_int()
{
	int r = 0, c = getchar(), s = (c == ' ' ? -1 : 1);
	if (c < '0' || c > '9') return get_int();
	for (; c >= '0' && c <= '9'; c = getchar()) r = r*10 + c - '0';
	return s*r;
}

int gauss(long double* a, int n)
{
	int i, j, k, t, r = 0;
	rep(i, n)
	{
		t = -1;
		while (++t < n && fabs(a[i*(n + 1) + t]) < 1e-9);
		if (t == n) continue;
		r++;
		for (j = n; j >= t; j--) a[i*(n + 1) + j] = a[i*(n + 1) + j]/a[i*(n + 1) + t];
		rep(j, n) if (i != j) for (k = n; k >= t; k--) a[j*(n + 1) + k] = a[j*(n + 1) + k] - a[i*(n + 1) + k]*a[j*(n + 1) + t];
	}
	return r;
}

int popcnt(int a)
{
	return a == 0 ? 0 : (a%2 + popcnt(a/2));
}

int main()
{
	int i, j, n = get_int(), k = get_int();
	double p = get_double();
	int m = 1 << n;
	long double a[m][m];
	long double e[m][m + 1];
	rep(i, m) rep(j, m) a[i][j] = 0.0;
	rep(i, m) rep(j, m + 1) e[i][j] = (i == j || j == m) ? 1.0 : 0.0;
	rep(i, m)
	{
		if (popcnt(i) == k) a[i][i] = 1.0;
		else
		{
			a[i][((m - 1)&(i << 1))] = 1.0 - p;
			a[i][((m - 1)&(i << 1)) + 1] = p;
		}
	}
	rep(i, m) rep(j, m) e[i][j] -= a[i][j];
	rep(i, m) if (popcnt(i) >= k) e[i][m] = 0.0, e[i][i] = 1.0;
	gauss(*e, m);
	printf("%.8f\n", (double)(e[0][m]));
	return 0;
}

double get_double()
{
	double ret = 0;
	char c = getchar();
	int sgn;

	while (1)
	{
		if (c == EOF) return EOF;
		if (c >= '0' && c <= '9') { sgn = 1; break; }
		if (c == '-')
		{
			c = getchar();
			if (c < '0' || c > '9') continue;
			sgn = -1;
			break;
		}
		c = getchar();
	}

	while (1)
	{
		ret = ret*10 + c - '0';
		c = getchar();
		if (c == '.')
		{
			double pos = 0.1;
			c = getchar();
			while (c >= '0' && c <= '9')
			{
				ret += pos*(c - '0');
				pos /= 10;
				c = getchar();
			}
			return sgn*ret;
		}
		else if (c < '0' || c > '9') return sgn*ret;
	}
}
