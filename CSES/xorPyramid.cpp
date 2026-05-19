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

const ll maxn = 2e5+100;

ll n,res=0,ex[maxn];

int main(){
    fast;
    cin>>n;
   	ex[1] = 0;
   	fore(i,2,n+1){
   		ex[i] += ex[i-1];
   		ll x = i;
   		while(x%2 == 0){
   			ex[i]++, x/=2;
   		}
   	}
   	
   	fore(i,1,n+1){
   		ll x;
   		cin >> x;
   		if (ex[n-1] - ex[i-1] - ex[n-i] == 0) res ^= x;
   	}
   	cout << res << nl;
   	return 0;
}