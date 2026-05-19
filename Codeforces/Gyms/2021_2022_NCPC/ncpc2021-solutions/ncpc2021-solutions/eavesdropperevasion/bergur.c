#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define per(E, F) for (E = (F) - 1; E >= 0; E--)
void swap(int *a, int *b) { int s = *a; *a = *b; *b = s; }
int max(int a, int b) { return a < b ? b : a; }
int min(int a, int b) { return a < b ? a : b; }
int get_int()
{
	int r = 0, c = getchar(), s = (c == ' ' ? -1 : 1);
	if (c < '0' || c > '9') return get_int();
	for (; c >= '0' && c <= '9'; c = getchar()) r = r*10 + c - '0';
	return s*r;
}

#define DSIZE 110000000
int d[2][DSIZE];
int sss(int *a, int n, int c)
{
	int i, j, k, r, l, mx = 0, s, b, t = 0;
	for (s = 0, b = 0; b < n && s + a[b] <= c; b++) s += a[b];
	rep(i, n) mx = max(mx, a[i]);
	l = c + mx + 1;
	rep(i, l) d[1 - t][i] = i <= c ? 0 : 1;
	d[1 - t][s] = b + 1;
	for (i = b; i < n; i++, t = 1 - t)
	{
		for (j = c - mx + 1; j <= c + mx; j++) d[t][j] = d[1 - t][j];
		for (j = c - mx + 1; j <= c; j++) d[t][j + a[i]] = max(d[t][j + a[i]], d[1 - t][j]);
		for (j = c + a[i]; j >= c + 1; j--) for (k = d[t][j] - 1; k >= d[1 - t][j]; k--) d[t][j - a[k - 1]] = max(d[t][j - a[k - 1]], k);
	}
	rep(i, l) if (d[1 - t][i]) break;
	per(i, c + 1) if (d[1 - t][i]) return i;
}

int prune(int *a, int n, int x)
{
	int i = 0;
	while (i < n) (a[i] > x) ? (swap(&a[i], &(a[n - 1])), n--) : (i++);
	return n;
}

int main()
{
#if 0
	int a[6] = {6, 4, 2, 6, 4, 3};
	printf("sss = %d\n", sss(a, 6, 24));
	return 0;
#else
	int i, j, n = get_int(), x = get_int(), mx = 0, t = 0, s;
	int a[n];
	rep(i, n) mx = max(mx, a[i] = get_int());
	i = 0;
	n = prune(a, n, x);
	if (n == 0)
	{
		printf("%d\n", max(mx, 0));
		return 0;
	}
	if (n == 1 || n == 2)
	{
		printf("%d\n", max(mx, a[0]));
		return 0;
	}
	if (n == 3)
	{
		printf("%d\n", max(mx, x + 1));
		return 0;
	}
	rep(j, 4)
	{
		n--;
		rep(i, n) if (a[i] < a[i + 1]) swap(&a[i], &a[i + 1]);
	}
	rep(i, n) t += (a[i] = x + 1 - a[i]);
	n = prune(a, n, t/2);
	s = sss(a, n, t/2);
	printf("%d\n", max(mx, max(s, t - s) + x + 1));
	return 0;
#endif
}
