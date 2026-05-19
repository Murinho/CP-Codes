#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(),a.end()
#define fst first
#define snd second

using namespace std;

const ll maxn = 105;

ll a[maxn][maxn];

ll p[maxn][maxn][4];

ll n,m,ans=0;

// 0: desde arriba
// 1: desde abajo
// 2: desde la izquierda:
// 3: desde la derecha

int main(){
    fast;
    cin >> n >> m;
    fore(i,1,n+1) fore(j,1,m+1) cin >> a[i][j];

    // 0:
    ll id = 0;
    fore(i,1,m+1){
        fore(j,1,n+1){
            p[j][i][id] = max(p[j-1][i][id], a[i][j]);
        }
    }

    // 1:
    id = 1;
    fore(i,1,m+1){
        rofe(j,n+1,1){
            p[j][i][id] = max(p[j+1][i][id], a[i][j]);
        }
    }

    // 2:
    id = 2;
    fore(i,1,n+1){
        fore(j,1,m+1){
            p[i][j][id] = max(p[i][j-1][id], a[i][j]);
        }
    }

    // 3:
    id = 3;
    fore(i,1,n+1){
        rofe(j,m+1,1){
            p[i][j][id] = max(p[i][j+1][id], a[i][j]);
        }
    }

    fore(i,1,n+1){
        fore(j,1,m+1){
            if (p[i-1][j][0] < a[i][j]) ans++;
            if (p[i+1][j][1] < a[i][j]) ans++;
            if (p[i][j-1][2] < a[i][j]) ans++;
            if (p[i][j+1][3] < a[i][j]) ans++;
        }
    }

    cout << ans << nl;
    return 0;
}