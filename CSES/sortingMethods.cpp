#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i<b;++i)
#define rofe(i,a,b) for(ll i=a-1;i>=b;--i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define lsbpos(x) __builtin_ffs(x)
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define f first
#define s second
#define eb emplace_back
#define ppb pop_back
#define i128 __int128_t
#define ull unsigned long long
 
using namespace __gnu_pbds;
using namespace std;

const ll maxn = 2e5+100;
const ll inf = 1e9+7;
const ll lzneut = 0; // be aware of the value of lzneut!!
const ll neut = 0;

struct STree{ //Lazy Segment Tree with set and add updates with sum get query.
	vi st,lzadd,lzset; int n;
	STree(int n): st(4*n + 5,neut),lzadd(4*n + 5,0), n(n){}

	void increment(int node, int ini, int fin, ll val){
		lzadd[node] += val;
		st[node] += (fin-ini+1)*val;
	}

	void push(int node, int ini, int fin){
		int mid = (ini+fin)/2;
		if (lzadd[node]){
			increment(2*node,ini,mid,lzadd[node]);
			increment(2*node + 1,mid+1,fin,lzadd[node]);
			lzadd[node] = 0;
		}
	}

	void addUpdate(int node, int ini, int fin, int l, int r, ll val){
		if (fin < l || r < ini) return;
		if (l <= ini && fin <= r){
			increment(node,ini,fin,val);
			return;
		}
		push(node,ini,fin);
		ll mid = (ini+fin)/2;
		addUpdate(2*node,ini,mid,l,r,val);
		addUpdate(2*node + 1,mid+1,fin,l,r,val);
		st[node] = st[2*node] + st[2*node + 1];
	}

	ll query(int node, int ini, int fin, int l, int r){
		if (fin < l || r < ini) return neut;
		if (l <= ini && fin <= r){
			return st[node];
		}
		push(node,ini,fin);
		int mid = (ini+fin)/2;
		ll lsum = query(2*node,ini,mid,l,r);
		ll rsum = query(2*node + 1,mid+1,fin,l,r);
		st[node] = st[2*node] + st[2*node + 1];
		return lsum + rsum;
	}

	void addUpdate(int l, int r, ll val){ addUpdate(1,1,n,l,r,val);} //[l,r]
	ll query(int l, int r){ return query(1,1,n,l,r);} //[l,r]
};

ll n;

ll method1(vi a){
	STree st(n);
	map <ll,ll> mp;
	
	fore(i,1,n+1) mp[a[i]] = i;
	
	ll ret = 0;
	
	fore(i,1,n+1){
		ll where = mp[i];
		ll pos = where + st.query(where,where);
		
		ret += (pos-i);
		
		st.addUpdate(1,where,+1);
	}
	
	return ret;
}

ll method2(vi a){
	ll ret=0;
	map <ll,ll> mp;
	fore(i,1,n+1) mp[a[i]] = i; 
	
	fore(i,1,n+1){
		if (mp[i] == i) continue;
		
		int j = mp[i];
		
		swap(a[i],a[j]);
		
		mp[a[i]] = i;
		mp[a[j]] = j;
		
		ret++;
	}
	
	return ret;
}

ll method3(vi a){
	vi lis(n+1);
	ll tam = 1;
	lis[1] = a[1];
	fore(i,2,n+1){
		int l = 0;
		int r = tam;
		while(l < r){
			ll mid = (l+r+1)/2;
			if (lis[mid] < a[i]) l = mid;
			else r = mid-1;
		}
		
		if (l == tam) lis[++tam] = inf;
		
		lis[l+1] = min(lis[l+1],a[i]);
	}
	return n-tam;
}

ll method4(vi a){
	ll cur = n;
	rofe(i,n+1,1){
		if (a[i] == cur){
			cur--;
		}
	}
	return cur;
}

int main(){
    fast;
    cin >> n;
    vi a(n+1);
    fore(i,1,n+1) cin >> a[i];
    
    vi res(5);
    res[1] = method1(a);
    res[2] = method2(a);
    res[3] = method3(a);
    res[4] = method4(a);
    
    fore(i,1,5) cout << res[i] << " ";
    cout << nl;
    
    return 0;
}