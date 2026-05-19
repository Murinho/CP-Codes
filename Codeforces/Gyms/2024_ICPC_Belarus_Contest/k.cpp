#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sz(a) ((ll)a.size())
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define nl '\n'
#define fst first
#define snd second
#define vi vector<ll>
#define pii pair <ll,ll>

using namespace std;

const ll maxn = 1e5+10;

ll tc,n,q;
vi a,sum;


void init(){
    a.clear(), a.resize(n+1);
    sum.clear(), sum.resize(n+1);
    sum[0]=0ll;
}

void solve(){
    cin>>n>>q;
    init();
    fore(i,1,n+1){
        cin>>a[i];
        sum[i] = sum[i-1] + a[i];
    }
    while(q--){
        pii s,e; 
        // first: month
        // second: day
        cin>>s.fst>>s.snd>>e.fst>>e.snd;
        swap(s.fst,s.snd);
        swap(e.fst,e.snd);
        if (s <= e){
            if (s.fst == e.fst) cout<<e.snd-s.snd+1<<nl;
            else if (s.fst + 1 == e.fst) cout<<(a[s.fst]-s.snd+1) + e.snd<<nl;
            else cout<<(a[s.fst]-s.snd+1) + e.snd + (sum[e.fst-1] - sum[s.fst])<<nl;
        }
        else{ //darle toda la vuelta.
            ll suf = sum[n]-sum[s.fst]; 
            suf += (a[s.fst]-s.snd+1);
            ll pref = sum[e.fst-1] + e.snd;
            cout<<pref + suf<<nl;
        }
    }
}

int main(){
    fast;
    cin>>tc;
    while(tc--){
        solve();
    }
}