#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; ++i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll> 
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second

using namespace std;

const ll maxn = 2e6+10;
const ld eps = 1e-5;

ll n,a,b;
ld e[maxn],k;

int main(){
    fast;
    cin>>n>>a>>b;
    k = (b-a+1);
    e[0] = 0.0;
    fore(i,1,n+1){
        ld sum=0.0;
        if (a>0){
            if (i-a >= 0) sum += e[i-a];
            if (i-b-1 >= 0) sum -= e[i-b-1];
            sum *= (1.0/k);
            sum += 1.0;
        }
        else{
            sum = e[i-1];
            if (i-b-1 >= 0) sum -= e[i-b-1];
            sum *= (1.0/k);
            sum += 1.0;
            sum *= (k/(k-1));
        }
        e[i] += sum;
        e[i] += e[i-1];
    }   
    cout<<fixed<<setprecision(9)<<e[n]-e[n-1]<<nl;
    return 0;
}