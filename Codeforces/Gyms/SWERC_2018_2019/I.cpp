// Problem: I. Mason's Mark
// Contest: Codeforces - 2018-2019 ICPC Southwestern European Regional Programming Contest (SWERC 2018)
// URL: https://codeforces.com/gym/102465/problem/I
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
#define fst first
#define snd second
#define eb emplace_back
#define ppb pop_back
#define i128 __ll128_t
 
using namespace __gnu_pbds;
using namespace std;

const ll maxn = 2005;

char mat[maxn][maxn];
ll sum[maxn][maxn];
ll n,m;
ll mov[8][2] = {{-1,-1},{-1,0},{-1,+1},{0,-1},{0,+1},{1,-1},{1,0},{1,1}};
bool vis[maxn][maxn];
ll buk[3];

void init(){
	fore(i,0,maxn){
		fore(j,0,maxn) mat[i][j]='.', sum[i][j] = 0;
	}
}

ll get_sum(ll x1, ll y1, ll x2, ll y2){
	if (x1 > x2 || y1 > y2){
		return -1; // wrong input.
	}
	ll ret = sum[x2][y2];
	if (y1 > 0) ret -= sum[x2][y1-1];
	if (x1 > 0) ret -= sum[x1-1][y2];
	if (y1 > 0 && x1 > 0) ret += sum[x1-1][y1-1];
	return ret;
} 

void calc_sum(){
	fore(i,1,maxn){
		ll row = 0;
		fore(j,1,maxn){
			row += (mat[i][j] == '#' ? 1 : 0);
			sum[i][j] = sum[i-1][j] + row;
		}
	}
}

void dfs(ll fil, ll col, ll &tam){
	vis[fil][col]=true;
	tam++;
	
	fore(i,0,8){
		ll sfil = fil + mov[i][0];
		ll scol = col + mov[i][1];
		if (mat[sfil][scol] == '#' && !vis[sfil][scol]){
			dfs(sfil,scol,tam);
		}
	}
	return;
}

void print_sum(){
	fore(i,1,n+1){
		fore(j,1,m+1) cout<<sum[i][j]<<" ";
		cout<<nl;
	}
}

ll getx(ll l, ll r, ll i, ll j){
	while(l < r){
		ll mid = (l+r+1)/2;
		ll ip = i + mid - 1;
		ll jp = j + mid - 1;
		if (get_sum(i,j,ip,jp) == mid*mid) l = mid;
		else r = mid-1;
	}
	return l;
}

ll gety(ll l, ll r, ll i, ll j, ll xdim){
	ll ip = i + xdim - 1;
	while(l < r){
		ll mid = (l+r+1)/2;
		ll jp = j + mid - 1;
		if (get_sum(i,j,ip,jp) == xdim * mid) l = mid;
		else r = mid-1;
	}
	ll ydim = l - (2*xdim);
	return ydim;
}

bool check_a(ll xroot, ll yroot, ll xdim, ll ydim, ll tam){
	// Check filled spaces:
	
	ll hor_len = (2*xdim) + ydim;
	ll ver_len = (3*xdim) + (2*ydim);
	
	// 1: upper horizontal:
	if (get_sum(xroot, yroot, xroot + xdim - 1, yroot + hor_len - 1) != xdim*hor_len) return false;
	
	// 2: middle horizontal:
	if (get_sum(xroot + xdim + ydim, yroot, xroot + (2*xdim) + ydim - 1, yroot + hor_len -1) != xdim*hor_len) return false;
	
	// 3: left vertical:
	if (get_sum(xroot, yroot, xroot + ver_len - 1, yroot + xdim - 1) != xdim*ver_len) return false;
	
	// 4: right vertical:
	if (get_sum(xroot, yroot + xdim + ydim, xroot + ver_len - 1, yroot + hor_len - 1) != xdim*ver_len) return false;
	
	//cout<<"fin filled"<<nl;
	
	// Check the unfilled spaces:
	
	// 5: upper unfilled square.
	if (get_sum(xroot + xdim, yroot + xdim, xroot + xdim + ydim - 1, yroot + xdim + ydim - 1) != 0) return false;
	 
	// 6: lower unfilled square.
	if (get_sum(xroot + (2*xdim) + ydim, yroot + xdim, xroot + ver_len - 1, yroot + xdim + ydim - 1) != 0) return false;
	
	//cout<<"fin unfilled"<<nl;
	// 7: whole square:
	ll cum = get_sum(xroot-1, yroot-1, xroot + ver_len, yroot + hor_len);
	ll cum2 = get_sum(xroot, yroot, xroot + ver_len - 1, yroot + hor_len - 1);
	//cout<<"cum: "<<cum<<nl;
	if (cum != tam || cum2 != tam) return false;
	
	return true;
}

