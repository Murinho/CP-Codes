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
 
using namespace std;

const ll maxn = 2e5+10;

struct Event{
	ll t,p,idx;
};

ll n,a[maxn],mx;
set <ll> st;
vector <Event> e;

void init(){
	fore(i,1,n+1) st.insert(i);
	mx = 0;
}

bool cmp(Event ev, Event ev2){
	if (ev.t == ev2.t) return ev.p < ev2.p;
	return ev.t < ev2.t;
}

int main(){
    fast;
	cin>>n;
	init();
	fore(i,0,n){
		ll x,y;
		cin>>x>>y;
		Event ev;
		ev.t = x, ev.p = 1, ev.idx = i;
		e.pb(ev);
		ev.t = y, ev.p = 2;
		e.pb(ev);
	}
	sort(ALL(e),cmp);
	
	for(auto ev : e){
		if (ev.p == 1){ //start event.
			ll sm = *st.begin();
			st.erase(sm);
			mx = max(mx,sm);
			a[ev.idx] = sm;
		}
		else{ //end event.
			st.insert(a[ev.idx]);
		}
	}
	cout<<mx<<nl;
	fore(i,0,n) cout<<a[i]<<" ";
	cout<<nl;
	return 0;
}