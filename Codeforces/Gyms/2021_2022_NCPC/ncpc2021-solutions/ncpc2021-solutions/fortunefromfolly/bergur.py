#!/usr/bin/env python3
from fractions import Fraction

def gauss(a, n):
    r = 0;
    for i in range(n):
        t = 0;
        while t < n and a[i][t] == Fraction(0): t += 1
        if t == n: continue;
        r += 1
        for j in range(t, n + 1)[::-1]: a[i][j] = a[i][j]/a[i][t]
        for j in range(n):
            if i != j:
                for k in range(t, n + 1)[::-1]: a[j][k] = a[j][k] - a[i][k]*a[j][t]
    return r

def popcnt(a):
        if a == 0: return 0
        return a%2 + popcnt(a//2)

n, k, pp = input().strip().split()
n = int(n)
k = int(k)
m = 1 << n
p = Fraction(pp)
a = []
e = []
for i in range(m):
    l = []
    for j in range(m): l.append(Fraction(0))
    a.append(l)
for i in range(m):
    l = []
    for j in range(m + 1):
        if i == j or j == m: l.append(Fraction(1))
        else: l.append(Fraction(0))
    e.append(l)

for i in range(m):
    if popcnt(i) == k: a[i][i] = Fraction(1)
    else:
        a[i][((m - 1)&(i << 1))] = Fraction(1) - p
        a[i][((m - 1)&(i << 1)) + 1] = p
for i in range(m):
    for j in range(m):
        e[i][j] = e[i][j] - a[i][j]
for i in range(m):
    if popcnt(i) >= k:
        e[i][m] = Fraction(0)
        e[i][i] = Fraction(1)
gauss(e, m);
print(float(e[0][m]))
