#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; ++i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector <vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second

using namespace std;

const ll INF = 1e18;
const ll maxn = 510;
const ll maxlen = 1e6+10;
const ll M = 1e9+9;
const ll B = 131;

string a[maxn][maxn],res[maxn];
ll sols[maxn],n,tam,pws[maxlen],h[maxlen][2],ah[4];
bool ok=true;

ll conv(char c){
    return (c-'a'+1);
}

void precalc(string s, int idx){
    h[0][idx] = conv(s[0]);
    fore(i,0,tam) h[i+1][idx] = ((h[i][idx]*B)+conv(s[i]))%M;
}

ll getHash(int l, int r, int idx){
    int len = r-l+1;
    return (h[l+len][idx]-h[l][idx]*pws[len]%M + M)%M;
}

void solve2(){
    ll ans=0,cpos;
    if (sz(a[1][2]) != sz(a[2][1])){
        cout<<"NONE"<<nl;
        return;
    }
    //precalc the powers:
    pws[0]=1;
    tam = sz(a[1][2]);
    fore(i,1,maxlen) pws[i] = (B * pws[i-1])%M;

    //precalc hashings:
    precalc(a[1][2],0);
    precalc(a[2][1],1);

    //cout<<getHash(0,1,0)<<" "<<getHash(1,2,0)<<nl;

    fore(i,1,tam){
        ah[0]=getHash(0,i-1,0);
        ah[1]=getHash(i,tam-1,0);
        ah[2]=getHash(0,tam-i-1,1);
        ah[3]=getHash(tam-i,tam-1,1);
        if (ah[0] == ah[3] && ah[1] == ah[2]){
            ans++;
            cpos=i;
        }
    }
    if (ans==0) cout<<"NONE"<<nl;
    else if (ans == 1){
        cout<<"UNIQUE"<<nl;
        fore(i,0,cpos) cout<<a[1][2][i];
        cout<<nl;
        fore(i,cpos,tam) cout<<a[1][2][i];
        cout<<nl;
    }
    else cout<<"MANY"<<nl;
    return;
}

bool check(int p1, int p2){
    int len1 = sols[p1];
    int len2 = sols[p2];
    if (len1 + len2 != sz(a[p1][p2])) return false;
    string s1="",s2="";
    fore(i,0,len1) s1 += a[p1][p2][i];
    fore(i,len1,len1+len2) s2 += a[p1][p2][i];
    if (s1 != res[p1] || s2 != res[p2]) return false;
    return true;
}

void solvegen(){
    ok=true;
    sols[1] = (sz(a[1][2]) + sz(a[1][3]) - sz(a[2][3]))/2;
    fore(i,2,n+1){
        ll len = sz(a[1][i]);
        sols[i] = len-sols[1];
    }
    fore(i,1,n+1) if (sols[i] <= 0) ok=false;
    if (!ok){
        cout<<"NONE"<<nl;
        return;
    }
    //get the string answers:
    fore(i,1,n+1) res[i]="";
    int idx=1;
    fore(i,1,n+1){
        if (i==1) idx=2;
        else idx=1;
        fore(j,0,min(sz(a[i][idx]),sols[i])) res[i] += a[i][idx][j];
    }
    //check the strings match in all concats:
    fore(i,1,n+1){
        fore(j,1,n+1){
            if (i == j) continue;
            if (!check(i,j)) ok=false;
        }
    }
    if (!ok) cout<<"NONE"<<nl;
    else{
        cout<<"UNIQUE"<<nl;
        fore(i,1,n+1) cout<<res[i]<<nl;
    }
    return;
}

int main() {
    fast;
    cin>>n;
    fore(i,1,n+1) fore(j,1,n+1) cin>>a[i][j];

    if (n == 2) solve2();
    else solvegen();
}