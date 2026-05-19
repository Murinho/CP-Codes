#!/usr/bin/env python3

HEURISTIC_CAP = 2

def add_piece(state, idx):
    state += 1 << (3*idx)
    if (state >> (3*idx)) & 7 > min(max(1, len(splits[idx])), HEURISTIC_CAP):
        state -= 2 << (3*idx)
    return state

def fix_pair(a, b): return (max(a, b), min(a, b))

pieces = []
piece_id = {}
for w in range(1, 7):
    for h in range(1, w+1):
        piece_id[(w,h)] = piece_id[(h,w)] = len(pieces)
        pieces.append((w, h))
splits = []
for (w, h) in pieces:
    sub = set()
    for a in range(1, w):
        sub.add(fix_pair(piece_id[(a,h)], piece_id[(w-a,h)]))
    for a in range(1, h):
        sub.add(fix_pair(piece_id[(w,a)], piece_id[(w,h-a)]))
    splits.append(sub)

(n, target) = map(int, input().split())
avail = [tuple(map(int, x.split('x'))) for x in input().split()]
start = 0
tot = 0
for (w, h) in avail:
    tot += w*h
    start = add_piece(start, piece_id[(w, h)])
states = {(start, 0): 0}

for (w, h) in reversed(pieces):
    idx = piece_id[(w, h)]
    sub = splits[idx]    
    nstates = {}
    for ((avail, cost), lost) in states.items():
        idx_avail = (avail >> (3*idx)) & 7
        avail -= idx_avail << (3*idx)
        for subset in range(1<<len(sub)):
            rem = idx_avail
            navail = avail
            for (i, (p1, p2)) in enumerate(sub):
                if subset & (1<<i):
                    rem -= 1
                    navail = add_piece(navail, p1)
                    navail = add_piece(navail, p2)
            if rem < 0: continue
            ncost = cost + (idx_avail - rem)
            if ncost > 9: continue
            nlost = lost + (rem % 2)*(w*h)
            if tot - nlost < 2*target: continue
            plost = nstates.get((navail, ncost), 1<<30)
            if nlost < plost:
                nstates[(navail, ncost)] = nlost
    states = nstates
    
print(min(cost for (_, cost) in states))
