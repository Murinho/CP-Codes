// Problem: G. Turning Red
// Contest: Codeforces - 2023 ICPC World Finals
// URL: https://codeforces.com/gym/105255/problem/G
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
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
#define i128 __int128_t
 
using namespace __gnu_pbds;
using namespace std;

const ll maxn = 4e5+100;
const ll inf = 1e9+7;

vi button[maxn]; // this vectors have light.
vi light[maxn]; // this vectors have buttons.
bool vis_button[maxn];
vector <char> og,color;
ll n,k;

void init(){
	og.resize(n+1);
	color.resize(n+1);
}

bool check_immutable(){
	fore(i,1,n+1){
		if (sz(light[i]) == 0 && og[i] != 'R') return false;
	}
	return true;
}

bool check(set <ll> &st_lights){
	for(auto &light_id : st_lights){
		if (color[light_id] != 'R') return false;
	}
	return true;
}

void dfs(ll button_id, set <ll> &st_buts, set <ll> &st_lights){ // discover the lights
	st_buts.insert(button_id);
	for(auto &light_id : button[button_id]){
		st_lights.insert(light_id);
		for(auto &sig_button_id : light[light_id]){
			if (!st_buts.count(sig_button_id)) dfs(sig_button_id,st_buts,st_lights);
		}
	}
}

void create_copy(set <ll> &st_buttons, set <ll> &st_lights){
	for(auto &light_id : st_lights){
		color[light_id] = og[light_id];
	}
	for(auto &button_id : st_buttons){
		vis_button[button_id] = false;
	}
}

void press_button(ll &button_id){
	for(auto &light_id : button[button_id]){
		if (color[light_id] == 'R') color[light_id] = 'G';
		else if (color[light_id] == 'G') color[light_id] = 'B';
		else color[light_id] = 'R';
	}
}

ll bfs(ll start_button_id){
	queue <pii> q; // keep the current button and any previous light.
	vis_button[start_button_id] = true;
	for(auto &light_id : button[start_button_id]){
		for(auto &sig_button_id : light[light_id]){
			if (!vis_button[sig_button_id]){
				vis_button[sig_button_id] = true;
				q.push({sig_button_id, light_id});
			}
		}
	}
	
	ll ret = 0;
	
	while(sz(q)){
		auto [button_id, light_id] = q.front();
		q.pop();
		
		if (color[light_id] == 'G'){
			ret += 2;
			press_button(button_id);
			press_button(button_id);
		}
		else if (color[light_id] == 'B'){
			ret++;
			press_button(button_id);
		}
		
		for(auto &sig_light_id : button[button_id]){
			for(auto &sig_button_id : light[sig_light_id]){
				if (!vis_button[sig_button_id]){
					vis_button[sig_button_id] = true;
					q.push({sig_button_id, sig_light_id});
				}
			}
		}
	}
	return ret;
}

int main(){
    fast;
    cin >> n >> k;
    ll ans = 0;
    init();
    fore(i,1,n+1) cin >> og[i];
    
    fore(i,1,k+1){
    	ll amou;
    	cin >> amou;
    	fore(j,0,amou){
    		ll x;
    		cin >> x;
    		button[i].pb(x); // storing the id of the light.
    		
    		light[x].pb(i); // storing the id of the button.
    	}
    }
    
    // First check, immutable lights:
    if (!check_immutable()){
    	cout << "impossible" << nl;
    	return 0;
    }
    
    fore(i,1,k+1){
    	if (!vis_button[i]){
    		set <ll> st_buttons, st_lights;
    		dfs(i,st_buttons,st_lights);
    		
    		ll minic = inf;
    		fore(j,0,3){
    			create_copy(st_buttons, st_lights);
    			fore(x,0,j){
    				press_button(i);
    			}
    			ll ret = bfs(i);
    			if (check(st_lights)){
    				minic = min(minic, ret + j);
    			}
    		}
    		for(auto &elm : st_buttons){
    			vis_button[elm] = true;
    		}
    		if (minic == inf){
    			cout << "impossible" << nl;
    			return 0;
    		}
    		ans += minic;
    		//cout << "ans: " << ans << nl;
    	}
    }
    cout << ans << nl;
    return 0;
}