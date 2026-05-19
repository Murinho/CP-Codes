#!/usr/bin/env python3
(n, c) = map(int, input().split())
a = list(map(int, input().split()))
ans = [0]*n
max_pos = max_neg = -(1<<60)
for i in range(n):
    max_pos = max(max_pos, a[i] + c*i)
    max_neg = max(max_neg, -a[i] + c*i)
    ans[i] = max(a[i] - c*i + max_neg, -a[i] - c*i + max_pos)
print(' '.join(map(str, ans)))

    
