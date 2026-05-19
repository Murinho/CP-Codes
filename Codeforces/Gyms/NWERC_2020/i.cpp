#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define pb push_back
#define vi vector <ll>
#define vvi vector<vi>
#define pii pair <ll,ll>
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(), a.end()

using namespace std;

const ll maxn = 410;

ll n,d[maxn],t[3][maxn],dp[3][maxn][maxn];
ll res[3];

void init(){
    fore(i,0,3) res[i] = -1;
}

void precalc(){
    fore(i,0,3){
        fore(j,0,n){
            ll cnt = 0;
            ll pos = j;
            ll tm = 0;
            while(cnt < n){
                dp[i][j][pos] = tm; // tiempo de entrada.
                tm += t[i][pos]; // tiempo que permanezco
                tm += d[pos]; // tiempo que me toma llegar al siguiente.
                pos = (pos+1)%n;
                cnt++;
            }
        }
    }
}   

bool good(ll p1, ll st1, ll p2, ll st2){
    ll t1 = 0;
    ll t2 = 0;
    fore(i,0,n){
        ll l = dp[p1][st1][i];
        ll r = dp[p1][st1][i] + t[p1][i] - 1;
        ll l2 = dp[p2][st2][i];
        ll r2 = dp[p2][st2][i] + t[p2][i] - 1;

        if ((l <= l2 && l2 <= r) || (l <= r2 && r2 <= r) || (l2 <= l && l <= r2) || (l2 <= r && r <= r2)) return false;
    }
    return true;
}   

void process(ll p1, ll p2, ll p3){
    fore(i,0,n){
        int pos = (i+1)%n;
        int r2 = -1;
        while(pos != i){
            if (good(p1,i,p2,pos)){
                r2 = pos;
                break;
            }
            pos = (pos+1)%n;
        }

        if (r2 == -1) continue;

        int r3 = -1;
        pos = (pos+1)%n;

        while(pos != i){
            if (good(p2,r2,p3,pos)){
                r3 = pos;
                break;
            }
            pos = (pos+1)%n;
        }

        if (r3 == -1) continue;

        if (good(p1,i,p3,r3)){
            res[p1] = i;
            res[p2] = r2;
            res[p3] = r3;
            break;
        }
    }
    return;
}

int main(){
    fast;
    init();
    cin >> n;
    fore(i,0,n) cin >> d[i];
    fore(i,0,3){
        fore(j,0,n) cin >> t[i][j];
    }

    precalc();

    vi v = {0,1,2};
    do{
        process(v[0],v[1],v[2]);
        if (res[0] != -1){
            break;
        }
    }while(next_permutation(ALL(v)));

    if (res[0] == -1) cout << "impossible" << nl;
    else{
        fore(i,0,3) cout << res[i]+1 << " ";
        cout << nl;
    }
    return 0;
}