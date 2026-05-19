#include <stdio.h>
#include <math.h>

int get_int()
{
	int r = 0, c = getchar(), s = (c == ' ' ? -1 : 1);
	if (c < '0' || c > '9') return get_int();
	for (; c >= '0' && c <= '9'; c = getchar()) r = r*10 + c - '0';
	return s*r;
}

int main()
{
	int x1 = get_int(), y1 = get_int(), z1 = get_int(), w1 = get_int();
	int x2 = get_int(), y2 = get_int(), z2 = get_int(), w2 = get_int();
	printf("%.8f\n", fmax(hypot(x1 - z1, y1 - w1), hypot(x2 - z2, y2 - w2)));
	return 0;
}
