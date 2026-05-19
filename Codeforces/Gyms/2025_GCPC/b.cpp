#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll long long
#define pb push_back
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(), a.end()
#define pii pair <ll,ll>
#define fst first
#define snd second
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const ll maxn = 1e5+100;
const ll lzaddneut = 0;
const ll lzsetneut = -1;
const ll neut = 0;
const ll inf = 1e18;

ll n,b,delay,w;
ll d[maxn],t[maxn],p[maxn];

bool check(ll &tope){
    ll pos = 1;
    ll acust = 0;
    while(pos <= n){
        ll pos2 = pos;
        ll acu = acust;
        ll mxb = 0;
        ordered_multiset freqs; // en este multiset mantener las frecuencias.
        ordered_set apps; // en este set mantener las apariciones.

        while(pos2 <= n){
            if (t[pos2] > mxb){ // nuevo maximo.
                acu += p[t[pos2]]-p[mxb]; // sumar las nuevas distancias que recorre el camion.
                mxb = t[pos2];
            }

            ll ook = apps.order_of_key(t[pos2]);
            acu += ((ook*2ll) + 2ll) * w;

            // checar cuantas hay despues y como afectan con el nuevo puesto
            if (ook >= sz(apps) || *apps.find_by_order(ook) != t[pos2]){
                ll aux = sz(freqs) - freqs.order_of_key({t[pos2],inf});
                acu += (aux*2ll*w);
                apps.insert(t[pos2]);
            }

            if (acu > tope) break;

            freqs.insert({t[pos2],pos2});
            pos2++;
        }
        if (pos2 == pos) return false;

        pos = pos2;
        acust += delay;
    }
    return true;
}

ll gauss(ll x){
    return x*(x+1)/2ll;
}

int main(){
    fast;
    cin >> n >> b >> delay >> w;

    ll mxt = 0;
    fore(i,1,b+1) cin >> d[i];
    fore(i,1,n+1){
        cin >> t[i];
        mxt = max(mxt,t[i]);
    }

    // sacar la suma acumulada de las distancias.
    p[0] = 0;
    fore(i,1,b+1) p[i] = p[i-1] + d[i];

    ll l = p[mxt] + (w*2ll);
    ll r = p[n] + (gauss(n)*w*2ll);;
   // cout << l << " " << r << nl;
    while(l < r){
        ll mid = (l+r)/2ll;
        if (check(mid)) r = mid;
        else l = mid+1;
    }

    cout << l << nl;
    return 0;
}