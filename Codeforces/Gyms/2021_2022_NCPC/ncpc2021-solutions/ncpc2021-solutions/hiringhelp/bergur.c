// I havent tested this a lot.
// I also havent tested list on its own.
// pitfalls so fat:
// 		not checking whether the point to add is in the current hull.
//		when removing an element you must sometimes decrement the binary searched index.
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#define EPS 1e-15
#define rep(E, F) for (E = 0; E < (F); E++)
#define per(E, F) for (E = (F) - 1; E >= 0; E--)
int min(int a, int b) { if (a > b) return b; return a; }
int max(int a, int b) { if (a < b) return b; return a; }
typedef double complex pt;
typedef long long ll;
typedef struct { int t, q, x, y, r; } query;
int get_int();

typedef struct map_snode map_node;
struct map_snode
{
	struct map_snode *l, *r;
	int v, u;
	pt w;
	ll p;
};
typedef struct { map_node* a; } map;
typedef struct
{
	map* a;
	int n;
} list;

list* list_init();
void list_free(list*);
pt list_access(list*, int);
void list_remove(list*, int);
void list_insert(list*, int, pt);

int ccw(pt a, pt b, pt c)
{
	if (cabs(a - b) < EPS || fabs(cimag((c - a)/(b - a))) < EPS) return 0;
	return cimag((c - a)/(b - a)) > 0.0 ? 1 : -1;
}

pt piv;
int cmp(const void* p1, const void* p2)
{
	pt a = *(pt*)p1, b = *(pt*)p2;
	if (fabs(carg(a - piv) - carg(b - piv)) > EPS)
		return carg(a - piv) < carg(b - piv) ? -1 : 1;
	if (fabs(cabs(a - piv) - cabs(b - piv)) < EPS) return 0;
		return cabs(a - piv) < cabs(b - piv) ? -1 : 1;
}

int convex_hull(pt* p, pt* h, int n)
{
	if (n == 0) return 0;
	int j = 0, i, mn = 0;
	for (i = 1; i < n; i++)
		if (cimag(p[i]) < cimag(p[mn]) || cimag(p[i]) == cimag(p[mn])
				&& creal(p[i]) < creal(p[mn])) mn = i;
	pt t = p[mn]; p[mn] = p[0]; p[0] = t;
	piv = p[0]; 
	qsort(p + 1, n - 1, sizeof(p[1]), cmp);

	for (i = 1; i < n && cabs(p[0] - p[i]) < EPS; i++);
	if (i == n) h[j++] = p[0];
	else if (i == n - 1) h[j++] = p[0], h[j++] = p[n - 1];
	if (i >= n - 1) return j;
	h[j++] = p[n - 1], h[j++] = p[0], h[j++] = p[i];
	if (ccw(h[0], h[1], h[2]) == 0)
		return j - (cabs(h[0] - h[1]) < EPS ? 2 : 1);
	for (i++; i < n;)
		(cabs(h[j - 1] - p[i]) > EPS && ccw(h[j - 2], h[j - 1], p[i]) == 1)
			? (h[j++] = p[i++]) : j--;
	return --j;
}

int on_segment(pt a, pt b, pt p)
{ // is |p| on the segment |<a, b>|?
	if (fabs(creal(a) - creal(b)) < EPS) return on_segment(a*I, b*I, p*I);
	if (ccw(a, b, p) != 0) return 0;
	if (creal(p) + EPS < fmin(creal(a), creal(b))) return 0;
	if (creal(p) - EPS > fmax(creal(a), creal(b))) return 0;
	return 1;
}

int search(list* l, double a)
{
	int r = 1, s = l->n; // the first element is always (0, 0).
	while (r < s)
	{
		int m = (r + s)/2;
		double h = carg(list_access(l, m));
		if (a < h) s = m;
		else r = m + 1;
	}
	return r;
}

int is_in_hull(list* l, pt p)
{
	int r = search(l, carg(p));
	if (l->n < 3) return 0;
	if (creal(p) < EPS) return cimag(p) - EPS < cimag(list_access(l, l->n - 1));
	if (cimag(p) < EPS) return creal(p) - EPS < creal(list_access(l, 1));
	return ccw(list_access(l, (r - 1 + l->n)%l->n), list_access(l, r%l->n), p) != -1;
}

void add_to_hull(list* l, pt p)
{
	if (is_in_hull(l, p)) return;

	int r = search(l, carg(p));
	if (l->n < 3)
	{ // this will always make a box.
		list_insert(l, r, p);
		return;
	}

	pt p1 = list_access(l, (r - 1 + l->n)%l->n), p2 = list_access(l, r%l->n);
	list_insert(l, r, p);
	while (ccw(list_access(l, (r - 2 + l->n)%l->n), list_access(l, (r - 1 + l->n)%l->n), list_access(l, r%l->n)) != 1)
	{
		list_remove(l, (r - 1 + l->n)%l->n);
		if (r != 0) r--;
	}
	while (ccw(list_access(l, r%l->n), list_access(l, (r + 1)%l->n), list_access(l, (r + 2)%l->n)) != 1)
	{
		list_remove(l, (r + 1)%l->n);
		if (r == l->n - 1) r--; // TODO: Make case that fails when this line is missing.
	}
}

