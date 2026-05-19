#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,s,r,t,q=0;
    cin>>n>>s;
    vector<int>w(n);
    for(int i=0;i<n;i++)cin>>w[i];
    sort(w.begin(),w.end());
    if(n==1){
        cout<<1;
        return 1<<32;
    }
    r=min(2,s);
    s-=r;
    for(int i=0;i<n-2;i++){
        while(s<w[i]/3&&q<=-2){
            q+=2,s++;
        }
        if(s<w[i]/3)break;
        if(w[i]%3==0){
            s-=w[i]/3;
        }else if(w[i]%3==1){
            if(q>0){
                s-=w[i]/3,q--;
            }else if(w[i]/3+1<=s){
                s-=w[i]/3+1,q--;
            }else if(q<0){
                s-=w[i]/3,q++;
            }else{
                break;
            }
        }else{
            if(q<0){
                s-=w[i]/3,q++;
            }else if(w[i]/3+1<=s){
                s-=w[i]/3+1,q++;
            }else{
                break;
            }
        }
        r++;
    }
    cout<<r;
    return 1<<32;
}