#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define vi vector<ll>
#define vvi vector<vi>
#define nl '\n'
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(),a.end()
#define pii pair <ll,ll>
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)

using namespace std;

const int maxn = 1e4+50;

int a[maxn],mp[maxn];
int n;
vector <pii> v;

void init(){
    v.clear(), v.resize(0);
}

void swapy(int l, int mid, int r){
    v.pb({l,r});
    int pos = mid+1;
    fore(i,l,mid+1){
        mp[a[i]] = pos;
        mp[a[pos]] = i;
        swap(a[i],a[pos]);
        pos++;
    }
}

void move(int from, int to){
    while(to < from){
        int dif = (from-to+1);
        if (dif%2){
            int mid = (to+1+from)/2;
            swapy(to+1,mid,from);
            from = mid;
        }
        else{
            int mid = (to+from)/2;
            swapy(to,mid,from);
            from = mid;
        }
    }
}

void solve(){
    cin >> n;
    init();
    fore(i,1,n+1){
        cin >> a[i];
        mp[a[i]] = i;
    }

    fore(i,1,n+1){
        move(mp[i],i);
    }

    cout << sz(v) << nl;
    for(auto &[l,r] : v) cout << l << " " << r << nl;
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