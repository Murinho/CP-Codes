W=6
ANT=(W*(W-1)/2)+W

nid=0
id=dict()
sz=[0]*ANT
for a in range(1,W+1):
  for b in range(a,W+1):
    id[(a,b)]=id[(b,a)]=nid
    sz[nid]=a*b
    nid+=1
adj=[set() for i in range(nid)]
for a in range(1,W+1):
  for b in range(a,W+1):
    for k in range(1,a/2+1):
      s=(id[(k,b)],id[(a-k,b)],(1<<id[(k,b)])^(1<<id[(a-k,b)])^(1<<id[(a,b)]))
      adj[id[(a,b)]].add(s)
    if a!=b:
      for k in range(1,b/2+1):
        s=(id[(a,k)],id[(a,b-k)],(1<<id[(a,k)])^(1<<id[(a,b-k)])^(1<<id[(a,b)]))
        adj[id[(a,b)]].add(s)
if 0:
  # Offline code to find upper bound on number of breaks needed
  worst=0
  dp=[ANT]*(1<<ANT)
  dp[0]=0
  for X in range(1,1<<ANT):
    cnt=0
    for j in range(ANT):
      if sz[j]&1 and (X>>j)&1:
        cnt+=1
    if cnt&1==0:    
      j=ANT-1
      while (X>>j)&1==0:
        j-=1
      for k in adj[j]:
        dp[X]=min(dp[X],dp[X^k[2]]+1)
      if worst<dp[X]:
        worst=dp[X]              
else:
  worst=9

#Tabulate size bounds 
low=[0]*(1<<ANT)
for j in range(ANT):
  c=(1<<j)
  while c<(1<<ANT):
    for k in range(1<<j):
      low[c+k]+=sz[j]
    c+=(1<<(j+1))
         
N,T=map(int,raw_input().split())   
inp=raw_input().split() 
v=[0]*ANT
tot=0
for k in range(N):
  (a,b)=map(int,inp[k].split('x'))
  v[id[(a,b)]]+=1
  tot+=a*b
  
gmk=0
sm=0
for k in range(ANT):
  if v[k]&1:
    gmk^=(1<<k)
  if v[k]:
    sm+=(v[k]&~1)*sz[k]

if sm>=2*T:
  best=0
else:            
  best=worst 
  def rec(ps,cnt):
    global best,gmk,tot,v
    if v[ps]:
      for i1,i2,mk in adj[ps]:
        v[i1]+=1
        v[i2]+=1
        v[ps]-=1
        gmk^=mk
        if tot-low[gmk]>=2*T:
          best=cnt+1
        else:
          if cnt+2<best:
            rec(ps,cnt+1)
        v[ps]+=1
        v[i1]-=1
        v[i2]-=1
        gmk^=mk
    if v[ps]&1==0:
      if cnt<best and ps:
        rec(ps-1,cnt) 
    else:
      tot-=sz[ps]
      if tot>=2*T:
        gmk^=(1<<ps)
        if tot-low[gmk]>=2*T:
          best=cnt
        else:  
          if cnt+1<best and ps:
            rec(ps-1,cnt) 
        gmk^=(1<<ps)
      tot+=sz[ps]        
  rec(ANT-1,0)
print best