#define MAXN 200000
pt a[3*MAXN + 1], g[3*MAXN + 1], h[3*MAXN + 1];
int main()
{
	int i, j, n = get_int(), m, q, gg = 0;
	int f[n];
	double mx = 0.0, my = 0.0;
	rep(i, n)
	{
		double x = get_int(), y = get_int();
		a[3*i + 0] = x + y*I;
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
	rep(i, n) if (!f[i]) g[gg++] = a[3*i], mx = fmax(mx, creal(a[3*i])), my = fmax(my, cimag(a[3*i]));
	g[gg++] = 0;
	g[gg++] = mx;
	g[gg++] = my*I;
	m = convex_hull(g, h, gg);
	list* l = list_init();
	j = 0;
	rep(i, m) if (carg(h[i]) < carg(h[j])) j = i;
	rep(i, m) list_insert(l, l->n, h[(j + i)%m]);
	rep(i, q)
	{
		if (b[i].q == 'c') b[i].r = is_in_hull(l, 1.0*b[i].x/b[i].t + 1.0*b[i].y*I/b[i].t);
		else
		{
			add_to_hull(l, a[3*b[i].x]);
			if (mx < creal(a[3*b[i].x])) mx = creal(a[3*b[i].x]), add_to_hull(l, mx);
			if (my < cimag(a[3*b[i].x])) my = cimag(a[3*b[i].x]), add_to_hull(l, I*my);
		}
	}
	per(i, q) if (b[i].q == 'c') printf("%s\n", b[i].r ? "no" : "yes");
	list_free(l);
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

map_node* map_init_node(map_node* l, map_node* r, int v, pt w, ll p)
{
	map_node* x = malloc(sizeof(map_node));
	x->l = l, x->r = r, x->p = p, x->v = v, x->w = w, x->u = 0;
	return x;
}

ll map_rand()
{
	ll r = rand();
	return r*RAND_MAX + rand();
}

map* map_init()
{
	srand(time(NULL));
	map* r = malloc(sizeof(*r));
	r->a = NULL;
	return r;
}

void map_node_free(map_node* t)
{
	if (!t) return;
	map_node_free(t->r);
	map_node_free(t->l);
	free(t);
}

void map_free(map* t)
{
	map_node_free(t->a);
	free(t);
}

void map_propagate(map_node* t)
{
	if (!t) return;
	if (t->l) t->l->u += t->u;
	if (t->r) t->r->u += t->u;
	t->v += t->u;
	t->u = 0;
}

void map_update(map* t, int x, int v)
{
	map_node *h = t->a;
	map_propagate(h);
	while (h)
	{
		map_propagate(h->l);
		map_propagate(h->r);
		if (h->v < x) h = h->r;
		else
		{
			h->v += v;
			if (h->r) h->r->u = v;
			h = h->l;
		}
	}
}

int map_is_in(map* a, int x)
{
	if (a->a == NULL) return 0;
	map_node *h = a->a;
	map_propagate(h);
	while (h)
	{
		map_propagate(h->l);
		map_propagate(h->r);
		if (x < h->v) h = h->l;
		else if (x > h->v) h = h->r;
		else return 1;
	}
	return 0;
}

void map_split(map_node *t, int x, map_node **l, map_node **r)
{
	map_propagate(t);
	while (t)
	{
		map_propagate(t->l), map_propagate(t->r);
		if (t->v > x) *r = t, r = &(t->l), t = t->l;
		else *l = t, l = &(t->r), t = t->r;
	}
	*l = *r = NULL;
}

void map_merge(map_node **t, map_node *l, map_node *r)
{
	while (l && r)
	{
		map_propagate(l), map_propagate(r);
		if (l->p > r->p) *t = l, t = &(l->r), l = l->r;
		else *t = r, t = &(r->l), r = r->l;
	}
	*t = l ? l : r;
}

int map_insert(map* a, int x, pt w)
{
	if (map_is_in(a, x)) return 0;
	if (a->a == NULL)
	{
		a->a = map_init_node(NULL, NULL, x, w, map_rand());
		return 1;
	}
	ll p = map_rand();
	map_node **l = &(a->a), **r, *t = a->a;
	while (t && t->p > p)
	{ // search
		map_propagate(t);
		l = x < t->v ? &(t->l) : &(t->r);
		t = x < t->v ? t->l : t->r;
	}
	map_node* h = map_init_node(NULL, NULL, x, w, p);
	*l = h;
	l = &(h->l), r = &(h->r);
	map_split(t, h->v, &(h->l), &(h->r));
	return 1;
}

int map_remove(map* a, int x)
{
	if (a->a == NULL) return 0;
	map_node **l = &(a->a), *t = a->a, *d;
	while (t && t->v != x)
	{ // search
		map_propagate(t);
		l = x < t->v ? &(t->l) : &(t->r);
		t = x < t->v ? t->l : t->r;
	}
	if (!t) return 0;
	d = t;
	map_merge(l, t->l, t->r);
	free(d);
	return 1;
}

map_node* map_search(map* t, int x)
{
	map_node *h = t->a;
	while (h)
	{ // search
		map_propagate(h);
		if (x < h->v) h = h->l;
		else if (x > h->v) h = h->r;
		else return h;
	}
	assert(0);
}

pt map_access(map* t, int x)
{
	return map_search(t, x)->w;
}

/* LIST */

list* list_init()
{
	list* r = malloc(sizeof(*r));
	r->n = 0;
	r->a = map_init();
	return r;
}

void list_free(list *l)
{
	map_free(l->a);
	free(l);
}

pt list_access(list *l, int x)
{
	assert(0 <= x);
	assert(x < l->n);
	return map_access(l->a, x);
}

void list_remove(list *l, int x)
{
	map_remove(l->a, x);
	map_update(l->a, x, -1);
	l->n--;
}

void list_insert(list* l, int x, pt y)
{
	map_update(l->a, x, 1);
	map_insert(l->a, x, y);
	l->n++;
}

