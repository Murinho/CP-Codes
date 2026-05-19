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

const ll maxn = 72;
const ll maxm = 72;

bool seen[maxn*maxm];
int mp[maxn*maxm],a[maxn][maxm];
int n,m;

void init(){
    fore(i,0,maxn*maxm){
        seen[i] = false;
        mp[i] = 0;
    }
}

void solve(){
    cin >> n >> m;
    init();
    fore(i,1,n+1){
        fore(j,1,m+1) cin >> a[i][j];
    }

    if (n == 1){
        fore(j,1,(m/2)+1) cout << a[1][j] << " ";
    }
    else if (n%2 == 0){
        fore(i,1,n+1){
            if (seen[a[i][1]] == false){
                fore(j,1,m+1) cout << a[i][j] << " ";
                seen[a[i][1]] = true;
            }
        }
    }
    else{ // m es par
        // asociar cada inicio de cada arreglo con un numero.
        fore(i,1,n+1){
            mp[a[i][1]] = i;
        }
        int cur = 1;
        fore(j,1,m+1) cout << a[cur][j] << " ";
        
        fore(v,2,n){
            cur = mp[a[cur][(m/2)+1]];
            fore(j,(m/2)+1,m+1) cout << a[cur][j] << " ";
        }
    }
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