bool check_b(ll xroot, ll yroot, ll xdim, ll ydim, ll tam){
	// Check filled spaces:
	
	ll hor_len = (2*xdim) + ydim;
	ll ver_len = (3*xdim) + (2*ydim);
	
	// 1: upper horizontal:
	if (get_sum(xroot, yroot, xroot + xdim - 1, yroot + hor_len - 1) != xdim*hor_len) return false;
	
	// 2: middle horizontal:
	if (get_sum(xroot + xdim + ydim, yroot, xroot + (2*xdim) + ydim - 1, yroot + hor_len -1) != xdim*hor_len) return false;
	
	// 3: lower horizontal:
	if (get_sum(xroot + (2*xdim) + (2*ydim), yroot, xroot + ver_len - 1, yroot + hor_len - 1) != xdim*hor_len) return false;
	
	// 4: left vertical:
	if (get_sum(xroot, yroot, xroot + ver_len - 1, yroot + xdim - 1) != xdim*ver_len) return false;
	
	// 5: right vertical:
	if (get_sum(xroot, yroot + xdim + ydim, xroot + ver_len - 1, yroot + hor_len - 1) != xdim*ver_len) return false;
	
	//cout<<"fin filled"<<nl;
	
	// Check the unfilled spaces:
	
	// 6: upper unfilled square.
	if (get_sum(xroot + xdim, yroot + xdim, xroot + xdim + ydim - 1, yroot + xdim + ydim - 1) != 0) return false;
	 
	// 7: lower unfilled square.
	if (get_sum(xroot + (2*xdim) + ydim, yroot + xdim, xroot + (2*xdim) + (2*ydim) - 1, yroot + xdim + ydim - 1) != 0) return false;
	
	//cout<<"fin unfilled"<<nl;
	// 8: whole square:
	ll cum = get_sum(xroot-1, yroot-1, xroot + ver_len, yroot + hor_len);
	ll cum2 = get_sum(xroot, yroot, xroot + ver_len - 1, yroot + hor_len - 1);
	//cout<<"cum: "<<cum<<nl;
	if (cum != tam || cum2 != tam) return false;
	
	return true;
}

bool check_c(ll xroot, ll yroot, ll xdim, ll ydim, ll tam){
	// Check filled spaces:
	
	ll hor_len = (2*xdim) + ydim;
	ll ver_len = (3*xdim) + (2*ydim);
	
	// 1: upper horizontal:
	if (get_sum(xroot, yroot, xroot + xdim - 1, yroot + hor_len - 1) != xdim*hor_len) return false;
	
	// 2: lower horizontal:
	if (get_sum(xroot + (2*xdim) + (2*ydim), yroot, xroot + ver_len - 1, yroot + hor_len - 1) != xdim*hor_len) return false;
	
	// 3: left vertical:
	if (get_sum(xroot, yroot, xroot + ver_len - 1, yroot + xdim - 1) != xdim*ver_len) return false;
	
	// Check the unfilled spaces:
	
	// 4: unfilled square.
	if (get_sum(xroot + xdim, yroot + xdim, xroot + (2*xdim) + (2*ydim) - 1, yroot + hor_len - 1) != 0) return false;
	
	//cout<<"fin unfilled"<<nl;
	// 5: whole square:
	ll cum = get_sum(xroot-1, yroot-1, xroot + ver_len, yroot + hor_len);
	ll cum2 = get_sum(xroot, yroot, xroot + ver_len - 1, yroot + hor_len - 1);
	//cout<<"cum: "<<cum<<nl;
	if (cum != tam || cum2 != tam) return false;
	
	return true;
}

void solve(){
	init();
	cin>> m >> n;
	fore(i,1,n+1){
		fore(j,1,m+1){
			cin>>mat[i][j];
		}
	}
	calc_sum();
	//print_sum();
	
	fore(i,1,n+1){
		fore(j,1,m+1){
			if (mat[i][j] == '#' && !vis[i][j]){
				ll tam = 0; //size of the component.				
				dfs(i,j,tam);
				
				ll xdim = getx(1,1005,i,j);
				ll ydim = gety(1,1005,i,j,xdim);
				
				//cout<<"Root: "<<i<<" "<<j<<": ";
				//cout<<xdim<<", "<<ydim<<", tam: "<<tam<<nl;
				
				if (min(xdim,ydim) < 0) break;				
				
				if (check_a(i,j,xdim,ydim,tam)) buk[0]++;
				if (check_b(i,j,xdim,ydim,tam)) buk[1]++;
				if (check_c(i,j,xdim,ydim,tam)) buk[2]++;
			}
		}
	}
	fore(i,0,3) cout<<buk[i]<<" ";
	cout<<nl;
	return;
}

int main(){
    fast;
    ll tc=1;
    while(tc--){
        solve();
    }
}