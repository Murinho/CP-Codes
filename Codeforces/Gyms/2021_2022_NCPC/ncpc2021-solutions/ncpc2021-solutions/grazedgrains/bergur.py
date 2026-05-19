#!/usr/bin/env python3
n = int(input())
a = [tuple(map(int, input().split())) for _ in range(n)]
r = 0
for (x, y) in [(x/33 - 10, y/33 - 10) for x in range(0, 1000) for y in range(0, 1000)]:
    r += any((x - xx)**2 + (y - yy)**2 <= rr**2 for (xx, yy, rr) in a)
print((1000/33)**2*r/10**6)
