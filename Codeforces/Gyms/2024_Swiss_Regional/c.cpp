#include<bits/stdc++.h>
#define nl '\n'
#define ll long long
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define ALL(a) a.begin(), a.end()
#define vi vector<ll>
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
using namespace std;
const int M=1e9+7;

const ll maxn = 1e5+100;

ll n,q,a[maxn];
ll st;

void init(){
    st = 1;
}

// primeros k/2 impares los elimino.
// primeros k/2 pares los reverseo

// solo imprimir los ultimos cnt_impar - sum_k/2 impares.
// 


void solve(){
    cin >> n >> q;
    init();

    fore(i,1,n+1){
        cin >> a[i];
    }

    fore(i,1,q+1){
        ll k;
        cin >> k;
        vi v;
        fore(j,st,st+k){
            if ((j-st+1)%2 == 0) v.pb(a[j]);
        }
        st += k/2;

        reverse(ALL(v));

        int pos = 0;
        fore(j,st,st+(k/2)) a[j] = v[pos++];
    }

    fore(i,st,n+1) cout << a[i] << " " ;
    cout << nl;
    return;
}
int main(){
    fast;
    ll tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}