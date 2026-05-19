#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector<ll>
#define ALL(a) a.begin(),a.end()
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define nl '\n'

using namespace std;

int main(){
    fast;

    int c,p,x,l;
    cin>>c>>p>>x>>l;
    x--;
    l--;

    vector<vector<int>>g(c,vector<int>());
    vector<bool>vis(c,0);

    for(int i=0;i<p;i++){
        int x2,y2;
        cin>>x2>>y2;
        x2--;
        y2--;
        g[x2].push_back(y2);
        g[y2].push_back(x2);
    }
    set<int>eli;
    
    queue<int>next;
    next.push(l);
    eli.insert(l);
    vis[l]=1;
    for(auto nxt:g[l]){
        next.push(nxt);
    }
    while(!next.empty()){
        int x = next.front();
        next.pop();
        vis[x]=1;
        int cant=0;
        for(auto nxt:g[x]){
            if(eli.find(nxt) != eli.end()){
                cant++;
            }
        }
        if(cant >= ceil((double)g[x].size()/2.0)){
            eli.insert(x);
        }
        for(auto nxt:g[x]){
            if(!vis[nxt]){
                next.push(nxt);
            }
        }
    }

    cout<<((eli.find(x)!=eli.end())?"leave":"stay");
    

    return 0;
}