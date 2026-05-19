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
 
const ll maxn = 1e6+10;
 
int n,z[maxn],kmp[maxn];
string s;

void z_function(){
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r){
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]){
            z[i]++;
        }
        if (i + z[i] - 1 > r){
            l = i, r = i + z[i] - 1;
        }
    }
}

void kmp_function(){ 
    for(int i=1; i<n; i++){
        int j = kmp[i-1];
        while(j!=0 && s[i] != s[j]){
            j = kmp[j-1];
        }
        if(s[i] == s[j]) j++;
        kmp[i] = j;
    }
}

int main(){
    fast;
    cin>>s;
    n = sz(s);
    z_function();
    kmp_function();
    fore(i,0,n) cout<<z[i]<<" ";
    cout<<nl;
    fore(i,0,n) cout<<kmp[i]<<" ";
    cout<<nl;
    return 0;
}