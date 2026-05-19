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

string s,ans;
int n,best=maxn;
set <char> st;

void reloadSet(){
    st.insert('A');
    st.insert('G');
    st.insert('C');
    st.insert('T');
}

void solve(char stc){
    string t = "";
    reloadSet();
    int pos = 0;
    while(pos < n && s[pos] != stc) pos++;
    if (pos < n) t += stc;
    while(pos < n){
        if (st.count(s[pos])){
            st.erase(s[pos]);
            if (!sz(st)){
                t += s[pos];
                reloadSet();
            }
        }
        pos++;
    }
    if (st.count(stc)) t += stc;
    else t += *st.begin();
    if (sz(t)<best){
        best = sz(t);
        ans = t;
    }
}

int main(){
    fast;
    cin>>s;
    n = sz(s);
    solve('A');
    solve('C');
    solve('G');
    solve('T');
    cout<<ans<<nl;
    return 0;
}