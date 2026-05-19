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

int a[26];
string s;
ll ans=0;

int main(){
    fast;
    freopen("concatenation.in", "r", stdin);  
    freopen("concatenation.out", "w", stdout);
    cin >> s;
    
    fore(i,1,sz(s)){
        int val = (int)(s[i]-'a');
        a[val]++;
    }

    ans = sz(s);
    cin >> s;
    ans *= sz(s);
    fore(i,0,sz(s)-1){
        int val = (int)(s[i]-'a');
        ans -= a[val];
    }
    cout << ans << nl;
}