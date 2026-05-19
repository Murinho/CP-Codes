#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector <ll>
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(a) a.begin(), a.end()
#define fst first
#define snd second
#define pii pair<ll,ll>
#define sz(a) ((ll)a.size())

using namespace std;

const ll maxn = 1e5+100;
ll n,bl[maxn],br[maxn];
vi w[maxn],p[maxn],s[maxn];
ll mxl = 0,ans = 0, totk = 0;
set <pii> toleft,inright;
map <pii,pii> mp; // map a toleft element with an inright element.

int main(){
    fast;
    // read stuff

    cin >> n;
    fore(i,0,n){
        ll k;
        cin >> k >> bl[i] >> br[i];
        mxl = max(mxl,bl[i]);
        w[i].reserve(k);
        totk += k;
        fore(j,0,k){
            ll x;
            cin >> x;
            w[i].pb(x);
        }

        // for this one compute the prefix.
        ll sum = bl[i];
        p[i].pb(sum);
        fore(j,0,k){
            sum += w[i][j];
            p[i].pb(sum);
        }

        // for this one compute the suffix.
        sum = br[i];
        s[i].pb(sum);
        rofe(j,k,0){
            sum -= w[i][j];
            s[i].pb(sum);
        }

        reverse(ALL(s[i]));

        // cout << "pref: ";
        // for(auto &elm : p[i]) cout << elm << " ";
        // cout << nl;
        // cout << "suf: ";
        // for(auto &elm : s[i]) cout << elm << " ";
        // cout << nl;

        // insert the tolefts
        fore(j,1,sz(p[i])){
            toleft.insert({p[i][j],i});
        }

        // insert the inrights
        fore(j,0,sz(s[i])){
            inright.insert({s[i][j],i});
        }

        // make the mappings from the incoming toleft to the must remove inright.
        fore(j,1,sz(p[i])){
            mp[{p[i][j],i}] = {s[i][j-1],i};
        }
    }
    

    // compute the answer:
    fore(i,0,totk){
        pii sm_right = *inright.begin();

        ans = max(ans, sm_right.fst - mxl);

        pii sm_toleft = *toleft.begin();

        ll block_size = sm_toleft.fst - bl[sm_toleft.snd];
        pii del_who = mp[sm_toleft];

        // cout << "sm_toleft: " << sm_toleft.fst << " " << sm_toleft.snd << nl;
        // cout << "blocksize: " << block_size << nl;
        // cout << "del who: " << del_who.fst << " " << del_who.snd << nl;
 
        inright.erase(del_who);
        toleft.erase(sm_toleft);

        bl[sm_toleft.snd] += block_size;

        mxl = max(mxl, bl[sm_toleft.snd]);
    }

    // compute one last time
    pii sm_right = *inright.begin();
    ans = max(ans, sm_right.fst - mxl);

    cout << ans << nl;
    return 0;
}