#!/usr/bin/env python3
n = int(input())
s = set()
a = list(map(int, input().split()))
b = list(map(int, input().split()))
for e in a: s.add(e)
for e in b:
    s.remove(e)
for e in s: print(e)
