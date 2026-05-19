from collections import deque
W,H=map(int,raw_input().split())
b=[]
for y in range(H):
  b.append([x for x in raw_input()])
  for x in range(W):
    if b[y][x]=='S':
      sx=x
      sy=y
I=raw_input()
INF=1<<62
dirc=['N','E','S','W']
dx=[0,1,0,-1]
dy=[-1,0,1,0]
def search(F):
  vis=[[INF]*W for y in range(H)]
  vis[sy][sx]=0
  h=deque()
  h.append((0,sx,sy))
  while len(h):
    cst,x,y=h.popleft()
    if cst==vis[y][x]:
      for k in range(4):
        if dirc[k]!=F[cst]:
          nx=x+dx[k]
          ny=y+dy[k]
          if nx>=0 and nx<W and ny>=0 and ny<H and vis[ny][nx]>cst+1 and b[ny][nx]!='#':
            vis[ny][nx]=cst+1
            if cst+1<len(F):
              h.append((cst+1,nx,ny))
  return vis
'''  
for y in range(len(vis)):
  print " ".join(map(str,vis[y]))          
'''
mvis=search(I)
svis=search(' '*len(I))

for y in range(H):
  for x in range(W):
    if mvis[y][x]==len(I) and svis[y][x]==len(I):
      b[y][x]='!'
  print "".join(b[y])
                      