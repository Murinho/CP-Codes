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
 
const ll maxn = 1e6+5;
struct state {int len,link;map<char,int> next;}; //clear next!!
state st[maxn];
int sz,last,ans[maxn];
string s;

void sa_init(){
	last=st[0].len=0;sz=1;
	st[0].link=-1;
}
void sa_extend(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}
  
ll f(ll x, vector <ll> &dp){
    if (dp[x] >= 0) return dp[x];
    ll res = 1;
    for(map <char,int>::iterator it=st[x].next.begin(); it!=st[x].next.end(); it++) res += f(it->second,dp);
    dp[x] = res;
    return dp[x];
}

//Finds the total length of different substrings.
ll get_tot_len_diff_substings(){
    ll tot = 0;
    for(int i = 1; i < sz; i++) {
        ll shortest = st[st[i].link].len + 1;
        ll longest = st[i].len;

        ll num_strings = longest - shortest + 1;
        ll cur = num_strings * (longest + shortest) / 2;
        tot += cur;
    }
    return tot;
}

void solve(){
    fore(i,1,sz){
        ll shortest = st[st[i].link].len + 1;
        ll longest = st[i].len;
        ans[shortest]++;
        ans[longest+1]--;
    }

    //Barrido:
    fore(i,1,sz(s)+1) ans[i] += ans[i-1];
}


int main(){
    fast;
    cin>>s;
    int n = sz(s);
    sa_init();
    fore(i,0,n) sa_extend(s[i]);

    solve();
    fore(i,1,n+1) cout<<ans[i]<<" ";
    cout<<nl;
    return 0;
}