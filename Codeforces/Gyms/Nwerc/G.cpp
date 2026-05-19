#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(),a.end()
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define nl '\n'
#define ppb pop_back
#define ld long double

using namespace std;

const int C=1e5+5;

int n,m,que;
int x[C],y[C],z[C];
vector<pair<int,ld>>g[C];

ld dis[C];

int main(){
    fast;
    cin>>n>>m>>que;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i]>>z[i];
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;

        ld aux=0;
        aux+=(x[a]-x[b])*(x[a]-x[b]);
        aux+=(y[a]-y[b])*(y[a]-y[b]);
        aux+=(z[a]-z[b])*(z[a]-z[b]);
        aux*=16;
        aux=sqrt(aux);
        aux=sqrt(aux);
        g[a].pb({b,aux});
        g[b].pb({a,aux});
        //cout<<fixed<<setprecision(10)<<aux<<"\n";
    }

    priority_queue<pair<ld,int>>q;
    q.push({0,1});
    for(int i=1;i<=n;i++)dis[i]=1e9;
    dis[1]=0;
    while(!q.empty()){
        auto x=q.top();
        q.pop();
        if(dis[x.s]<-x.f)continue;
        for(auto l:g[x.s]){
            if(dis[l.f]>-x.f+l.s){
                dis[l.f]=-x.f+l.s;
                q.push({x.f-l.s,0});
            }
        }
    }

    for(int i=0;i<que;i++){
        int a,t;
        cin>>a>>t;
        if(dis[a]>t){
            cout<<"impossible\n";
        } else cout<<fixed<<setprecision(10)<<dis[a]<<"\n";
    }

    return 0;
}