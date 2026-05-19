#!/usr/bin/env python3
import sys
import math


def lcm(a, b):
    return abs(a * b) // math.gcd(a, b)


k = int(sys.stdin.readline())
pairs = [tuple(map(int, sys.stdin.readline().split(" "))) for _ in range(k)]
# print(pairs)
# print([y + lcm(c1, c2) for (y, c1, c2) in pairs])
print(sorted([y + lcm(c1, c2) for (y, c1, c2) in pairs])[0])
