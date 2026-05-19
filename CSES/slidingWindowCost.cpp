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
 
using namespace std;
 
const ll maxn = 1e6+10;
 
ll n,k,a[maxn],bg,sm;
ll sl=0,sh=0;
multiset <ll> low,high;
 
void insert(ll val){
    if (val <= *low.rbegin()){ //insert in the lower part.
        low.insert(val);
        sl += val;
        if (sz(low) > (k+1)/2){
            bg = *low.rbegin();
            sl -= bg;
            low.erase(low.find(bg));
            high.insert(bg);
            sh += bg;
        }
    }
    else{
        high.insert(val);
        sh += val;
        if (sz(high) > k/2){
            sm = *high.begin();
            high.erase(high.find(sm));
            sh -= sm;
            low.insert(sm);
            sl += sm;
        }
    }
}
 
ll getMid(){ return (k%2 == 0 ? 0 : *low.rbegin());}
 
void erase(ll val){
     if (high.find(val) != high.end()) high.erase(high.find(val)), sh -= val;
	else low.erase(low.find(val)), sl -= val;
	if (low.empty()) {
		ll moving = *high.begin();
		low.insert(*high.begin());
		sl += moving;
		high.erase(high.find(*high.begin()));
		sh -= moving;
	}
}
 
int main(){
    fast;
    cin>>n>>k;
    fore(i,0,n) cin>>a[i];
 
    if (k == 1){
        fore(i,0,n) cout<<0<<" ";
        cout<<nl;
        return 0;
    }
    if (a[0] <= a[1]){
        low.insert(a[0]), sl=a[0];
        high.insert(a[1]), sh=a[1];
    }
    else{
        low.insert(a[1]), sl=a[1];
        high.insert(a[0]), sh=a[0];
    }
 
    fore(i,2,k) insert(a[i]);
 
    fore(i,k,n){
        cout<<sh - sl + getMid()<<" ";
        erase(a[i-k]);
        insert(a[i]);
    }
    cout<<sh - sl + getMid()<<nl;
    return 0;
}