#!/usr/bin/env python3
import sys
V = list(map(int, sys.stdin.read().split()))
print(next(x for x in V[1:V[0]+1] if x not in V[V[0]+1:]))

      
