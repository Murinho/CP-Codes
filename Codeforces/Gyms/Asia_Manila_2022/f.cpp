#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ll long long
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector<ll>
#define vvi vector<ll>
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define sz(a) ((ll)a.size())
#define nl '\n'
#define fst first
#define snd second
#define pii pair <ll,ll>

using namespace std;

const ll maxn = 2e5+100;

set <ll> lk;
set <pii> st;
ll a[maxn],n,sum=0;

void modify(ll &mid, ll cur){
    st.erase({a[cur],cur});
    a[cur] += mid;
    sum += mid;
    st.insert({a[cur],cur});
}

void prop(pii tar){
    // propagate to left and right:
    auto it = lk.find(tar.snd);

    ll mid = tar.fst/2;

    //cout << "mid prop: " << mid << nl;

    if (mid > 0){
        if (it != lk.begin()){
            ll ant = *prev(it);
            modify(mid,ant);
        }
        if (next(it) != lk.end()){
            ll ne = *next(it);
            modify(mid,ne);
        }
    }
    
    // erase from the linked list
    sum -= tar.fst;
    st.erase(tar);
    lk.erase(tar.snd);
}

void print(){
    cout << "--------------" << nl;
    for(auto &elm : lk){
        cout << a[elm] << " " << elm << nl;
    }
    return;
}

int main(){
    fast;
    cin >> n;
    fore(i,1,n+1){
        cin >> a[i];
        lk.insert(i);
        st.insert({a[i],i});
        sum += a[i];
    }

    fore(i,1,n){
        pii p = *st.rbegin();
        pii tar;
        if (sum - p.fst < p.fst){ // tomar el pequeno
            tar = *st.begin();
        }
        else{
            auto it = st.lower_bound({p.fst,-1});
            tar.fst = (*it).fst;
            tar.snd = (*it).snd;
        }
        cout << tar.snd << " " << tar.fst << nl;
        prop(tar);
    }

    pii tar = *st.begin();
    cout << tar.snd << " " << tar.fst << nl;
    return 0;
}