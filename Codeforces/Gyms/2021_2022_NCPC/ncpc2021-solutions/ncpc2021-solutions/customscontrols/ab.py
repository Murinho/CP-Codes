import heapq
N,M,K=map(int,raw_input().split())
T=map(int,raw_input().split())
adj=[[] for i in range(N)]
for i in range(M):
  u,v=map(int,raw_input().split())
  u-=1
  v-=1
  adj[u].append(v)
  adj[v].append(u)
def search(s,t):
  h=[(0,s)]
  INF=1<<62
  dst=[INF]*N
  dst[s]=0
  while len(h):
    cst,who=heapq.heappop(h)
    if cst==dst[who]:
      if who==t:
        break
      for nxt in adj[who]:
        if cst+T[who]<dst[nxt]:
          dst[nxt]=cst+T[who]
          heapq.heappush(h,(cst+T[who],nxt))
  return dst

dst_st=search(0,N-1)
dst_ts=search(N-1,0)
dist=dst_st[N-1]+T[N-1]
dst=[x for x in range(N) if dst_st[x]+dst_ts[x]+T[x]==dist]
sdst=set(dst)
extra=[x for x in range(N) if x not in sdst]
if len(dst)==2 and N==2 and K==1:
  print "impossible"
else:
  mrk=[0]*N
  if len(dst)==2 and K>1:
    mrk[0]=mrk[N-1]=1
    K-=2
  for i in range(min(K,len(extra))):
    mrk[extra[i]]=1
  K-=min(K,len(extra))
  if K:   
    h=[(dst_st[x],x) for x in dst]
    heapq.heapify(h)
    while K:
      d,w=heapq.heappop(h)
      mrk[w]=1
      K-=1
  print "".join(map(lambda y:'SN'[y],mrk))
