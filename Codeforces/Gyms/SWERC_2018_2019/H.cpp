#include<bits/stdc++.h>
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'
#define pi pair<int,int>
#define pb push_back
#define f first
#define s second
#define ll long long
#define sz(a) ((ll)a.size())
#define fore(i,a,b) for(ll i=a; i<b; i++)

using namespace std;

const int C=1e5+5;

int n,e;
vector<pi>g[C];

int dis[C][3];


vector<pair<array<ll,3>, int>>cord;

int s[4*C] ;

int que(int a, int x, int y, int z){
    if(y<=a)return s[z];
    if(a<x)return 1e9;
    int m=(x+y)/2;
    return min(que(a, x,m,2*z), que(a,m+1,y,2*z+1));
}

void up(int a, int u, int x, int y, int z){
    if(y<a)return;
    if(a<x)return;
    if(x==y){
        s[z]=min(s[z],u);
        return;
    }
    int m=(x+y)/2;
    up(a,u, x,m,2*z), up(a,u,m+1,y,2*z+1);
    s[z]=min(s[2*z],s[2*z+1]);
}

int main(){
    fast;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int x,y,z;
        cin>>x>>y>>z;
        g[x].pb({y,z});
        g[y].pb({x,z});
    }

    for (int i=0;i<3;i++){
        priority_queue<pi> q;
        for(int j=0;j<n;j++){
            dis[j][i]=1e9;
        }

        dis[i][i]=0;

        q.push({0,i});

        while(!q.empty()){
            auto x=q.top();
            q.pop();
            if(-x.f>dis[x.s][i])continue;
            for(auto l:g[x.s]){
                if(-x.f+l.s<dis[l.f][i]){
                    dis[l.f][i]=-x.f+l.s;
                    q.push({x.f-l.s, l.f});
                }
            }
        }
    }

    vector <ll> unicos; // unicos de coordenada y.
    for(int i=0;i<n;i++){
        cord.pb({{dis[i][0], dis[i][1],dis[i][2]}, i});
        unicos.pb(dis[i][1]);
    }

    sort(cord.begin(),cord.end());

    sort(unicos.begin(),unicos.end());

    unicos.erase(unique(unicos.begin(),unicos.end()),unicos.end()); // quita los dups.

    map <ll,ll> mpx;
    fore(i,0,sz(unicos)){ // indexado en 0.
        mpx[unicos[i]] = i;
    }

    for(int i=0;i<n;i++){
        cord[i].f[1]=mpx[cord[i].f[1]];
    }

    for(int i=0;i<4*C;i++)s[i]=1e9;

    int d=0;

    for(int i=1;i<n;i++){
        if(cord[i].f!=cord[i-1].f){
            up(cord[i-1].f[1],cord[i-1].f[2],0,sz(unicos)-1,1 );
        }
        if(que(cord[i].f[1],0,sz(unicos)-1,1)<=cord[i].f[2])d++;
    }

    cout<<n-d;

}
