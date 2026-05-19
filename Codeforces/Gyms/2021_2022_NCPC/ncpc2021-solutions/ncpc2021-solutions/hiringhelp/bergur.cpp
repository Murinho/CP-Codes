#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-16
#define rep(E, F) for (E = 0; E < (F); E++)
#define per(E, F) for (E = (F) - 1; E >= 0; E--)
#define I pt(0, 1)
int min(int a, int b) { if (a > b) return b; return a; }
int max(int a, int b) { if (a < b) return b; return a; }
typedef complex<double> pt;
typedef struct { int t, q, x, y, r; } query;
typedef pair<double, double> ii;
int get_int();

bool cmp(const pt a, const pt b)
{
	return ii(abs(a) < 1e-9 ? 0.0 : arg(a), abs(a)) < ii(abs(b) < 1e-9 ? 0.0 : arg(b), abs(b));
}

typedef set<pt, decltype(cmp)*> hull;

int ccw(pt a, pt b, pt c)
{
	if (abs(a - b) < EPS || fabsl(imag((c - a)/(b - a))) < EPS) return 0;
	return imag((c - a)/(b - a)) > 0.0 ? 1 : -1;
}

pt piv;
int cmp(const void* p1, const void* p2)
{
	pt a = *(pt*)p1, b = *(pt*)p2;
	if (fabsl(arg(a - piv) - arg(b - piv)) > EPS)
		return arg(a - piv) < arg(b - piv) ? -1 : 1;
	if (fabsl(abs(a - piv) - abs(b - piv)) < EPS) return 0;
		return abs(a - piv) < abs(b - piv) ? -1 : 1;
}

int convex_hull(pt* p, pt* h, int n)
{
	if (n == 0) return 0;
	int j = 0, i, mn = 0;
	for (i = 1; i < n; i++)
		if (imag(p[i]) < imag(p[mn]) || imag(p[i]) == imag(p[mn])
				&& real(p[i]) < real(p[mn])) mn = i;
	pt t = p[mn]; p[mn] = p[0]; p[0] = t;
	piv = p[0]; 
	qsort(p + 1, n - 1, sizeof(p[1]), cmp);

	for (i = 1; i < n && abs(p[0] - p[i]) < EPS; i++);
	if (i == n) h[j++] = p[0];
	else if (i == n - 1) h[j++] = p[0], h[j++] = p[n - 1];
	if (i >= n - 1) return j;
	h[j++] = p[n - 1], h[j++] = p[0], h[j++] = p[i];
	if (ccw(h[0], h[1], h[2]) == 0)
		return j - (abs(h[0] - h[1]) < EPS ? 2 : 1);
	for (i++; i < n;)
		(abs(h[j - 1] - p[i]) > EPS && ccw(h[j - 2], h[j - 1], p[i]) == 1)
			? (h[j++] = p[i++]) : j--;
	return --j;
}

int on_segment(pt a, pt b, pt p)
{ // is |p| on the segment |<a, b>|?
	if (fabsl(real(a) - real(b)) < EPS) return on_segment(a*I, b*I, p*I);
	if (ccw(a, b, p) != 0) return 0;
	if (real(p) + EPS < min(real(a), real(b))) return 0;
	if (real(p) - EPS > max(real(a), real(b))) return 0;
	return 1;
}

int is_in_hull(hull& h, pt p)
{
	auto it = h.lower_bound(p);
	if (h.size() < 3) return 0;
	if (real(p) < EPS) return imag(p) - EPS < imag(*h.rbegin());
	if (imag(p) < EPS) return real(p) - EPS < real(*next(h.begin()));
	return ccw(*prev(it), *it, p) != -1;
}

void add_to_hull(hull& h, pt p)
{
	if (h.size() < 3)
	{
		h.insert(p);
		return;
	}
	if (is_in_hull(h, p)) return;

	auto it = h.insert(p).first;
	while (ccw(*prev(prev(it)), *prev(it), *it) != 1) h.erase(prev(it));
	while (next(next(it)) != h.end() && ccw(*it, *next(it), *next(next(it))) != 1) h.erase(next(it));
}

#define MAXN 200000
pt a[MAXN], h[MAXN + 10];
int main()
{
	int i, j, n = get_int(), m, q;
	int f[n];
	double mx = 0.0, my = 0.0;
	rep(i, n)
	{
		double x = get_int(), y = get_int();
		a[i] = x + y*I;
	}
	q = get_int();
	query b[q];
	per(i, q)
	{
		b[i].q = getchar(); getchar();
		if (b[i].q == 'c') b[i].t = get_int(), b[i].x = get_int(), b[i].y = get_int();
		else b[i].x = get_int() - 1, b[i].y = -1;
	}
	rep(i, n) f[i] = 0;
	rep(i, q) if (b[i].q == 'q') f[b[i].x] = 1;
	rep(i, n) if (!f[i]) mx = max(mx, real(a[i])), my = max(my, imag(a[i]));

	hull s = hull(cmp);
	s.insert(pt(0, 0));
	s.insert(pt(mx, 0));
	s.insert(pt(0, my));
	rep(i, n) if (!f[i]) add_to_hull(s, a[i]);
	rep(i, q)
	{
		if (b[i].q == 'c') b[i].r = is_in_hull(s, pt((double)b[i].x/b[i].t, (double)b[i].y/b[i].t));
		else
		{
			if (mx < real(a[b[i].x]))
			{
				if (mx > 1e-9) s.erase(pt(mx, 0));
				mx = real(a[b[i].x]);
				s.insert(pt(mx, 0));
			}
			if (my < imag(a[b[i].x]))
			{
				if (my > 1e-9) s.erase(pt(0, my));
				my = imag(a[b[i].x]);
				s.insert(pt(0, my));
			}
			add_to_hull(s, a[b[i].x]);
		}
	}
	per(i, q) if (b[i].q == 'c') printf("%s\n", b[i].r ? "no" : "yes");
	return 0;
}

int get_int()
{
	int ret = 0;
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
		if (c < '0' || c > '9') return sgn*ret;
	}
}
