#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using vll = vector<ll>;

const int maxk = 503; 
const int maxn = 200000 + 5;

ll dp[maxk][maxk];
ll vl[maxn];
ll n,k;

ll calc(ll i, ll j) {
	ll ans = 2; 
	ll a = j;
	for (ll kk = j+1; kk<n; kk++) {
		if (vl[kk] - vl[a] == vl[j]-vl[i]) {
			ans++; 
			a = kk;
		}
	}
	return ans;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin>>vl[i];
	}
	
	
	if (n == 2) {
		cout << 0 << '\n';
		return 0;
	}
	
	for (int i=0; i<=k+1; i++) dp[i][k+2] = calc(i,k+2);
	for (int b=k+1; b>0; b--) {
		for (int a = b-1; a>=0; a--) {
			dp[a][b] = 2;
			for (int c=b+1; c<=k+2; c++) {
				if (vl[c] - vl[b] != vl[b] - vl[a]) continue;
				dp[a][b] = max(1 + dp[b][c], dp[a][b]);
			}
		}
	}
	
	ll ans = 0;
	pll p;
	for (int i=0; i<=k+1; i++) {
		for (int j=i+1; j<=k+2; j++) {
			 if (dp[i][j] > ans) {
			 	ans = dp[i][j];
			 	p.first = i; 
			 	p.second = j;
			 }
		}
	}
	
	if (n - ans > k) {
		cout << -1 << '\n';
		return 0;
	}
	
	ll a = p.first;
	vll sol;
	for (int i=0; i<a; i++) sol.push_back(i);
	
	for (int i=a+1; i<n; i++) {
		if (vl[i] - vl[a] == vl[p.second] - vl[p.first]) a = i;
		else sol.push_back(i);
	}
	assert((int)sol.size() == (n - ans));
	cout << sol.size() << '\n';
	for (size_t i = 0; i<sol.size(); i++) cout << ++sol[i] << (i+1 == sol.size() ? '\n' : ' ');
}