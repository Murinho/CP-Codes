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
 
int main() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++)  // read start time, end time
		cin >> v[i].second >> v[i].first;
	sort(begin(v), end(v));  // sort by end time

	int maxMovies = 0;
	multiset<int> end_times;  // times when members will finish watching movies
	for (int i = 0; i < k; ++i) end_times.insert(0);

	for (int i = 0; i < n; i++) {
		auto it = end_times.upper_bound(v[i].second);
		if (it == begin(end_times)) continue;
		// assign movie to be watched by member in multiset who finishes at time
		// *prev(it)
		end_times.erase(--it);
		// member now finishes watching at time v[i].first
		end_times.insert(v[i].first);
		++maxMovies;
	}

	cout << maxMovies;
}