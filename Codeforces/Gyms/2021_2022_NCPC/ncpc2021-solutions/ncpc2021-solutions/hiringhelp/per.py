#!/usr/bin/env python3
# O(n*(log n)^2) because lazy

import bisect

def bit_sum(idx):
    res = 0
    while idx > 0:
        res += hull_bit[idx]
        idx -= idx & -idx
    return res

def bit_add(idx, v):
    idx += 1
    while idx < len(hull_bit):
        hull_bit[idx] += v
        idx += idx & -idx

class point:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y
    def __sub__(p, q): return point(p.x-q.x, p.y-q.y)
    def __mul__(p, k): return point(p.x*k, p.y*k)
    def cross(p, q): return p.x*q.y - q.x*p.y
    def __lt__(p, q): return p.x < q.x if p.x != q.x else p.y < q.y
    
def next_hull_point(j):
    b = bit_sum(j)
    if bit_sum(n) == b: return None
    lo = j
    hi = n
    while hi-lo > 1:
        m = (lo+hi)//2
        if bit_sum(m) != b:
            hi = m
        else:
            lo = m
    return lo

def prev_hull_point(j):
    b = bit_sum(j)
    if bit_sum(0) == b: return None
    lo = 0
    hi = j
    while hi-lo > 1:
        m = (lo+hi)//2
        if bit_sum(m) != b:
            lo = m
        else:
            hi = m
    return lo
    
def above(p, scale=1):
    q = point((p.x+scale-1)//scale, 0)
    j = bisect.bisect_left(points, q)
    right = next_hull_point(j)
    if right is None: return True
    if p.y <= points[right].y*scale: return False
    left = prev_hull_point(j)
    if left is None: return True
    dp = p - points[left]*scale
    dq = points[right]-points[left]
    return dp.cross(dq) < 0

def add(idx):
    p = points[idx]
    if not above(p): return
    bit_add(idx, 1)
    mid = next_hull_point(idx+1)
    while mid is not None:
        right = next_hull_point(mid+1)
        if right is None or (points[mid]-p).cross(points[right]-points[mid]) < 0:
            break
        bit_add(mid, -1)
        mid = right
    mid = prev_hull_point(idx)
    while mid is not None:
        left = prev_hull_point(mid)
        if points[mid].y > p.y and (left is None or (points[mid]-points[left]).cross(points[idx]-points[mid]) < 0):
            break
        bit_add(mid, -1)
        mid = left
        

n = int(input())
points_orig = [point(*map(int, input().split())) for _ in range(n)]
idxs = list(range(n))
idxs.sort(key=lambda i: (points_orig[i].x << 30) | (points_orig[i].y))
inv_idx = [0]*n
points = [0]*n
for i in range(n):
    inv_idx[idxs[i]] = i
    points[i] = points_orig[idxs[i]]

    

e = int(input())
resigned = [0]*n
queries = []
for _ in range(e):
    line = input().split()
    if line[0] == 'c':
        (t, x, y) = map(int, line[1:])
        queries.append((t, point(x, y)))
    else:
        i = inv_idx[int(line[1])-1]
        resigned[i] = 1
        queries.append((-1, i))

hull_bit = [0]*(n+1)

for i in range(n):
    if not resigned[i]:
        add(i)

ans = []
queries.reverse()
for (t, x) in queries:
    if t == -1: add(x)
    else: ans.append(above(x, t))

print('\n'.join(['no', 'yes'][a] for a in reversed(ans)))
