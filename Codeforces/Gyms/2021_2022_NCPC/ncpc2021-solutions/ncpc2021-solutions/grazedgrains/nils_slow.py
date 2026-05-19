#!/usr/bin/env python3
import random

n = int(input())
X = []
Y = []
R = []
for i in range(n):
    x, y, r = map(int, input().split())
    X.append(x)
    Y.append(y)
    R.append(r)

hits = 0
LIM = 500000

for _ in range(LIM):
    hit = False
    x = random.uniform(-10, 20)
    y = random.uniform(-10, 20)
    for i in range(n):
        if (X[i] - x)**2 + (Y[i] - y)**2 <= R[i]**2:
            hit = True
            break
    hits += int(hit)

tot = 900.0
print(float(hits) * tot / LIM)
