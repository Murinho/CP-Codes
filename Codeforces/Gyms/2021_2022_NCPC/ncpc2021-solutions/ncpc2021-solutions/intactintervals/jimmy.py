#!/usrbin/env python3
import random
from collections import defaultdict
random.seed(0)

hasher = defaultdict(lambda: 1 + random.getrandbits(63))
n = int(input())
a = map(lambda x: hasher[x], input().split())
b = map(lambda x: hasher[x], input().split())
a = [x - y for x,y in zip(a,b)]

cur = 0
num_chains = {}
first = {}
for i in range(0, n*2):
    if cur in num_chains:
        if first[cur] + n > i:            
            num_chains[cur] += 1
    else:
        first[cur] = i
        num_chains[cur] = 1
    cur += a[i%n]

print(sum(2**cnt - cnt - 1 for cnt in num_chains.values()) % (10**9+7))
