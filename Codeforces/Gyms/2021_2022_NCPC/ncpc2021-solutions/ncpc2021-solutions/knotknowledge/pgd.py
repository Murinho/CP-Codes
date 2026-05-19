import sys
_,a,b=map(str.split,sys.stdin.readlines())
print((set(a)-set(b)).pop())
