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
 
using namespace std;

const ll maxn = 2e6+5;

ll n,ans = 0;

struct Point{
	ll x,y,id,ap;
};

struct frac{ // we will save the slopes here.
    ll num, den;
    frac(){}
    frac(ll num, ll den):num(num), den(den){ 
        if(!num) den = 1;
        if(num > 0 && den < 0) num = -num,  den = -den;
        simplify(); 
    }
    void simplify(){
        ll g = __gcd(abs(num), abs(den));
        if(g) num /= g,  den /= g;
    }
    frac operator+(const frac& b){ return {num*b.den + b.num*den, den*b.den};}
    frac operator-(const frac& b){ return {num*b.den - b.num*den, den*b.den};}
    frac operator*(const frac& b){ return {num*b.num, den*b.den};}
    frac operator/(const frac& b){ return {num*b.den, den*b.num};}
    bool operator<(const frac& b)const{ return num*b.den < den*b.num; }
    bool operator ==(const frac &b) const { return num == b.num && den == b.den;}
    void print(){ cout<<num<<"/"<<den<<nl; }
};

struct Pfrac{
	ll x,y,id,ap;
	frac f;
};

bool cmp(Pfrac &p1, Pfrac &p2){
	return p1.f < p2.f;
}

vector <Point> p;

void sweep(vector <Pfrac> &pf, ll &res){
	vector<bool> seen(n,false);
	fore(i,0,sz(pf)){
		int pos = i;
		ll sub = 0;
		while(pos < sz(pf) && pf[i].f == pf[pos].f){
			if (!seen[pf[pos].id]){
				res += pf[pos].ap;
				seen[pf[pos].id] = true;
			}
			else{
				//cout<<"Quita: "<<pf[pos].x<<" "<<pf[pos].y<<nl;
				sub += pf[pos].ap;
			}
			pos++;
		}
		ans = max(ans,res);
		res -= sub;
		//cout<<i<<" <-> "<<pos<<nl;
		i = pos-1;
	}
}

void solve(){
	cin>>n;
	fore(i,0,n){
		ll l,r,y;
		cin>>l>>r>>y;
		if (l > r) swap(l,r);
		ans = max(ans,r-l);
		p.pb({l,y,i,r-l});
		p.pb({r,y,i,r-l});
	}
	
	for(auto &pt : p){
		vector <Pfrac> pf;
		for(auto &pt2 : p){
			if (pt2.ap == 0) continue;
			if (pt.y < pt2.y){
				Pfrac pt3;
				frac fr(pt2.y-pt.y,pt2.x-pt.x);
				pt3.x = pt2.x;
				pt3.y = pt2.y;
				pt3.id = pt2.id;
				pt3.ap = pt2.ap;
				pt3.f = fr;
				pf.pb(pt3);
			}
			else if (pt.y > pt2.y){
				Pfrac pt3;
				frac fr(pt.y-pt2.y,pt.x-pt2.x);
				pt3.x = pt2.x;
				pt3.y = pt2.y;
				pt3.id = pt2.id;
				pt3.ap = pt2.ap;
				pt3.f = fr;
				pf.pb(pt3);
			}
		}
		sort(ALL(pf),cmp);
		//cout<<"fixed pt: "<<pt.x<<" "<<pt.y<<nl;
		//for(auto &au : pf) cout<<au.x<<" "<<au.y<<" "<<au.id<<nl;
		ll res = pt.ap;
		sweep(pf,res);
	}
	cout<<ans<<nl;
	return;
}

int main(){
    fast;
    ll tc=1;
    while(tc--){
        solve();
    }
}