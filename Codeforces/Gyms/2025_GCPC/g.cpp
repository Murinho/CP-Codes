#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(), a.end()
#define pii pair <ll,ll>
#define fst first
#define snd second
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'

using namespace std;

const ll alpha = 26;

ll n,cnt=0;


int main(){
    fast;
    cin >> n;
    fore(i,0,alpha){
        if (cnt >= n) break;
        string base = "";
        char c = (char)('a'+i);
        fore(j,0,12) base.pb(c);
        base[0] = '$';
        base[1] = '0';
        base[2] = 'a';
        base[3] = 'A';

        fore(j,0,alpha){
            if (cnt >= n) break;
            if(i == j) continue;

            char d = (char)('a'+j);
            
            for(int k = 5; k<12 && cnt < n; k += 2){
                string res = base;
                res[k-1] = d;
                res[k] = d;
                cout << res << nl;
                cnt++;
            }
        }
    }
    return 0;
}