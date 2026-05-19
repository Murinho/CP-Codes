#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
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

const ll maxn = 1e5+5;
const ll maxsum = 304930;
ll n,x,a[maxsum];

void criba(){
    fore(i,1,maxsum){
        for(int j = 2; i*j<maxsum; j++) a[i*j] += i;
    }
}

int main(){
    fast;
    criba();
    cin>>n;
    bool ok;
    while(n--){
        ok=false;
        cin>>x;
        cout<<x;
        if (a[x]==x) cout<<" perfecto";
        else{
            if (a[a[x]] == x) cout<<" romantico", ok=true;
            if (x < a[x]) cout<<" abundante", ok=true;
            if (!ok) cout<<" complicado";
        }
        cout<<nl;
    }
    return 0;
}