#!/usr/bin/env python3
import heapq

def solve():
    (n, m, k) = map(int, input().split())
    (k, flip) = (max(k, n-k), k < n-k)
    
    weight = list(map(int, input().split()))
    adj = [[] for _ in range(n)]
    for (u, v) in [map(int, input().split()) for _ in range(m)]:
        adj[u-1].append(v-1)
        adj[v-1].append(u-1)

    dist = [1<<50]*n
    dist[0] = 0
    Q = [(0, 0)]
    while Q:
        (c, u) = heapq.heappop(Q)
        if c == dist[u]:
            for v in adj[u]:
                if c + weight[v] < dist[v]:
                    dist[v] = c + weight[v]
                    heapq.heappush(Q, (dist[v], v))

    sp_adj = [set() for _ in range(n)]
    sp_radj = [set() for _ in range(n)]
    for u in range(n):
        for v in adj[u]:
            if dist[v] == dist[u] + weight[v]:
                sp_adj[u].add(v)
                sp_radj[v].add(u)

    ans = [0]*n
    if n-1 in sp_adj[0]:
        if k == 1:
            return 'impossible'
        for i in range(k-1): ans[i] = 1
        ans[n-1] = 1
    else:
        A = [v for v in sp_adj[0] if n-1 not in sp_adj[v]] + [0]
        X = range(n)
        if len(A) > k:
            A = [v for v in sp_radj[n-1] if 0 not in sp_radj[v]] + [n-1]
            X = range(n-1, -1, -1)
        assert len(A) <= k
        for x in A:
            ans[x] = 1
        rem = k - len(A)
        for i in X:
            if rem and ans[i] == 0:
                ans[i] = 1
                rem -= 1
    if flip:
        ans = [1-x for x in ans]
    return ''.join(map(lambda y: 'SN'[y], ans))

print(solve())
