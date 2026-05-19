#include <stdio.h>
#include <stdlib.h>

#define D (6)
#define ANT (D*(D-1)/2+D)
#define MAXN (50)

int v[ANT];
int id[(D+1)*(D+1)];
int n,t;
int adj[ANT][6];
int nadj[ANT];
int v[ANT];
int sz[ANT];
int tot=0;
int gmsk=0;
int best=ANT+1;
  
#define PS0_MASK ((1<<ANT)-1)
#define GETPS0(x) ((x)&PS0_MASK)
#define PS1 (ANT)
#define PS1_MASK 31
#define GETPS1(x) (((x)>>PS1)&PS1_MASK)
#define PS2 (ANT+5)
#define PS2_MASK 31
#define GETPS2(x) (((x)>>PS2)&PS2_MASK)

void solve(int pr, int cnt) {
  int i;
  if (v[pr]) {
    for (i=0;i<nadj[pr];i++) {
      gmsk^=GETPS0(adj[pr][i]);
      if (gmsk==0)
        best=cnt+1;
      else {  
        if (cnt+1<best) {
          v[pr]-=1;
          v[GETPS1(adj[pr][i])]+=1;
          v[GETPS2(adj[pr][i])]+=1;
          solve(pr,cnt+1);
          v[pr]+=1;
          v[GETPS1(adj[pr][i])]-=1;
          v[GETPS2(adj[pr][i])]-=1;
        }
      }
      gmsk^=GETPS0(adj[pr][i]);
    }
  }  
  if (v[pr]&1) {
    tot-=sz[pr];
    gmsk^=(1<<pr);
    
    if (2*t<=tot) { 
      if (gmsk==0)
        best=cnt;
      else  
        if (pr) solve(pr-1,cnt);
    }
    gmsk^=(1<<pr);
    tot+=sz[pr];
  } else
    if (pr) solve(pr-1,cnt);  
}

void add(int cid1,int cid2, int cid3) {
  adj[cid1][nadj[cid1]++]=(1<<cid1)^(1<<cid2)^(1<<cid3)^(cid2<<PS1)^(cid3<<PS2);
}
  
int main()
{
  int i,j,k,l,m;
  char r[8];

  int nid=0;

  for (i=1;i<=D;i++) {
    for (j=i;j<=D;j++) {
      id[i*(D+1)+j]=nid;
      id[j*(D+1)+i]=nid;
      sz[nid]=i*j;
      nid++;
    }
  }
  for (i=0;i<ANT;i++) {
    nadj[i]=0;
    v[i]=0;
  }
  for (i=1;i<=D;i++) {
    for (j=i;j<=D;j++) {
      int cid=id[i*(D+1)+j];
      for (k=1;k<=i/2;k++) 
        add(cid,id[k*(D+1)+j],id[(i-k)*(D+1)+j]);
      if (i!=j) {
        for (k=1;k<=j/2;k++)
          add(cid,id[i*(D+1)+k],id[i*(D+1)+j-k]);  
      }  
    }
  }
  
  scanf("%d %d",&n,&t);
  while (scanf("%s",r)==1) {
    int a=(int)(r[0])-(int)'0';
    int b=(int)(r[2])-(int)'0';
    tot+=a*b;
    v[id[a*(D+1)+b]]+=1; 
  }
  for (i=0;i<ANT;i++)
    if (v[i]&1)
      gmsk^=(1<<i);
  if (gmsk==0) best=0;
      
  solve(ANT-1,0);
  printf("%d\n",best);
  return 0;
}
