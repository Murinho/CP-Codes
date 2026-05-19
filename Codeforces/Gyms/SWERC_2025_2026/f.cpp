#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define ALL(a)  a.begin(),a.end()
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define nl '\n'

using namespace std;

const ll maxn = 1005;

ll n,a[maxn];
set <ll> st;
bool ok=false;

void init(){
    ok = false;
    st.clear();
}

void solve(){
    init();
    cin >> n;
    fore(i,1,n+1) cin >> a[i];

    fore(i,2,n+1){
        if (a[i]-a[i-1] > 0){
            st.insert(a[i]-a[i-1]);
        }
        else ok=true;
    }

    if (sz(st) >= 2 || ok){
        fore(i,2,n+1){
            if (a[i] <= a[i-1]){
                ll nval = a[i];
                ll pv = nval-1;
                //cout << "here: ";
                cout << a[i-1]/pv << nl;
                return;
            }
        }
    }
    else{
        //cout << "hereee: ";
        ll d = a[n]/(a[n]-a[n-1]);
        ll ans = max(a[n]/d, d);
        cout << ans << nl;
    }
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