#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
const int maxn = 1e5;

ll d[maxn];
vll vadj[maxn];
vll ans;

void dfs(ll x, ll p) {
	//cout << x << endl;
	ans.push_back(x);
	d[x]--;
	for (ll y: vadj[x]) {
		if (y == p) continue;
		dfs(y,x);
		ans.push_back(x);
		d[x]--;
		while (d[y] > 0) {
			
			//cout << y << ' ' << d[y] << endl;
			d[x]--;
			d[y]--;
			ans.push_back(y);
			ans.push_back(x);
		}
	}
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n; cin>>n;
    for (int i=0; i<n; i++) cin>>d[i];
    d[0]++;
    for (int i=0; i<n-1; i++) {
    	ll a,b; cin>>a>>b;
    	vadj[--a].push_back(--b);
    	vadj[b].push_back(a);
    }
    
    dfs(0,0);
    bool se = true;
    for (int i=0; i<n; i++) if (d[i] != 0) se=false;
    
    if (!se) {
    	cout << 0 << '\n';
    	return 0;
    }
    for (size_t i=0; i<ans.size(); i++) cout << ++ans[i] << (i+1 == ans.size() ? '\n': ' ');
}