#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(int i=a; i<b; i++)
#define rofe(i,a,b) for(int i=a-1; i>=b; i--)
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
 
const int maxn = 2e4+1;
const int maxk = 30;
 
int n,k,a[maxn],p[maxk],ans,val;
char c;

void precalc(){
    p[0]=1;
    fore(i,1,maxk) p[i] = (p[i-1]*2);
}

int main(){
    fast;
    cin>>n>>k;
    precalc();
    ans = k;
    fore(i,0,n){
        rofe(j,k,0){
            cin>>c;
            if (c == '1') a[i] += p[j];
        }
    }
    fore(i,0,n){
        fore(j,i+1,n){
            val = (a[i]^a[j]);
            ans = min(ans,__builtin_popcount(val));
        }
        if (ans == 0) break;
    }
    cout<<ans<<nl;
    return 0;
}