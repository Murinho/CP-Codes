#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sz(a) ((ll)a.size())
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define nl '\n'
#define fst first
#define snd second
#define vi vector<ll>
#define pii pair <ll,ll>

using namespace std;

const ll maxn = 2e5+20;

ll n,k,a[maxn],bi,bj,dif,skip,las;
map <pii,bool> mp;
bool ok=false;
vi res;

void build_res(){
    fore(i,0,bi) res.pb(i);
    fore(i,bi+1,bj) res.pb(i);

    las = bj;
    dif = a[bi]-a[bj];
    //cout<<las<<" "<<dif<<nl;
    fore(i,bj+1,n){
        if (a[las]-a[i] == dif) las = i;
        else res.pb(i);
    }
}   

int main(){
    fast;
    cin>>n>>k;
    fore(i,0,n){
        cin>>a[i];
    }
    if (n == 2){
        cout<<0<<nl;
        return 0;
    }
    else if (n == 3){
        if (a[0]-a[1] == a[1]-a[2]) cout<<0<<nl;
        else cout<<-1<<nl;
        return 0;
    }

    fore(i,0,k+1){
        fore(j,i+1,k+2){
            dif = a[i]-a[j];
            if (mp[{i,j}]) continue;
            //cout<<"try: "<<i<<" "<<j<<" --> ";
            mp[{i,j}]=true;
            skip = i + (j-i-1);
            las = j;
            for(ll x = j+1; x<n && skip<=k; x++){
                if (a[las]-a[x] == dif){
                    las = x;
                    if (x <= k+1) mp[{las,x}]=true;
                }
                else skip++;
            }
            //cout<<skip<<nl;
            if (skip <= k){
                bi = i;
                bj = j;
                ok=true;
                break;
            }
        }
        if (ok) break;
    }
    if (ok){
        build_res();
        cout<<sz(res)<<nl;
        for(auto au : res) cout<<au+1<<" ";
        if (sz(res)) cout<<nl;
    }
    else cout<<-1<<nl;
    return 0;
}