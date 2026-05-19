#!/usr/bin/env python3
from collections import defaultdict
import random
random.seed(2021)
HMOD = (1<<61)-1
HVALS = defaultdict(lambda: random.randint(1, HMOD-1))

MOD = 10**9 + 7

def make_hashes(L):
    H = [0]
    for x in L: H.append((H[-1] + HVALS[x]) % HMOD)
    return H

n = int(input())
H1 = make_hashes(list(map(int, input().split())))
H2 = make_hashes(list(map(int, input().split())))
diff_freqs = defaultdict(lambda: 0)
for i in range(n-1, -1, -1):
    diff_freqs[(H1[i] - H2[i]) % HMOD] += 1
print(sum(pow(2, v, MOD) - 1 - v for v in diff_freqs.values()) % MOD
      if H1[-1] == H2[-1] else 0)
