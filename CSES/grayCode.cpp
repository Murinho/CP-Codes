#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i<b;++i)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((int)a.size())
#define lsb(x) ((x)&(-x))
#define lsbpos(i) __builtin_ffs(i)
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
 
using namespace std;

const ll maxn = 16;

ll n;
bool b[maxn+1];

void print(){
	rofe(i,n+1,1) cout<<b[i];
	cout<<nl;
}

int main(){
    fast;
	cin>>n;
	print();
	fore(i,1,(1ll<<n)){
		b[__builtin_ffs(i)] ^= 1;
		print();
	}
}