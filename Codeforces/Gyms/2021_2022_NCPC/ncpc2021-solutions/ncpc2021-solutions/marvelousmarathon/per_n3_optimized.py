#!/usr/bin/env python3
oo = 1<<60

def best_alloc(M, L1, S1, L2, S2):
    # maximize x*S1 + y*S2
    # subject to
    #   x + 2*y = M,    0 <= x <= L1,   0 <= y <= L2,   x, y integers
    if (M % 2 and L1 == 0): return -oo
    if S2 > 2*S1:
        y = min(L2, M//2)
        x = M - 2*y
    else:
        x = min(L1, M)
        x -= (x^M) & 1
        y = (M-x) // 2
    return x*S1 + y*S2


def solve0(X, L, R, M):
    global ans
    n = len(X)-1
    Lsum = [0]*(n+1)
    Rsum = [0]*(n+1)
    dX = [X[i+1]-X[i] for i in range(n)]
    for i in range(n):
        Lsum[i+1] = Lsum[i] + L[i]*dX[i]
        Rsum[i+1] = Rsum[i] + R[i]*dX[i]
    Score = [[0]*(n+1) for _ in range(n+1)]
    for i in range(n+1):
        for j in range(n+1):
            Score[i][j] = Rsum[j]-Rsum[i] if i < j else Lsum[i] - Lsum[j]

    # no turns
    for i in range(n+1):
        for j in range(i, n+1):
            if X[j] - X[i] == M:
                ans = max(ans, Score[i][j])
            if X[j] - X[i] >= M: break
            if j < n and X[j+1] - X[i] > M:
                ans = max(ans, Score[i][j] + (M - (X[j]-X[i]))*R[j])

    # one turn
    for i1 in range(n):
        i2 = i1
        i3 = 0
        while i2 < n:
            rem0 = M - (X[i2]-X[i1])
            rem = rem0 - (X[i2]-X[i3])
            Lroom = dX[i3-1] if i3 > 0 else 0
            Lscore = L[i3-1] if i3 > 0 else 0
            Rroom = dX[i2]
            Rscore = R[i2] + L[i2]

            if 0 <= rem <= Lroom + 2*Rroom:
                score0 = Score[i1][i2]
                score = score0 + Score[i2][i3]
                ans = max(ans, score + best_alloc(rem, Lroom, Lscore, Rroom, Rscore))
                if i2 < n and 0 <= rem0 <= 2*Rroom:
                    x = min(rem0, Rroom) if R[i2] >= L[i2] else (rem0+1)//2
                    ans = max(ans, score0 + x*R[i2] + (rem0-x)*L[i2])
            if rem < 2*Rroom:
                i3 += 1
            if rem >= 2*Rroom or i2 < i3:
                i2 += 1

    # two turns, first at breakpoint
    for i1 in range(n):
        for i2 in range(i1, n+1):
            if 2*X[i2] < M or 2*(X[i2]-X[i1]) > M: continue
            if Score[0][i2] + Score[i2][0] <= ans: continue
            i3 = i4 = 0
            rem0 = M - ((X[i2] - X[i1]) + (X[i2] - X[i3]))
            Lroom = 0
            Lscore = 0
            Rroom = dX[i4] if i4 < i1 else 0
            Rscore = R[i4] if i4 < i1 else 0
            while i4 <= i1:
                rem = rem0 - (X[i4] - X[i3])
                if 0 <= rem <= Rroom + 2*Lroom:
                    score0 = Score[i1][i2] + Score[i2][i3]
                    score = score0 + Score[i3][i4]
                    ans = max(ans, score + best_alloc(rem, Rroom, Rscore, Lroom, Lscore))
                    if i3 and 0 <= rem0 <= 2*Lroom:
                        x = min(rem0, Lroom) if L[i3-1] >= R[i3-1] else (rem0+1)//2
                        ans = max(ans, score0 + x*L[i3-1] + (rem0-x)*R[i3-1])
                if rem < Rroom:
                    rem0 += dX[i3]
                    i3 += 1
                    if Score[i3-1][i2] + Score[i2][i3-1] <= ans: break
                    Lroom = dX[i3-1]
                    Lscore = L[i3-1] + R[i3-1]
                if rem >= Rroom or i4 < i3:
                    i4 += 1
                    Rroom = dX[i4] if i4 < i1 else 0
                    Rscore = R[i4] if i4 < i1 else 0

    # two turns, second at breakpoint
    for i1 in range(n):
        for i3 in range(i1):
            if 2*(X[n]-X[i3]) < M or X[i1]-X[i3] > M: continue
            if Score[i3][n] + Score[n][i3] <= ans: continue
            i2 = i1
            i4 = i1
            rem = M - ((X[i2] - X[i1]) + (X[i2] - X[i3]) + (X[i4] - X[i3]))
            Lroom = 0
            Lscore = 0
            Rroom = dX[i2]
            Rscore = L[i2] + R[i2]
            while i4 >= i3 and i2 < n:
                if 0 <= rem <= Lroom + 2*Rroom:
                    score = Score[i1][i2] + Score[i2][i3] + Score[i3][i4]                
                    ans = max(ans, score + best_alloc(rem, Lroom, Lscore, Rroom, Rscore))
                if rem < 2*Rroom:
                    rem += dX[i4-1]
                    i4 -= 1
                    if Score[i3][i4+1] + Score[i1][n] + Score[n][i3] <= ans: break
                    if i4 >= i3:
                        Lroom = dX[i4]
                        Lscore = R[i4]
                else:
                    rem -= 2*dX[i2]
                    i2 += 1
                    if i2 < n:
                        Rroom = dX[i2] 
                        Rscore = L[i2] + R[i2]
    
    return ans
                

def solve(X, L, R, M):
    global ans
    ans = 0
    mX = X[-1]
    revX = list(reversed([mX-x for x in X]))
    revL = list(reversed(L))
    revR = list(reversed(R))
    a1 = solve0(X, L, R, M)
    a2 = solve0(X, R, L, M)
    a3 = solve0(revX, revL, revR, M)
    a4 = solve0(revX, revR, revL, M)
    return max(a1, a2, a3, a4)


(m, x, n) = map(int, input().split())

X = {0, m}
LI = []
RI = []
for _ in range(n):
    (start, stop, val) = map(int, input().split())
    X |= {start, stop}
    if start < stop: RI.append((start, stop, val))
    else: LI.append((stop, start, val))

LI.sort()
RI.sort()
X = list(sorted(X))
L = []
R = []
Li = Ri = 0
for i in range(len(X)-1):
    while Li < len(LI) and LI[Li][1] <= X[i]:
        Li += 1
    L.append(LI[Li][2] if Li < len(LI) and LI[Li][0] <= X[i] else 0)
    while Ri < len(RI) and RI[Ri][1] <= X[i]:
        Ri += 1
    R.append(RI[Ri][2] if Ri < len(RI) and RI[Ri][0] <= X[i] else 0)

print(solve(X, L, R, x))
