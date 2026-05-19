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

const ll maxn = 2e5+100;

ll n,x,l,r,lis[maxn],tam;



int main(){
    fast;
	cin>>n;
	fore(i,0,n){
		cin>>x;
		l = 0;
		r = tam;
		while(l < r){
			ll mid = (l+r+1)/2;
			if (lis[mid] < x) l = mid;
			else r = mid-1;
		}
		if (l == tam){
			tam++;
			lis[tam] = x;
		}
		else if (x < lis[l+1]){
			lis[l+1] = x;
		}
	}
	cout<<tam<<nl;
	return 0;
}