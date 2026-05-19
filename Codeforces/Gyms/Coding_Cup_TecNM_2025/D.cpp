// Problem: D. Dificultad mínima
// Contest: Codeforces - Coding Cup TecNM 2025
// URL: https://codeforces.com/gym/106113/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const ll maxn = 1e6+10;
const ll inf = 1e18;
const ld eps = 1e-6;
// 
// struct Bigint{
	// string a;
	// int sign;
// 	
	// Bigint() {}
// 	
	// void operator =(string b){
		// a=(b[0]=='-' ? b.substr(1) : b);
		// reverse(ALL(a));
		// (*this).Remove0(b[0]=='-' ? -1 : 1);
	// }
// 	
	// Bigint(string x) {(*this)=x;}
	// Bigint(ll x) {(*this)=to_string(x);}
	// void operator =(ll x){*this=to_string(x);}
// 	
	// char operator[](int i){ return a[i];}
	// int size(){ return a.size();}
	// Bigint inverseSign(){ sign *= -1; return (*this);}
// 	
	// bool operator == (Bigint x) {return sign==x.sign && a==x.a;}
	// bool operator == (string x) {return *this==Bigint(x);}
	// bool operator !=(Bigint x) { return !(*this==x);}
// 	
	// Bigint Remove0(int newSign){
		// sign = newSign;
		// for(int i =a.size()-1; i>=0 && a[i] == '0'; i--) a.ppb();
		// if (a.size() == 1 && a[0] == '0') sign = 1;;
		// return (*this);
	// }
// 	
	// bool operator < (Bigint b){
		// if (sign != b.sign) return sign < b.sign;
		// if ((int)a.size() != b.size()) return (int)a.size()*sign < (int)b.size()*sign;
// 		
		// for(int i=a.size()-1; i>=0; i--){
			// if (a[i] != b[i]) return a[i]<b[i];
		// }
		// return false;
	// }
// 	
	// Bigint operator - ( Bigint b ) {
		// if(sign != b.sign) return (*this)+b.inverseSign();
		// if(*this < b) return (b - *this).inverseSign();
		// Bigint sub;
		// for(int i=0,borrow=0; i<(int)a.size(); i++) {
			// borrow = a[i]-borrow-(i<b.size() ? b.a[i] : '0');
			// sub.a += borrow>=0 ? borrow+'0' : borrow + 58;
			// borrow = borrow>=0 ? 0:1;
		// }
		// return sub.Remove0(sign);
	// }
// 	
	// Bigint operator +(Bigint b){
		// if (sign != b.sign) return (*this)-b.inverseSign();
		// Bigint sum;
		// for(int i=0, carry=0; i<(int)a.size() || i < (int)b.size() || carry; i++){
			// if (i<(int)a.size()) carry += a[i]-'0';
			// if (i<(int)b.size()) carry += b[i]-'0';
			// sum.a += (carry%10 + 48);
			// carry /= 10;
		// }
		// return sum.Remove0(sign);
	// }
// 	
	// Bigint operator *(Bigint b){
		// Bigint mult("0");
		// for(int i=0, k=a[i]; i<(int)a.size(); i++, k=a[i]){
			// while(k-- -'0') mult = mult+b;
			// b.a.insert(b.a.begin(),'0');
		// }
		// return mult.Remove0(sign * b.sign);
	// }
// };
// 
vi g[maxn];
ll m;
ld d[maxn];
ll pv[maxn];
ll mx=0;

void init(){
	fore(i,0,maxn) d[i] = inf;
}

void daikra(){
	priority_queue < pair <ld, ll>, vector < pair <ld, ll> >, greater < pair <ld, ll> > > pq;
	d[1] = log2(1);
	pq.push({d[1],1});
	pv[1] = 1;
	while(sz(pq)){
		auto [w,node] = pq.top();
		
		pq.pop();
		
		if (abs(d[node]-w) > eps) continue;
		
		for(auto &signode : g[node]){
			ld sigw = log2(signode);
			if (d[node] + sigw < d[signode]){
				d[signode] = d[node] + sigw;
				pv[signode] = node;
				pq.push({d[signode], signode});
			}
		}
	}
}

int main(){
    fast;
    cin >> m;
    init();
    fore(i,0,m){
    	ll x,y;
    	cin >> x >> y;
    	mx = max({mx,x,y});
    	g[x].pb(y);
    }
    
    daikra();
    
    ll node = mx;
    vi res;
    while(node != 1){
    	res.pb(node);
    	node = pv[node];
    }
    res.pb(1);
    reverse(ALL(res));
    
    for(auto &elm : res) cout << elm << " ";
    cout << nl;
    
    return 0;
}