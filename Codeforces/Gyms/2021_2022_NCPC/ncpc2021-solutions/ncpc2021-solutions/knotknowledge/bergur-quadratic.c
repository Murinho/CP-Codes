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

int cmp(const void* p1, const void* p2) { return *(int*)p1 - *(int*)p2; }

int main()
{
	int i, j, n = get_int();
	int a[n], b[n - 1];
	rep(i, n) a[i] = get_int();
	rep(i, n - 1) b[i] = get_int();
	rep(i, n - 1) rep(j, n) if (b[i] == a[j]) { a[j] = -1; break; }
	rep(i, n) if (a[i] != -1) break;
	printf("%d\n", a[i]);
}

