n,c=map(int,raw_input().split())
b=map(int,raw_input().split())
x=[(b[i],i) for i in range(n)]

dst=[0]*n

tp=0
while (1<<tp)<=n:
  tp+=1
tp-=1

# sum_(x<q) f(x)
def bef(q):
  sm = 0
  while q:
	  sm+=f[q-1]
	  q-=(q&-(q))
  return sm

def ins(p,d):
  global f,ant
  while p<n:
    f[p]+=d
    p+=(p+1)&-(p+1)
  ant+=d
  
# find largest y so that sum_x<y f(x)<=value     
def rank(value):
  i=0
  j=1<<tp	
  while j>0:
    if i + j <= n and f[i + j - 1] <= value:
      value -= f[i + j - 1]
      i += j
    j>>=1  
  return i;    

def sweep(x): 
  global f,ant,dst
  f=[0]*n
  ant=0
  for i in range(n):
    ps=bef(x[i][1])
    nd=0
    if ps>0:
      lft=rank(ps-1)
      nd=abs(x[i][0]-b[lft])-c*abs(lft-x[i][1])
      if nd>dst[x[i][1]]:
        dst[x[i][1]]=nd
    if nd<=0:
      ins(x[i][1],1)
               
x.sort()
sweep(x) 
x.sort(reverse=True)
sweep(x)

print " ".join(map(str,dst))