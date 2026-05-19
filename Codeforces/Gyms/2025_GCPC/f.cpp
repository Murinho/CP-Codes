#include <bits/stdc++.h>
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

const ll maxn = 2550;

char a[maxn][maxn];
bool vis[maxn][maxn];
ll ans = 0;
ll n,m;
vi d;

void clean(){
    fore(i,0,n){
        fore(j,0,m) vis[i][j] = false;
    }
}

bool check(ll k){
    clean();
    fore(i,0,n){
        fore(j,0,m){
            if (!vis[i][j] && a[i][j] == '#'){
                fore(ii,i,i+k){
                    fore(jj,j,j+k){
                        if (ii >= n || jj >= m) return false;
                        if (vis[ii][jj] || a[ii][jj] == '.') return false;
                        vis[ii][jj] = true;
                    }
                }
            }
        }
    }
    return true;
}

int main(){
    fast;
    cin >> n >> m;
    fore(i,0,n) fore(j,0,m) cin >> a[i][j];

    // recorrer por filas:
    fore(i,0,n){
        ll x = 0;
        fore(j,0,m){
            if (a[i][j] == '.'){
                if (x > 0){
                    if (ans == 0) ans = x;
                    else ans = __gcd(ans,x);
                }
                x = 0;
            }
            else{
                x++;
            }
        }
        if (x > 0){
            if (ans == 0) ans = x;
            else ans = __gcd(ans,x);
        }
    }

    // recorrer por columnas:
    fore(i,0,m){
        ll x = 0;
        fore(j,0,n){
            if (a[j][i] == '.'){
                if (x > 0){
                    if (ans == 0) ans = x;
                    else ans = __gcd(ans,x);
                }
                x = 0;
            }
            else{
                x++;
            }
        }
        if (x > 0){
            if (ans == 0) ans = x;
            else ans = __gcd(ans,x);
        }
    }

    ll sq = sqrt(ans);

    fore(i,1,sq+1){
        if(ans%i == 0){
            d.pb(i);
            if (i*i != ans) d.pb(ans/i);
        }
    }

    sort(ALL(d));
    reverse(ALL(d));
    
    for(auto &elm : d){
        if (check(elm)){
            cout << elm << nl;
            return 0;
        }
    }

    cout << 1 << nl;
    return 0;
}