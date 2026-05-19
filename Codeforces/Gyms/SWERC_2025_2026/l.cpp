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

const ll maxn = 5e5+100;
const ll M = 1e9+9;
const ll B = 131;
const ll alpha = 26;
const ll inf = 1e9+7;

ll n,q;
string s;
ll pws[maxn],h[maxn],a[maxn];
vi ids[alpha+2];
ll st[4*maxn][alpha+1];
ll sum[maxn][alpha+2],las[maxn][alpha+2];

void init(){
    fore(i,0,4*n + 5){
        fore(j,1,alpha+1) st[i][j] = inf;
    }

    fore(i,0,n){
        a[i] = inf;
        fore(j,1,alpha+1) las[i][j] = -1;
    }
}

ll conv(char &c){
    return (c-'a'+1);
}

bool sameHash(int l1, int len1, int l2, int len2){
    int r1 = l1 + len1;
    int r2 = l2 + len2;
    ll h1 = (h[r1]-h[l1]*pws[len1]%M + M)%M;
    ll h2 = (h[r2]-h[l2]*pws[len2]%M + M)%M;
    return h1 == h2;
}

void precalc(){
    pws[0] = 1;
    fore(i,1,maxn) pws[i] = (pws[i-1]*B)%M;
    h[0] = conv(s[0]);
    fore(i,0,n) h[i+1] = ((h[i]*B)+conv(s[i]))%M;
}

ll maxfreq(ll &l, ll &r){
    ll mx = 0;
    fore(i,1,alpha+1){
        mx = max(mx,sum[r][i] - (l > 0 ? sum[l-1][i] : 0));
    }
    return mx;
}

void build(int node, int ini, int fin){
    if (ini == fin){
        ll x = conv(s[ini]);
        st[node][x] = a[ini];
        // cout << "build: " << ini << ": " << a[ini] << nl;
        return;
    }
    int mid = (ini+fin)/2;
    build(2*node,ini,mid);
    build(2*node + 1,mid+1,fin);
    fore(i,1,alpha+1) st[node][i] = min(st[2*node][i], st[2*node + 1][i]);
}

ll query(int node, int ini, int fin, ll &l, ll r, ll &let){
    if (fin < l || r < ini) return inf;
    if (l <= ini && fin <= r) return st[node][let];
    int mid = (ini+fin)/2;
    return min(query(2*node,ini,mid,l,r,let), query(2*node + 1,mid+1,fin,l,r,let));
}

int main(){
    fast;
    cin >> n >> q;
    cin >> s;
    init();
    precalc();

    // put the letters in their respective position.
    fore(i,0,n){
        int x = conv(s[i]);
        ids[x].pb(i);
        sum[i][x] = 1;
        las[i][x] = i;
    }

    // sweep the prefix sums of letters and the last appearances of each letter
    fore(i,1,n){
        fore(j,1,alpha+1){
            sum[i][j] += sum[i-1][j];
            if (las[i][j] == -1) las[i][j] = las[i-1][j];
        }
    }

    // fore(j,1,3){
    //     fore(i,0,n) cout << sum[i][j] << " ";
    //     cout << nl;
    // }

    // calculate similitude between adjacent ones.
    fore(i,1,alpha+1){
        fore(j,1,sz(ids[i])){
            int l = 1;
            int r = n-ids[i][j];
            while(l < r){
                int mid = (l+r+1)/2;
                if (sameHash(ids[i][j-1],mid,ids[i][j],mid)) l = mid;
                else r = mid-1;
            }
            a[ids[i][j-1]] = l;
        }
    }

    build(1,0,n-1);

    // process the queries
    while(q--){
        ll l,r;
        cin >> l >> r;
        l--, r--;
        ll mx = maxfreq(l,r);

        //cout << l << ", " << r << ": " << mx << nl;
        ll ans = 0;
        if (mx == 1){
            cout << r-l+1 << nl;
            continue;
        }

        fore(i,1,alpha+1){
            if (sum[r][i]-(l > 0 ? sum[l-1][i] : 0) == mx && las[r][i] != -1){
                ll dif = r - las[r][i] + 1;
                ll qans = inf;
                if (l <= las[r][i]-1) qans = query(1,0,n-1,l,las[r][i]-1,i);
                //cout << i << " " << l << " " << las[r][i]-1 << " " << dif << " " << qans << nl;
                ans = max(ans,min(dif,qans));
            }
        }

        cout << ans << nl;
    }
    return 0;
}