#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define f first
#define s second
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

const int C=2e5+5;

using namespace std;

vector<int>g[C];

pair<pair<int,int>,int>p[C];
double d[C];

bool vis[C];

void dfs(int a){
    if(vis[a])return;

    vis[a]=1;
    for(auto v:g[a])dfs(v);
}

int main(){
    //fast;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i].f.f>>p[i].f.s;
        int tt;
        cin>>tt;
        d[i]=(double)tt/2;
        p[i].s=i;
    }

    sort(p,p+n);

    int j=0;

    set<pair<pair<int,int>,int>>s;

    for(int i=0;i<n;i++){
        while(j<n){
            if(p[j].f.f <= p[i].f.f + d[p[i].s] + 80 + 51){
                s.insert({{p[j].f.s,p[j].f.f},p[j].s});
                j++;
            } else break;
        }

        swap(p[i].f.f,p[i].f.s);

        s.erase(p[i]);

        for(auto it=s.lower_bound({{p[i].f.f-d[p[i].s]-80-51,p[i].s},0});it!=s.end();it++){
            if((*it).f.f>p[i].f.f+d[p[i].s]+80+51)break;

            ld dis=sqrtl((ld)(p[i].f.f-(*it).f.f)*(p[i].f.f-(*it).f.f) + (ld)(p[i].f.s-(*it).f.s)*(p[i].f.s-(*it).f.s)); 
            dis-=50.8;
            if(dis<= d[p[i].s] + d[(*it).s]){
                g[p[i].s].pb((*it).s);
                g[(*it).s].pb(p[i].s);
            }
        }
    }

    dfs(0);

    bool xd=1;

    for(int i=0;i<n;i++)if(vis[i]==0)xd=0;

    if(xd==0){
        cout<<"no";
        return 0;
    } else if(n<7){
        cout<<"yes";
        return 0;
    }

    for(int i=0;i<n;i++)if(g[i].size()==1)xd=0;

    if(xd==0){
        cout<<"no";
        return 0;
    } 
    cout<<"yes";
    return 0;

}