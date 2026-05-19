import random
N=int(raw_input())
INF=1e10
mxw=-INF
mnw=INF
mxh=-INF
mnh=INF
pts=[]
for i in range(N):
  x,y,r = map(int,raw_input().split())
  pts.append((x,y,r*r))
  mxw=max(mxw,x+r)
  mnw=min(mnw,x-r)
  mxh=max(mxh,y+r)
  mnh=min(mnh,y-r)
cnt=0
ITERS=5000000
for i in range(ITERS):
  x=random.random()*(mxw-mnw)+mnw
  y=random.random()*(mxh-mnh)+mnh
  for j in range(N):
    dx=x-pts[j][0]
    dy=y-pts[j][1]
    res=dx*dx+dy*dy
    if res<=pts[j][2]:
      cnt+=1
      break
print float(cnt)/ITERS*(mxw-mnw)*(mxh-mnh)
       