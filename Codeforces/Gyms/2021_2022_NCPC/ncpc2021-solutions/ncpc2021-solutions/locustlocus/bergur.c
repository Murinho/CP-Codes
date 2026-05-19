#include <stdio.h>
int min(int a, int b) { return a < b ? a : b; }
int get_int()
{
	int r = 0, c = getchar(), s = (c == ' ' ? -1 : 1);
	if (c < '0' || c > '9') return get_int();
	for (; c >= '0' && c <= '9'; c = getchar()) r = r*10 + c - '0';
	return s*r;
}

int gcd(int a, int b)
{
	while (b > 0) { int r = a%b; a = b; b = r; }
	return a;
}

int main()
{
	int q = get_int(), r = 1 << 30;
	while (q--)
	{
		int x = get_int(), y = get_int(), z = get_int();
		r = min(r, x + y*z/gcd(y, z));
	}
	printf("%d\n", r);
	return 0;
}

