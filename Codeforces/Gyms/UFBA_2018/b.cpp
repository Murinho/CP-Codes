#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second


using namespace std;

const ll maxn = 2005;

string a[maxn];
ll n,cur,m;
string s;
map <char,int> mp;
set <ll> st;
bool flag;

void solve(string b){
    string t;
    fore(i,0,n){
        t = "";
        mp.clear();
        set <char> seen;
        cur = 0;
        fore(j,i,n){
            if (sz(t) == m) break;
            if (!mp.count(s[j])){
                if (cur == 2) break;
                mp[s[j]]=cur;
                cur++;
            }
            t += to_string(mp[s[j]]);
        }
        if (sz(t) == sz(b) && cur == 1){
            st.insert(i);
        }
        else if (t == b){
            st.insert(i);
        }
    }
}

void invertBits(string &b){
    fore(i,0,sz(b)){
        if (b[i] == '0') b[i]='1';
        else b[i]='0';
    }
}

int main(){
    fast;
    string b;
    cin>>s;
    cin>>b;
    n = sz(s);
    m = sz(b);
    //Do normal;
    if (b[0] == '1'){
        invertBits(b);
    }
    //cout<<"doing normal with: "<<b<<nl;
    solve(b);

    reverse(ALL(b));
    if (b[0] == '1'){
        invertBits(b);
    }
    //cout<<"doing inverse with: "<<b<<nl;
    solve(b);

    cout<<sz(st)<<nl;
    return 0;
}