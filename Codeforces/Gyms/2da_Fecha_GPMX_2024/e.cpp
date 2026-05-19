#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; ++i)
#define ALL(u) u.begin(), u.end()
#define vi vector <ll>
#define vvi vector <vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second

using namespace std;

const ll maxn = 1e5+10;
ll n,a[maxn],tot=0;
vector < pii > v[maxn];
vector < pii > b,res;
bool flag = true;

int main(){
    fast;
    cin>>n;
    fore(i,1,n+1) cin>>a[i], b.pb({a[i],i});

    sort(ALL(b));
    
    fore(i,0,n){
        if (b[i].fst-1 > i){
            flag=false;
            break;
        }
        fore(j,0,b[i].fst-1){
        	res.pb({b[i].snd,b[j].snd});
        }
    }
    if (!flag) cout<<-1<<nl;
    else{
        cout<<sz(res)<<nl;
        for(auto au : res) cout<<au.fst<<" "<<au.snd<<nl;
    }
    return 0;
}