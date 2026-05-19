#include <stdio.h>

int gcd(a,b)
{
  int mx=a>b?a:b;
  int mn=a+b-mx;
  while (mx%mn) {
    int tmp=mx%mn;
    mx=mn;
    mn=tmp;
  }
  return mn;
}

int main()
{
  int k,i,y,c1,c2, first=1<<30;
  scanf("%d",&k);
  for (i = 0;i < k;i++) {
    scanf("%d %d %d",&y,&c1,&c2);
    int lcm=c1*c2/gcd(c1,c2);
    if (y+lcm<first)
      first=y+lcm;
  }
  printf("%d\n",first);  
}