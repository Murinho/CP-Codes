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
#define fore(i,a,b) for(int i=a;i<b;++i)
#define rofe(i,a,b) for(ll i=a-1;i>=b;--i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define lsbpos(x) __builtin_ffs(x)
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
#define eb emplace_back
#define ppb pop_back
#define i128 __int128_t
#define ull unsigned long long
 
using namespace std;

const ll maxn = 2e5+100;
const ll inf = 1e9;

int d1[maxn];//d1[i] = max odd palindrome centered on i
int d2[maxn];//d2[i] = max even palindrome centered on i
int res[maxn][2];
//s  aabbaacaabbaa
//d1 1111117111111
//d2 0103010010301
void manacher(string& s){
	int l=0,r=-1,n=sz(s);
	fore(i,0,n){
		int k=i>r?1:min(d1[l+r-i],r-i);
		while(i+k<n&&i-k>=0&&s[i+k]==s[i-k])k++;
		d1[i]=k--;
		if(i+k>r)l=i-k,r=i+k;
	}
	l=0;r=-1;
	fore(i,0,n){
		int k=i>r?0:min(d2[l+r-i+1],r-i+1);k++;
		while(i+k<=n&&i-k>=0&&s[i+k-1]==s[i-k])k++;
		d2[i]=--k;
		if(i+k-1>r)l=i-k,r=i+k-1;
	}
}

vi salida[maxn]; // guardar los id's de los que salen
multiset <int> mst; // guardar los inicios.
string s;

void init(){
	fore(i,0,sz(s)){
		fore(j,0,2) res[i][j] = inf;
	}
}

void clean(){
	mst.clear();
	fore(i,0,sz(s)) salida[i].clear(), salida[i].resize(0);
}

void process_odd(){
	clean();
	
	fore(i,0,sz(s)){
		int en = i + d1[i] - 1;
		salida[en].pb(i);
		
		mst.insert(i);
		
		// procesar el menor encontrado.
		if (sz(mst)){
			int sm = *mst.begin();
			res[i][0] = min(res[i][0],sm);
		}
		
		// sacar los que van de salida
		for(auto &id : salida[i]){
			mst.erase(mst.find(id));
		}
	}
}

void process_even(){
	clean();
	
	fore(i,0,sz(s)){
		if (d2[i] > 0){
			int en = i + d2[i] - 1;
			salida[en].pb(i);
			
			mst.insert(i);
		}
		if (sz(mst)){
			int sm = *mst.begin();
			res[i][1] = min(res[i][1],sm);
		}
		// sacar los que van de salida
		for(auto &id : salida[i]){
			mst.erase(mst.find(id));
		}
	}
}

int main(){
    fast;
    cin >> s;
    init();
    manacher(s);
    
    /*
    fore(i,0,sz(s)) cout << d1[i] << " ";
    cout << nl;
    fore(i,0,sz(s)) cout << d2[i] << " ";
    cout << nl; */
    
    // process the odd ones.
    process_odd();
    process_even();
    
    fore(i,0,sz(s)){
    	int ans = 0;
    	ans = max(ans,((i-res[i][0])*2) + 1); // with the odd one.
    	ans = max(ans,(i-res[i][1]+1) * 2);
    	
    	cout << ans << " ";
    }
    cout << nl;
    return 0;
}