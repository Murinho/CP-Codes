#include <bits/stdc++.h>
#define ll long long
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define nl '\n'
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(u) u.begin(),u.end()
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define lsbpos(x) __builtin_ffs(x)
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second
#pragma GCC target("popcnt")

using namespace std;

const ll maxn = 1e6+5;

struct Ev{ //for horizontal lines.
    ll x,y; // coordinates;
    ll t; //type of point (1 open, 2 close).
};

struct Query{
    ll x,y1,y2;
};

vi uni; //uniques 
map <ll,ll> mp; //from val to pos.
ll n,ans=0,fen[maxn];
vector <Ev> e;
vector <Query> q;

// Sum of values. (1-indexed).
void add(int x, int v){
    while (x < maxn){
        fen[x] += v;
        x += lsb(x);
    }
}
// Getting to whole prefix.
int get(int x){ 
    int freq = 0;
    while (x > 0){
        freq += fen[x];
        x -= lsb(x);
    }
    return freq;
}

bool cmp_ev(Ev e1, Ev e2){
    return e1.x < e2.x;
}

bool cmp_qy(Query q1, Query q2){
    return q1.x < q2.x;
}

int main(){
    fast;
    cin>>n;
    fore(i,1,n+1){
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        if (x1 == x2){ //vertical line.
            if (y1>y2) swap(y1,y2);
            uni.pb(y1), uni.pb(y2);
            Query qy;
            qy.x = x1, qy.y1 = y1, qy.y2 = y2;
            q.pb(qy);
        }
        else{ //horizontal line.
            if (x1>x2) swap(x1,x2);
            uni.pb(y1);
            Ev ev;
            ev.x = x1, ev.y = y1, ev.t = 1;
            e.pb(ev);
            ev.x = x2, ev.y = y2, ev.t = 2;
            e.pb(ev);
        }
    }

    sort(ALL(uni));
    uni.erase(unique(ALL(uni)),uni.end());

    // do the mapping:
    fore(i,0,sz(uni)){
        mp[uni[i]] = i+1;
        //cout<<uni[i]<<": "<<i+1<<nl;
    }
    
    // sort the events:
    sort(ALL(e),cmp_ev);

    //sort the queries:
    sort(ALL(q),cmp_qy);

    // go through the queries while adding events:
    int pos = 0;
    for(auto qy : q){
        while(pos<sz(e) && e[pos].x < qy.x){
            if (e[pos].t == 1) add(mp[e[pos].y],+1);
            else add(mp[e[pos].y],-1);
            pos++;
        }
        ll aux = get(mp[qy.y2]);
        if (mp[qy.y1]>1) aux -= get(mp[qy.y1]-1);
        ans += aux;
    }      
    cout<<ans<<nl;
    return 0;
}