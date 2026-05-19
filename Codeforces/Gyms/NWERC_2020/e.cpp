#include <bits/stdc++.h>
using namespace std;
using ll=long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N=1e5+5;
int x[N],y[N];
int n,ax,ay,bx,by;
set<pair<int,int>>st;

bool atk(int x1,int y1){
    for(int i=0;i<n;i++)
        if(st.count({x1-x[i],y1-y[i]}))
            return 1;
    return st.count({x1,y1});
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>ax>>ay>>bx>>by;
    uniform_int_distribution<int>dis(1,n);
    srand(time(0));
    for(int i=0;i<n;i++)cin>>x[i]>>y[i];
    for(int i=0;i<n;i++)
        if(0<ax+x[i]&&ax+x[i]<=n&&0<ay+y[i]&&ay+y[i]<=n)
            st.insert({ax+x[i],ay+y[i]});
    if(atk(bx,by)){
        cout<<"Alice wins";
        return 1<<32;
    }
    st.clear();
    st.insert({bx,by});
    for(int i=0;i<n;i++)
        if(0<bx+x[i]&&bx+x[i]<=n&&0<by+y[i]&&by+y[i]<=n)
            st.insert({bx+x[i],by+y[i]});
    if(n<=100){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(!atk(i,j)){
                    cout<<"tie "<<i<<" "<<j;
                    return 1<<32;
                }
            }
        }
        cout<<"Bob wins";
    }else while(true){
        int i=dis(rng),j=dis(rng);
        if(!atk(i,j)){
            cout<<"tie "<<i<<" "<<j;
            return 1<<32;
        }
    }
}