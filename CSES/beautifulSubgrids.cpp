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
#pragma GCC target("popcnt")
 
using namespace std;
 
const ll maxn = 3005;
ll n,ans=0,cnt;
bitset<3000> rows[maxn];
string s;   

int main(){
    fast;
    cin>>n;
    fore(i,0,n){
        cin>>s;
        rows[i] = bitset<3000>(s);
    }

    fore(i,0,n){
        fore(j,i+1,n){
            cnt = (rows[i]&rows[j]).count();
            ans += (cnt*(cnt-1))/2;
        }
    }
    cout<<ans<<nl;
    return 0;
}