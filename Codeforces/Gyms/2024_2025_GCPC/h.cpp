#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; ++i)
#define rofe(i,a,b) for(ll i=a-1;i>=b; i--)
#define ALL(u) u.begin(),u.end()
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first 
#define snd second

using namespace std;

const int MAXN = 1e6+10;
const int M = 1e9+9;
const int B = 131;
const int alphabet = 30;

//unordered_map<char, int> to[MAXN];
ll to[MAXN][alphabet]; 
string a[MAXN];
ll lnk[MAXN],endlink[MAXN],balance[MAXN];
ll ahonode[MAXN],que[MAXN],pws[MAXN],leaf[MAXN];
int ahosz=1;
pii edges[MAXN];

int getval(char &c){
    return (int)(c-'a');
}

int add_str(string s, int id) {
    int v = 0;
    for(char c: s) {
        int val = getval(c);
        if(!to[v][val]) to[v][val] = ahosz++;
        v = to[v][val];
    }
    leaf[v]++;
    return v; //return the index of the leaf.
}
void push_links() {
    queue<int> q({0});
    while(!q.empty()) {
        int v = q.front(); q.pop();
        fore(i,0,alphabet){ //iterar to[v][i]
            int j = lnk[v];
            int u = to[v][i];
            if (u == 0) continue;
            while(j && !to[j][i]) j=lnk[j];
            if (to[j][i] && to[j][i] != u) lnk[u]=to[j][i];
            endlink[u] = leaf[lnk[u]]>0?lnk[u]:endlink[lnk[u]];
            q.push(u);
        }
    }
}

bool walk(string &s){
    int v=0;
    ll balan=0;
    fore(i,0,sz(s)) {
        int val = getval(s[i]);
        while(v && !to[v][val]) v=lnk[v];
        if(to[v][val]) v=to[v][val]; 
        for(int u=v;u;u=endlink[u]){
            balan += balance[u];
        }  
    }
    if (balan%M ==0) return true;
    return false;
}


int main(){
    fast;
    string s="$";
    int n,m,k;
    cin>>n>>m>>k;
    cin.ignore();
    fore(i,1,n+1){
        getline(cin,a[i]);
        replace(ALL(a[i]),' ',char('z'+1));
        ahonode[i] = add_str(a[i],i);
    }
    fore(i,1,m+1){
        cin>>edges[i].fst>>edges[i].snd;
    }

    //precalculate powers:
    pws[0]=B;
    fore(i,1,m+1) pws[i] = (pws[i-1]*B)%M;

    //Add the balances to the nodes:
    fore(i,1,m+1){
        int x = edges[i].fst;
        int y = edges[i].snd;
        balance[ahonode[x]] += (M-pws[i]);
        balance[ahonode[x]] %= M;
        balance[ahonode[y]] += pws[i];
        balance[ahonode[y]] %= M;
    }
    push_links();

    cin.ignore();
    fore(i,0,k){
        string art;
        getline(cin,art);
        replace(ALL(art),' ',(char)('z'+1));
        if(walk(art)) cout<<"yes"<<nl;
        else cout<<"no"<<nl;
    }
    return 0;
}