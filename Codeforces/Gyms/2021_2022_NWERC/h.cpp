#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector<ll>
#define pii pair <ll,ll>
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(),a.end()
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define i128 __int128_t
#define ppb pop_back
#define fst first
#define snd second

using namespace std;

const ll inf = 1e18;
const ll maxn = 5e6+100;

ll n,a[maxn],lef[maxn],rig[maxn];
i128 pref[maxn];
ll ans = inf;

void prefsums(){
    pref[0] = 0;
    fore(i,1,3*n + 1) pref[i] = pref[i-1] + a[i];
}

void precalc_left(){
    vector <pii> v; // monotonic stack.
    lef[0] = 0;
    v.pb({a[0],0});
    fore(i,1,3*n + 1){
        int l = 0;
        int r = sz(v)-1;
        while(l < r){
            ll mid = (l+r+1)/2;
            if (v[mid].fst > a[i]*2) l = mid;
            else r = mid-1;
        }
        lef[i] = v[l].snd;

        while(sz(v) && v.back().fst <= a[i]){
            v.ppb();
        }
        v.pb({a[i],i});
    }
}

void precalc_right(){
    vector <pii> v; // monotonic stack.
    rig[3*n + 1] = 3*n + 1;
    v.pb({a[3*n + 1],3*n + 1});
    rofe(i,3*n + 1,1){
        int l = 0;
        int r = sz(v)-1;
        while(l < r){
            ll mid = (l+r+1)/2;
            if (v[mid].fst > a[i]*2) l = mid;
            else r = mid-1;
        }
        rig[i] = v[l].snd;

        while(sz(v) && v.back().fst <= a[i]){
            v.ppb();
        }
        v.pb({a[i],i});
    }
}

void solve(ll inipos){
    ll res = a[inipos];
    ll sum = a[inipos]*2;
    ll l = inipos;
    ll r = inipos;
    ll sl = inipos;
    ll sr = inipos;
    ll cnt = 1;
    while(cnt < n){
        ll newl = lef[l]+1;
        if (newl < sl){
            sum += pref[sl-1] - pref[newl-1];
            cnt += (sl-newl);
            sl = newl;
        }
        ll newr = rig[r]-1;
        if (sr < newr){
            sum += pref[newr] - pref[sr];
            cnt += (newr-sr);
            sr = newr;
        }

        if (cnt >= n) break;

        if (a[lef[l]] <= a[rig[r]]){
            res += max(0ll,a[lef[l]]-sum);
            sum = max(sum + a[lef[l]], a[lef[l]] * 2);
            l = lef[l];
            sl = l;
            cnt++;
        }
        else{
            res += max(0ll, a[rig[r]]-sum);
            sum = max(sum + a[rig[r]], a[rig[r]] * 2);
            r = rig[r];
            sr = r;
            cnt++;
        }

        //cout << l << " " << r << " " << sl << " " << sr << " " << cnt << " " << sum << ": " << res << nl;
    }

    //cout << inipos - n << " " << res << nl;
    ans = min(ans,res);
}

int main(){
    fast;
    cin >> n;
    a[0] = inf;
    fore(i,1,n+1){
        cin >> a[i];
        a[i+n] = a[i + (2*n)] = a[i];
    }
    a[3*n + 1] = inf;

    prefsums();
    precalc_left();
    precalc_right();

    //cout << "lefts: " << nl;
    //fore(i,n+1, 2*n + 1) cout << i << ": " << lef[i] << nl;
    //cout << "rights: " << nl;
    //fore(i,n+1, 2*n + 1) cout << i << ": " << rig[i] << nl;

    //solve(n+4);
    //return 0;
    fore(i,n+1,2*n + 1){
        solve(i);
    }

    cout << ans << nl;
    return 0;
}

/*
20 23 7 2 3 7 1
lefts:
8: 0
9: 0
10: 9
11: 10
12: 10
13: 9
14: 13
rights:
8: 22
9: 22
10: 15
11: 13
12: 13
13: 15
14: 15
10 11 10 12 3 14: 2
10 13 10 13 4 14: 2
10 15 10 15 6 40: 7
4 7
*/