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
 
using namespace std;

const ll maxn = 205;

struct MinCostMaxFlow {
    static constexpr ll INF = (1LL<<60);
    struct Edge { ll to, rev, cap, cost; };

    ll n;
    vector<vector<Edge>> g;
    vi pot,dist,pv_v,pv_e;

    MinCostMaxFlow(int n=0) { init(n); }
    void init(int n_) {
        n = n_;
        g.assign(n, {});
        pot.assign(n, 0);
        dist.assign(n, 0);
        pv_v.assign(n, -1);
        pv_e.assign(n, -1);
    }

    void addEdge(int u, int v, ll cap, ll cost) {
        Edge a{v, sz(g[v]), cap, cost};
        Edge b{u, sz(g[u]), 0, -cost};
        g[u].pb(a);
        g[v].pb(b);
    }

    // Optional: initialize potentials with Bellman-Ford/SPFA if you might have
    // negative cost edges reachable from s in the *initial* residual graph.
    // If all original costs are >= 0, you can skip this and keep pot=0.
    void initPotentialsSPFA(int s) {
        fill(ALL(pot), INF);
        vector<bool> inq(n, false);
        queue<int> q;
        q.push(s);
        pot[s] = 0;
        inq[s] = true;

        while (sz(q)) {
            int u = q.front(); q.pop();
            inq[u] = false;
            for (auto &e : g[u]) {
                if (e.cap <= 0) continue;
                if (pot[u] + e.cost < pot[e.to]) {
                    pot[e.to] = pot[u] + e.cost;
                    if (!inq[e.to]) {
                        inq[e.to] = true;
                        q.push(e.to);
                    }
                }
            }
        }
        fore(i,0,n) if (pot[i] >= INF/2) pot[i] = 0;
    }

    bool dijkstra(int s, int t) {
        fill(ALL(dist), INF);
        fill(ALL(pv_v), -1);
        fill(ALL(pv_e), -1);

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        dist[s] = 0;
        pq.push({0, s});

        while (!pq.empty()) {
            auto [d,u] = pq.top(); pq.pop();
            if (d != dist[u]) continue;
            for (int ei = 0; ei < sz(g[u]); ei++) {
                const auto &e = g[u][ei];
                if (e.cap <= 0) continue;

                ll rcost = e.cost + pot[u] - pot[e.to];
                ll nd = d + rcost;
                if (nd < dist[e.to]) {
                    dist[e.to] = nd;
                    pv_v[e.to] = u;
                    pv_e[e.to] = ei;
                    pq.push({nd, e.to});
                }
            }
        }

        if (dist[t] >= INF/2) return false;

        fore(v,0,n) if (dist[v] < INF/2) pot[v] += dist[v];

        return true;
    }
    
    pii minCostFlow(int s, int t, ll maxf) {
        ll flow = 0, cost = 0;

        // If you may have negative costs initially, call initPotentialsSPFA(s).
        // If all costs >= 0, you can skip.
        // initPotentialsSPFA(s);

        while (flow < maxf && dijkstra(s, t)) {
            // find bottleneck
            ll add = maxf - flow;
            for (int v = t; v != s; v = pv_v[v]) {
                auto &e = g[pv_v[v]][pv_e[v]];
                add = min(add, e.cap);
            }

            // apply flow + compute real cost along path
            for (int v = t; v != s; v = pv_v[v]) {
                int u = pv_v[v];
                int ei = pv_e[v];
                auto &e = g[u][ei];
                auto &rev = g[v][e.rev];
                e.cap -= add;
                rev.cap += add;
                cost += add * e.cost; // IMPORTANT: use original cost, not reduced
            }

            flow += add;
        }
        return {flow, cost};
    }

    // Convenience wrapper: min-cost max-flow
    pii minCostMaxFlow(int s, int t) {
        return minCostFlow(s, t, INF);
    }
};

ll n,a[maxn][maxn];

int main(){
    fast;
    cin >> n;
    ll src = 2*n;
    ll sink = src + 1;
    MinCostMaxFlow mcmf(sink+1);
    
    fore(i,0,n){
    	fore(j,0,n){
    		cin >> a[i][j];
    		mcmf.addEdge(i,j+n,1,a[i][j]);
    	}
    	mcmf.addEdge(src,i,1,0);
    	mcmf.addEdge(i+n,sink,1,0);
    }
    
    auto [flow, cost] = mcmf.minCostMaxFlow(src,sink);
    
    cout << cost << nl;
    
    // now know how are the connections:
    fore(i,0,n){
    	cout << i+1 << " ";
    	for(auto &au : mcmf.g[i]){
    		if (au.cap == 0){
    			cout << au.to - n + 1 << nl;
    			break;
    		}
    	}
    }
    return 0;
}