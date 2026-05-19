#include <bits/stdc++.h>
#define ll long long
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define ld long double
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define pii pair <ll,ll>
#define ALL(a) a.begin(),a.end()
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back

using namespace std;

const ll maxn = 15;
const ll maxk = 32;
const ll B = 131;
const ll M = 10000000000000061;

map <ll,vi> mp;
ll n,k,b[maxn]; 
string a[maxn];  
ll cnt,pw[maxk];
string who;

void precalc(){
    fore(i,0,maxk) pw[i] = (1ll<<i);
}

string getstr(ll mk, ll tam){
    string ret = "";
    fore(i,0,tam){
        if (pw[i]&mk) ret += "1";
        else ret += "0";
    }
    reverse(ALL(ret));
    return ret;
}

void init(){
    cnt = 0;
    mp.clear();
}

void solve(){
    cin >> n >> k;
    init();
    ll mid1 = (k/2); // exclusivo para mitad izquierda.
    fore(i,0,n){
        cin >> a[i] >> b[i];
    }

    bool ok;
    fore(i,0,pw[mid1]){ // each possible mask (mask of correct answers)
        ll ha = 0;
        ok = true;
        //cout << "mk: " << i << nl;
        fore(j,0,n){ // iterate through the exams.
            ll pts = b[j];
            ll pid = 0;
            rofe(x,mid1,0){
                if (pw[pid]&i){ // bit is on, answer should be '1'.
                    if (a[j][x] == '1') pts--;
                }
                else{ // bit is off, answer should be '0'.
                    if (a[j][x] == '0') pts--;
                }
                pid++;
            }
            if (pts < 0){
                ok = false;
                break;
            }
            ha = ((ha*B)+pts+1ll)%M;
        }
        if (ok){
            mp[ha].eb(i);
        }
    }

    ll suflen = k - mid1;
    //cout << "------------------" << nl;
    fore(i,0,pw[suflen]){
        ll ha = 0;
        //cout << "Mk: " << i << nl;
        fore(j,0,n){
            ll pts = 0;
            ll pid = 0;
            rofe(x,k,mid1){
                if (pw[pid]&i){ // bit is on, answer should be '1'.
                    if (a[j][x] == '1') pts++;
                }
                else{ // bit is off, answer should be '0'.
                    if (a[j][x] == '0') pts++;
                }
                pid++;
            }
            ha = ((ha*B)+pts+1ll)%M;
        }
        //cout << "Check: " << ha << nl;
        for(auto &mk : mp[ha]){
            if (cnt == 0){
                who = getstr(mk,mid1);
                who += getstr(i,suflen);
            }
            cnt++;
        }
    }
    if (cnt == 1) cout << who << nl;
    else cout << cnt << " solutions" << nl;
    return;
}


int main(){
    fast;
    ll tc;
    precalc();
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}