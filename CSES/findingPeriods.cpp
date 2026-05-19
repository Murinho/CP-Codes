#include <bits/stdc++.h>
#define ll long long
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define nl '\n'
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(u) u.begin(),u.end()
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define lsbpos(x) __builtin_ffs(x)
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second

using namespace std;

const ll maxn = 1e6+5;
const ll M = 1e9+9;
const ll B = 131;

ll n,pws[maxn],h[maxn];
string s;

ll conv(char c){
    return (c-'a'+1);
}

ll getHash(ll l, ll len){
    ll r = l+len;
    ll res = (h[r]-h[r-len]*pws[len]%M + M)%M;
    return res;
}

void precalc(){
    pws[0]=1;
    fore(i,1,maxn) pws[i] = (B*pws[i-1])%M;
    h[0]=conv(s[0]);
    fore(i,0,n) h[i+1] = ((h[i]*B)+conv(s[i]))%M;
}

int main(){
    fast;
    cin>>s;
    n = s.size(); //double the length.
    precalc();
    fore(i,1,n+1){
        bool ok=true;
        ll ch = -1;
        for(ll j = 0; j<n; j += i){
            if (j+i <= n){ //fully in.
                ll res = getHash(j,i);
                if (ch == -1) ch = res;
                else if (ch != res){
                    ok=false;
                    break;
                }
            }
            else{ //partially.
                ll len = n-j;
                ll pref = getHash(0,len);
                ll suf = getHash(j,len);
                if (pref != suf){
                    ok=false;
                    break;
                }
            }
        }
        if (ok) cout<<i<<" ";
    }
    cout<<nl;
    return 0;
}
