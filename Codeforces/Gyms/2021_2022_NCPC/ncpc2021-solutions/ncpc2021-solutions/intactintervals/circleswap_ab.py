import random
LARGE=(1<<62)
PRIME=1000000007

N=int(raw_input())
a=map(int,raw_input().split())
b=map(int,raw_input().split())
nid=0
id=dict()
rnd=[0]*N
for i in range(N):
  if a[i] not in id:
    id[a[i]]=nid
    rnd[nid]=random.randint(1,LARGE)
    nid+=1
    
D=dict()
frq=dict()
pr=[-1]*(2*N+1)
D[0]=0
frq[0]=0
sm=0
r=0
ans=0
twop=[0]*(N+1)
twop[0]=1
for i in range(1,N+1):
  twop[i]=(2*twop[i-1]) % PRIME
          
for i in range(2*N):
  sm=(sm+rnd[id[a[r]]]-rnd[id[b[r]]]) % LARGE
  r+=1
  if r==N: r=0
  if sm in D:
    if i>=N and D[sm]<N+1:
      #print str(i)+' '+str(frq[sm])
      ans=(ans+twop[frq[sm]]-frq[sm]-1) % PRIME
    pr[i+1]=D[sm]
    frq[sm]+=1
  else:
    frq[sm]=1
  D[sm]=i+1
print ans
