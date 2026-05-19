#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector<ll>
#define ALL(a) a.begin(),a.end()
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define nl '\n'
#define eb emplace_back
#define vvi vector<vi>
#define sz(a) ((ll)a.size())

using namespace std;

const ll maxn = 210;
const ll inf = 1e9;

struct FlowEdge {
	int v, u;
	ll cap, flow = 0;
	FlowEdge(int v, int u, ll cap) : v(v), u(u), cap(cap) {}
};
struct Dinic {
	const ll flow_inf = 1e18;
	vector<FlowEdge> edges;
	vvi adj;
	int n, m = 0;
	int s, t;
	vi level, ptr;
	queue<int> q;
	Dinic(int n, int s, int t) : n(n), s(s), t(t){
		adj.resize(n);
		level.resize(n);
		ptr.resize(n);
	}
	void add_edge(int v, int u, ll cap){ // v -> u
		edges.emplace_back(v, u, cap);
		edges.emplace_back(u, v, 0);
		adj[v].push_back(m);
		adj[u].push_back(m + 1);
		m += 2;
	}
	bool bfs(){
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int id : adj[v]) {
				if (edges[id].cap - edges[id].flow < 1) continue;
				if (level[edges[id].u] != -1) continue;

				level[edges[id].u] = level[v] + 1;
				q.push(edges[id].u);
			}
		}
		return level[t] != -1;
	}
	ll dfs(int v, ll pushed) {
		if (pushed == 0) return 0;
		if (v == t) return pushed;
		for (ll& cid = ptr[v]; cid < adj[v].size(); cid++) {
			int id = adj[v][cid];
			int u = edges[id].u;
			if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1) continue;

			ll tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
			if (tr == 0) continue;
			
			edges[id].flow += tr;
			edges[id ^ 1].flow -= tr;
			return tr;
		}
		return 0;
	}
	ll flow(){ // run the algorithm.
		ll f = 0;
		while (true) {
			fill(ALL(level), -1);
			level[s] = 0;
			q.push(s);
			if (!bfs()) break;
			fill(ALL(ptr), 0);
			while (ll pushed = dfs(s, flow_inf)) {
				f += pushed;
			}
		}
		return f;
	}
};

ll n,a[maxn],b[maxn];

ll dist(ll i, ll j){
    return abs(a[i]-a[j]) + abs(b[i]-b[j]);
}

bool check(ll tope){
    int src = 2*n;
    int sink = 2*n + 1;
    Dinic dinic(2*n + 2,src,sink);
    fore(i,0,n){
        dinic.add_edge(src,i,1);
        dinic.add_edge(i+n,sink,1);
        fore(j,n,2*n){
            if (dist(i,j) <= tope){
                dinic.add_edge(i,j,1);
            }
        }
    }
    ll res = dinic.flow();
    return (res == n);
}

int main(){
    fast;
    cin >> n;
    fore(i,0,2*n){
        cin >> a[i] >> b[i];
    }

    ll src = 2*n;
    ll sink = src + 1;
    Dinic dinic(2*n + 2,src,sink);

    ll l = 0;
    ll r = inf;
    while(l < r){
        ll mid = (l+r)/2;
        if (check(mid)) r = mid;
        else l = mid+1;
    }
    cout << l << nl;
    return 0;
}