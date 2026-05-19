#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXN (20000)
#define MAXX (10000)
#define REGW (63)
#define MAXD (2*144*MAXX/REGW+10)
#define OFFSET (MAXX/REGW+10)

typedef unsigned long long ull;

void shuffle(int *a, int n)
{
  int i;
  for (i = 0;i < n - 1; i++) {
    int j = i + (long long)rand() * (n - i) / RAND_MAX;
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
  }
}

int N, X;
int n = 0;
int v[MAXN];
ull dp[2][MAXD];
int mir[1<<16];

int cmp(const void* a,const void* b)
{
  return *(int*)a-*(int*)b;
}

int main() 
{
  int i, j, k, lb = 0, par = 0, tot = 0, best = (1<<30), max_spread;
  scanf("%d %d",&N,&X);
  for (i = 0; i < N; i++) {
    int t;
    scanf("%d",&t);
    if (t <= X) {
      v[n++] = X + 1 - t;
    }
    if (t > lb) lb = t;
  }
  qsort(v,n,sizeof(int),cmp);
  
  if (n <= 4) {
    if (n && n <= 2)
      best = X + 1 - v[n-1];
    else
      best = X + 1;
  } else {
    
    max_spread = (((int)2*sqrt(n)+2) * X)/REGW + 3;
    ull rmsk1,rmsk2,lmsk1,lmsk2;
    int shift,left,right;
    unsigned int ls1,ls2,rs1,rs2;
    
    for (i = 0; i < (1<<16); i++) {
      j=((i&0xff00)>>8)|((i&0xff)<<8);
      j=((j&0xf0f0)>>4)|((j&0xf0f)<<4);
      j=((j&0xcccc)>>2)|((j&0x3333)<<2);
      j=((j&0xaaaa)>>1)|((j&0x5555)<<1);
      mir[i]=j;
    }
    n -= 4;
    shuffle(v, n);
    memset(dp[0], 0,  sizeof(ull)*(max_spread+OFFSET));
    dp[0][OFFSET] = 1; 
    
    for (i=0;i<n;i++){
      int shift = v[i];
      tot+=v[i];
      for (j=0;j<(shift>>1)/REGW+2;j++) {
        ull d=dp[i&1][OFFSET+j];
        ull m=0;
        for (k=0;k<3;k++){
          m=(m<<16)+mir[d&0xffff];
          d>>=16;
        } 
        m=(m<<(16-(64-REGW)))+(mir[d]>>(64-REGW));
        if (!par) {
          m&=(1UL<<(REGW-1))-1;
          m<<=1;
          m|=(dp[i&1][OFFSET+j+1]&1);
        }
        dp[i&1][OFFSET-1-j]=m;
      }  
      if (shift&1) {
        shift>>=1;
        left=(-shift-par-REGW+1)/REGW;
        ls1=(((-shift-par)%REGW)+REGW)%REGW;
        right=(shift+1-par)/REGW;
        rs1=(((shift+1-par)%REGW)+REGW)%REGW;
        par^=1;
      } else {
        shift>>=1;
        left=(-shift-REGW+1)/REGW;
        ls1=(((-shift)%REGW)+REGW)%REGW;
        right=(shift)/REGW;
        rs1=(shift)%REGW;
      }
      ls2=(REGW-ls1)%REGW;
      lmsk2=(1UL<<ls1)-1;
      lmsk1=~lmsk2;
      rs2=(REGW-rs1)%REGW;
      rmsk2=(1UL<<rs1)-1;
      rmsk1=~rmsk2;    
        
      memset(dp[(i^1)&1], 0, sizeof(ull)*(max_spread+OFFSET));
      for (j=OFFSET;j<max_spread+OFFSET-right-1;j++) {
        ull r1=dp[i&1][j+right];
        ull r2=dp[i&1][j+right+1];
        ull r12=((r1&rmsk1)>>rs1)|((r2&rmsk2)<<rs2);
        ull l1=dp[i&1][j+left];
        ull l2=dp[i&1][j+left+1];
        ull l12=((l1&lmsk1)>>ls1)|((l2&lmsk2)<<ls2);
        dp[(i^1)&1][j]=r12|l12;
      }
    }    
    for (j=OFFSET;j<max_spread+OFFSET;j++)
      if (dp[n&1][j]) {
        for (k=0;k<REGW;k++)
          if ((dp[n&1][j]>>k)&1){
            int nvl=(j-OFFSET)*(2*REGW)+2*k+par;
            int l1=(tot+nvl)/2;
            l1=tot-l1>l1?tot-l1:l1;
            best=l1+X+1;
            break;
          }
        break;
      }
  }
  best = lb>best?lb:best;      
  printf("%d\n",best);
  return 0;
}
