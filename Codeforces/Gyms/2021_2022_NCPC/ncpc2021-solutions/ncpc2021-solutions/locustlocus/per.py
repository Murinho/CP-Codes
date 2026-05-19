#!/usr/bin/env python3

k = int(input())
ans = 1<<30
for _ in range(k):
    (y, c1, c2) = map(int, input().split())
    yy = y+1
    while (yy-y) % c1 != 0 or (yy-y) % c2 != 0:
        yy += 1
    ans = min(ans, yy)
print(ans)
