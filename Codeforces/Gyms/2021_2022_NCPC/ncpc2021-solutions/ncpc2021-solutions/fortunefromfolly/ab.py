inp=raw_input().split()
n=int(inp[0])
k=int(inp[1])
p=float(inp[2])

id=[]
ids=dict()
ks=[]
for i in range(1<<n):
  X=i
  cnt=0
  while X:
    b=X&-X
    X^=b
    cnt+=1
    if cnt>k: break
  if cnt<k or (cnt==k and i&(1<<(n-1))):
    ids[i]=len(id)
    if cnt==k:
      ks.append(len(id))   
    id.append(i)
dim=len(id)         
mx=[[0.0]*dim for i in range(dim)]

for i in range(dim):
  mx[i][i]=1.0
  X=id[i]
  if i not in ks:
    X>>=1
    mx[ids[X]][i]-=(1-p)
    X^=(1<<(n-1))
    if X in ids:
      mx[ids[X]][i]-=p

def inv(A):
  dim=len(A)
  imx=[[0.0]*dim for i in range(dim)]
  for i in range(dim):
    imx[i][i]=1.0
  for i in range(dim):
    inv=1.0/A[i][i]
    for k in range(dim):
      A[i][k]*=inv
      imx[i][k]*=inv
    
    for j in range(dim):
      if i!=j:
        mul=A[j][i]
        for k in range(dim):
          A[j][k]-=A[i][k]*mul
          imx[j][k]-=imx[i][k]*mul
  return imx
  
def mul(A,B):
  res=[[0.0]*dim for i in range(dim)]
  for i in range(dim):
    for j in range(dim):
      sm=0.0
      for k in range(dim):
        sm+=A[i][k]*B[k][j]
      res[i][j]=sm
  return res
   
imx=inv(mx)
res=mul(imx,imx)
ans=0.0
for i in ks:
  ans+=res[i][0]
print ans-1.0
           