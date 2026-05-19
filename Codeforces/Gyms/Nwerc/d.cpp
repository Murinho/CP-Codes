#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(),a.end()
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define nl '\n'
#define ppb pop_back
#define ld long double

using namespace std;

const int n = 7;
const int m = 24;

int d,h;
char a[n][m];
vvi combs;

void dfs(int curi, vi &path){
    if (sz(path) == d){
        combs.pb(path);
        return;
    }

    fore(i,curi,n){
        path.pb(i);
        dfs(i+1,path);
        path.ppb();
    }
}

bool have(ll &target, vi &v){
    for(auto &elm : v){
        if (target == elm) return true;
    }
    return false;
}


int main(){
    fast;
    fore(i,0,n){
        fore(j,0,m) cin >> a[i][j];
    }

    cin >> d >> h;

    vi path;
    dfs(0,path);

    ld ans = 0.0;

    for(auto &comb : combs){
        vi v;
        fore(i,0,m){ //columnas.
            ll cnt = 0;
            fore(j,0,n){ // filas
                if (have(j,comb) &&  a[j][i] == '.') cnt++;
            }
            v.pb(cnt);
        }
        sort(ALL(v));
        reverse(ALL(v));

        // escoger los h mas grandes:
        ll cnt = 0;
        fore(i,0,h){
            cnt += v[i];
        }
        ld aux = (ld)(cnt)/(ld)(d*h);
        
        ans = max(ans,aux);
    }

    cout << fixed << setprecision(9) << ans << nl;
    return 0;
}