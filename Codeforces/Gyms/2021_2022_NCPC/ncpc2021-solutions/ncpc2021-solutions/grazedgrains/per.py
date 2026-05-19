#!/usr/bin/env python3
import random
random.seed(2021)
ITERS = 1<<20

n = int(input())
C = [tuple(map(int, input().split())) for _ in range(n)]
hits = 0
for _ in range(ITERS):
    x = random.uniform(-10, 20)
    y = random.uniform(-10, 20)
    hits += any((x-xc)**2 + (y-yc)**2 <= r**2 for (xc, yc, r) in C)

print('%.3f' % (30*30*hits/ITERS))
