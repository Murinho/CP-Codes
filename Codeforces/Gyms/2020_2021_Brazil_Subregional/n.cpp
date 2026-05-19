#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; ++i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll> 
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second

using namespace std;

const ll INF = 1e15;
const ll maxp = 32000000;
const ll maxn = 2010;

ll n,m,k,c[maxn],mcd[maxn],sm[maxn],cur,pos;
vector < pii > adj[maxn]; //{other node, amount of times}.

void init(){
    fore(i,1,m+1) sm[i]=INF, mcd[i]=0ll;
}

void check(){
    ll num=mcd[pos];
    ll cnt=0;
    while(cnt<sm[pos]){
        if (num%cur) break;
        num /= cur;
        cnt++;
    }
    if (cnt==sm[pos]){
        cout<<cur<<" ";
        //Propagate the changes (divide):
        for(auto elm : adj[pos]){
            ll ot = elm.fst - m;
            ll amou = elm.snd;
            while(amou) c[ot] /= cur, amou--;
        }
        pos++;
        //Compute the MCD for the next element:
        if (pos <= m){
            for(auto elm : adj[pos]){
                mcd[pos] = __gcd(mcd[pos],c[elm.fst - m]);
            }
        }
    }
}

int main(){
    fast;
    cin>>m>>n>>k;
    init();
    fore(i,1,n+1) cin>>c[i];

    fore(i,1,k+1){
        ll x,y,d;
        cin>>x>>y>>d;
        y += m;
        adj[x].pb({y,d});
        adj[y].pb({x,d});
        sm[x] = min(sm[x],d);
        if (x==1) mcd[x] = __gcd(mcd[x],c[y-m]);
    }
    cur=2;
    pos=1;
    //Check if the first number is 2:
    check();
    //Proceed in steps of 2:
    cur=3;
    while(cur<maxp && pos<=m){
        check();
        cur += 2;
    }
    fore(i,pos,m+1){
        pii aux = adj[i][0];
        ll ot = aux.fst - m;
        cout<<c[ot]<<" ";
    }
    cout<<nl;
    return 0;
}