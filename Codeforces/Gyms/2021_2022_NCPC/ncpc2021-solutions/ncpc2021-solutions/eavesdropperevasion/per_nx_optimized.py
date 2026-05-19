#!/usr/bin/env python3

def SubsetSums(X, t, B):
    # O(|X|*B), based on "Linear Time Algorithms for Knapsack Problems
    # with Bounded Weights" by David Pisinger
    n = len(X)
    MaxPref = [-1]*(2*B+1)
    Cur = [0]*(B+1)
    s = 0
    for brk in range(n):
        if s + X[brk] > t:
            MaxPref[s-(t-B)] = brk
            break
        s += X[brk]
    for i in range(brk, n):
        if MaxPref[B] >= 0: return [t]
        x = X[i]
        for d in range(B, -1, -1):
            MaxPref[d+x] = max(MaxPref[d+x], MaxPref[d])
        for d in range(2*B, B-1, -1):
            j = Cur[d-B]
            while j < MaxPref[d]:
                dj = d - X[j]
                MaxPref[dj] = max(MaxPref[dj], j)
                j += 1
            Cur[d-B] = j
    return [t-B+i for i in range(2*B+1) if MaxPref[i] >= 0]
    
(n, x) = map(int, input().split())
T = list(sorted(map(int, input().split())))
max_T = T[-1]
while T and T[-1] > x: T.pop()
if len(T) > 4:
    Jobs = [x+1-t for t in T[4:]]
    tot = sum(Jobs)
    ans = x+1 + min(max(s, tot-s) for s in SubsetSums(Jobs, tot // 2, max(Jobs)))
elif len(T) > 2:
    ans = x+1
else:
    ans = max_T
print(max(ans, max_T))
