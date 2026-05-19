#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector<ll>
#define vvi vector <vi>
#define sz(a) ((ll)a.size())
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define fst first
#define snd second
#define pii pair <ll,ll>
#define nl '\n'

using namespace std;

const ll maxn = 1e4+10;

ll n,k;
ll bt,bc;
ll a[maxn],b[maxn];

void init(){
    bt = -1;
    bc = 1e9+100;
}

int main(){
    fast;
    cin >> n >> k;
    init();
    fore(i,0,n){
        ll x,y;
        cin >> x >> y;
        a[i] = x;
        b[i] = x+y; 
    }

    ll tope = 60*8;
    fore(i,0,tope+1){
        ll cand = 0;
        fore(j,0,n){
            if (b[j] < i) continue; // nada.

            ll lwb = 0;
            if (a[j] <= i){
                lwb = 0;
            }
            else{
                lwb = (a[j]-i)/k;
                if ((a[j]-i)%k) lwb++;
            }

            ll upb = (b[j]-i)/k;

            //cout << i << " " << j << " " << lwb << " " << upb << nl;

            if (lwb <= upb){
                ll dif = (upb-lwb);
                cand += dif+1;
            }
        }
        if (cand < bc){
            bc = cand;
            bt = i;
        }
    }

    cout << bt << " " << bc << nl;
    return 0;
}