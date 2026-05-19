#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i<b;++i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((int)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
 
using namespace std;

const ll maxn = 2e5+5;
const ll INF = 1e9+7;

struct Ev{
    ll typ,t,id;
};

ll n,a[maxn],b[maxn],len[maxn];
pii v[maxn];
vector < Ev > e;
set < pii > wtc;
set < pii > opens;

bool cmp(Ev e1, Ev e2){
    if (e1.t == e2.t){
        return len[e1.id] < len[e2.id];
    }
    return e1.t < e2.t;
}

int main(){
    fast;
    cin>>n;
    fore(i,0,n){
        ll x,y;
        cin>>x>>y;
        v[i]={x,y};
        len[i] = y-x+1;
        Ev ev;
        ev.id = i;
        ev.typ = 1;
        ev.t = x;
        e.pb(ev);
        ev.typ = 2;
        ev.t = y;
        e.pb(ev);
    }

    sort(ALL(e),cmp);

    fore(i,0,sz(e)){
        Ev cur = e[i];
        if (cur.typ == 1){ //abre.
            wtc.insert({cur.t,cur.id});
            opens.insert({cur.t,cur.id});
        }
        else{ //closes.
            opens.erase({v[cur.id].fst,cur.id}); //close the current one.
            if (sz(opens)){ //check if current range is contained by another one. 
                pii sm = *opens.begin();
                if (sm.fst <= v[cur.id].fst) b[cur.id]=1;
            }
            while(!wtc.empty()){
                pii sm = *wtc.begin();
                if (sm.fst > v[cur.id].fst) break;
                wtc.erase(sm);
                if (sm.snd != cur.id) a[sm.snd]=1; //a bigger range contains the current range.
            }
        }
    }
    fore(i,0,n) cout<<a[i]<<" ";
    cout<<nl;
    fore(i,0,n) cout<<b[i]<<" ";
    cout<<nl;
    return 0;
}