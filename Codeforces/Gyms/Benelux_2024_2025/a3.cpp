#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fore(i,a,b) for(ll i = a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'
#define pii pair <ll,ll>
#define vi vector<ll>
#define vvi vector<vi>
#define fst first
#define snd second
#define sz(a) ((ll) a.size())
#define ALL(a) a.begin(),a.end()
#define ppb pop_back

using namespace std;

struct Team{
    ll val,fav;
};

vector <Team> a;

ll n,m,k,cur,totp=0;
string s;

int main(){
    fast;
    cin>>n>>m>>k;
    fore(i,1,n+1){
        cin>>s;
        ll cnt = 0;
        for(auto &elm : s) if (elm == 'P') cnt++;
        a.pb({cnt,(i == k ? 1 : 0)});
        totp += cnt;
    }
    cur = n-1;
    fore(i,0,totp){
        cin>>s;
        cin>>s;
        while(sz(s) && s.back() != 'y') s.ppb();
        reverse(ALL(s));
        while(sz(s) && s.back() != 'y') s.ppb();

        ll mov = sz(s) - 3;
        a[cur].val--;
        if (mov >= 0){
            ll nwpos = cur - mov;
            
            vector <Team> b;
            fore(i,0,nwpos) b.pb(a[i]);
            b.pb(a[cur]);
            fore(i,nwpos,cur) b.pb(a[i]);
            fore(i,cur+1,n) b.pb(a[i]);
            a = b;
        }
        while(cur >= 0 && a[cur].val == 0){
            cur--;
        }
    }   

    ll ans = 0;
    for(auto &elm : a){
        ans++;
        if (elm.fav == 1) break;
    }
    cout<<ans<<nl;
    return 0;


}