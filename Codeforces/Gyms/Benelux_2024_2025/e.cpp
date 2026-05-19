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
#define ld long double

using namespace std;

const ll inf = 1e18;
ll c1,c2,n;
map <ll,ll> mp;

ll get_val(ll x){
    if (mp.count(x)) return mp[x];
    ll ret;
    cout<<"? "<<x<<nl;
    cout.flush();
    cin>>ret;
    mp[x] = ret;
    return ret;
}

ll eval(ll x){
    ll c3 = get_val(x);
    ll dif = max(c2-c3,c3-c1);
    return dif;
}

ll find_lwb(ll tar){ //has to be some a[x] <= tar.
    ll l = 2;
    ll r = n-1;
    while(l < r){
        ll mid = (l+r+1)/2;
        ll e = get_val(mid);
        if (e <= tar) l = mid;
        else r = mid-1;
    }
    return l;
}

ll find_upb(ll tar){ // has to be some tar <= a[x]
    ll l = 2;
    ll r = n-1;
    while(l < r){
        ll mid = (l+r)/2;
        ll e = get_val(mid);
        if (tar <= e) r = mid;
        else l = mid+1;
    }
    return l;
}

int main(){
    //fast;
    cin>>n;
    cout<<"? 1"<<nl;
    cout.flush();
    cin>>c1;
    cout<<"? "<<n<<nl;
    cout.flush();
    cin>>c2;

    if (n == 3){
        cout<<"! 1 2 3"<<nl;
    }
    else if (c1 == c2){
        cout<<"! 1 2 "<<n<<nl;
    }
    else{
        ll id3;
        ll tar_lwb = (c1+c2)/2;
        ll tar_upb = (c1+c2+1)/2;
        //cout<<"Tar lwb: "<<tar_lwb<<nl;
        //cout<<"Tar upb: "<<tar_upb<<nl;
        ll lo = find_lwb(tar_lwb);
        //cout<<"lo is: "<<lo<<nl;
        ll hi = find_upb(tar_upb);
        //cout<<"hi is: "<<hi<<nl;
        ll e1 = eval(lo);
        ll e2 = eval(hi);
        if (e1 < e2) id3 = lo; //tomar el que minimice max(c2-mp[x],mp[x]-c1) porque esta mas al centro.
        else id3 = hi;
        cout<<"! "<<1<<" "<<id3<<" "<<n<<nl;
    }
    cout.flush();
    return 0;
}