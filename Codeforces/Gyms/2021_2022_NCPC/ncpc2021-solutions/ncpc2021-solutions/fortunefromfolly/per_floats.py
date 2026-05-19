#!/usr/bin/env python3

(n, k, p) = input().split()
n, k = map(int, (n, k))
p = float(p)

V = [X for X in range(1<<n) if bin(X).count('1') < k]

d = len(V)
A = [[0]*(d+1) for _ in range(d)]
for (i, X) in enumerate(V):
    X0 = 2*X % (1<<n)
    X1 = (2*X+1) % (1<<n)
    A[i][i] = 1
    A[i][d] = 1
    A[i][V.index(X0)] -= 1-p
    if X1 in V: A[i][V.index(X1)] -= p

    
for i in range(d):
    m = 1.0/A[i][i]
    for k in range(d+1):
        A[i][k] *= m

    for j in range(d):
        if j == i: continue
        m = A[j][i]
        for k in range(d+1):
            A[j][k] -= A[i][k]*m

print(float(A[0][d]))

