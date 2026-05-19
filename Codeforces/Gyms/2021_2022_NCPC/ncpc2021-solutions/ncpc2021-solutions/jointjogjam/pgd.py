#!/usr/bin/env python3
import sys
from math import hypot

ksx, ksy, osx, osy, kex, key, oex, oey = map(int, sys.stdin.readline().split(" "))
ds = hypot(ksx - osx, ksy - osy)
de = hypot(kex - oex, key - oey)
print(round(max(ds, de), 7))
