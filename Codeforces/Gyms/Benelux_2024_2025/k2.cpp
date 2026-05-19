#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fore(i,a,b) for(ll i = a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'
#define pii pair <ll,ll>
#define vi vector<ll>
#define vvi vector<vi>
#define fst first
#define snd second
#define sz(a) ((ll) a.size())
#define ALL(a) a.begin(),a.end()
#define ppb pop_back

using namespace std;

const ll M = 1e9+7;
const ll B = 131;

const ll maxn = 5010;
const ll maxsub = 1255; //should be: 12502500

ll pws[maxn],h[maxn],tam[maxsub],seen[maxsub],pv[maxsub];
string s;
ll n;

ll conv(char c){
    return (c-'a'+1);
}

bool getHash(int l1, int len1){
    int r1 = l1 + len1;
    cout<<l1<<" "<<r1<<nl;
    ll h1 = (h[r1]-h[l1]*pws[len1]%M + M)%M;
    cout<<"this h1: "<<h1<<nl;
    return h1;
}

void precalc(){
    cout<<"n: "<<n<<nl;
    pws[0] = 1;
    fore(i,1,maxn){
        pws[i] = (pws[i-1]*B)%M; 
        if (i <= 10){
            cout<<i<<": "<<pws[i]<<nl;
        }
    }

    // Main hash.
    h[0] = conv(s[0]);
    cout<<0<<": "<<h[0]<<nl;
    fore(i,0,n){
        h[i+1] = ((h[i]*B)+conv(s[i]))%M;
        cout<<i+1<<": "<<h[i+1]<<nl;
    }
}

int main(){
    fast;
    cin>>s;
    n = sz(s);
    precalc();
    

    ll tha = getHash(1,3);
    cout<<"here: "<<getHash(1,3)<<nl;
    cout<<"other: "<<getHash(2,4)<<nl;
    return 0;

    // get all the different substrings.
    ll cnt = 0;
    fore(i,0,n){
        string t = "";
        fore(j,i,n){
            t += s[j];
            ll ha = getHash(i,j-i+1);
            //cout<<"this: "<<ha<<nl; 
        }
    }
}