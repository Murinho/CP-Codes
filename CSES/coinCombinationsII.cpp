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
 
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const ll maxn = 1e6+2;
const ll maxc = 101;
const ll mod = 1e9+7;
ll dp[maxn],a[maxc];
ll n,k;

int main(){
    fast;
	cin>>n>>k;
	dp[0] = 1;
	fore(i,0,n){
		cin>>a[i];
		fore(j,0,a[i]){
			ll ways = dp[j];
			for(int x = j+a[i]; x<=k; x += a[i]){
				ll aux = dp[x];
				dp[x] = (dp[x] + ways)%mod;
				ways = (ways + aux)%mod;
			}
		}
	}
	cout<<dp[k]<<nl;
	return 0;
}