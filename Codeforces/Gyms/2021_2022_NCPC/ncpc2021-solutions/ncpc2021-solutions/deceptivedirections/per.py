#!/usr/bin/env python3
(w, h) = map(int, input().split())
Map = [input() for _ in range(h)]
I = input()
(sr, sc) = next((r, c) for r in range(h) for c in range(w) if Map[r][c] == 'S')

def bfs(sr, sc, cond):
    D = [-1]*(w*h)
    D[sr*w + sc] = 0
    Q = [(sr, sc)]
    qh = 0
    while qh < len(Q):
        (r, c) = Q[qh]
        qh += 1
        d = D[r*w+c]
        for (i, nr, nc) in [('N', r-1, c), ('S', r+1, c), ('W', r, c-1), ('E', r, c+1)]:
            if Map[nr][nc] == '.' and D[nr*w+nc] == -1 and cond(i, nr, nc, d):
                D[nr*w+nc] = d+1
                Q.append((nr, nc))
    return D

Dist = bfs(sr, sc, lambda i, nr, nc, d: True)
IDist = bfs(sr, sc, lambda i, nr, nc, d: d < len(I) and I[d] != i and Dist[nr*w+nc] == d+1)

out = [list(row) for row in Map]
for r in range(h):
    for c in range(w):
        if IDist[r*w+c] == len(I): out[r][c] = '!'
    print(''.join(out[r]))
    

     
