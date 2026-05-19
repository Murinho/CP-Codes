#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i<b;++i)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((int)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
 
using namespace std;

const ll maxn = 1005;

struct UF{
    ll pad,tam,ran;
};

UF uf[maxn*maxn];
ll n,m,ans=0,sum[maxn][maxn];
char a[maxn][maxn];

void dosum(){
    fore(i,0,n){
        rofe(j,m,0){
            if (a[i][j] == '*') sum[i][j]=0;
            else sum[i][j] = 1 + (j+1<m ? sum[i][j+1] : 0);
        }
    }
}

int bus(int u){
	if (uf[u].pad!=u) uf[u].pad=bus(uf[u].pad);
	return uf[u].pad;
}

void join(int u ,int v){
	u=bus(u); v=bus(v);
	if (u==v) return; 
	if (uf[u].ran>uf[v].ran){
        uf[v].pad=u;
        uf[u].tam+=uf[v].tam;
    }
	else if (uf[u].ran<uf[v].ran) {
        uf[u].pad=v;
        uf[v].tam+=uf[u].tam;
    }
	else {
        uf[u].pad=v;
        uf[v].ran++;
        uf[v].tam+=uf[u].tam;
    }
	return;
}

void init(){
    fore(i,0,n*m + 2){
        uf[i].pad = i;
        uf[i].ran = 0;
        uf[i].tam = 1;
    }
}

int getIdx(int i, int j){
    return (i*m) + j;
}

int main(){
    fast;
    cin>>n>>m;
    init();
    fore(i,0,n) fore(j,0,m) cin>>a[i][j];

    //return 0;
    dosum();

    //Iterate column by column.
    fore(i,0,m){
        vector < pii > v;
        fore(j,0,n){
            if (sum[j][i]) v.pb({sum[j][i],j});
        }
        sort(ALL(v));
        reverse(ALL(v));

        for(auto elm : v){
            ll h = elm.fst;
            ll row = elm.snd;
            if (0<row && sum[row-1][i] >= h) join(getIdx(row,i),getIdx(row-1,i)); //join with the row up.
            if (row+1<n && sum[row+1][i] >= h) join(getIdx(row,i),getIdx(row+1,i)); // join with the row down.
            ans = max(ans,uf[bus(getIdx(row,i))].tam * h);
        }
    }
    cout<<ans<<nl;
    return 0;
}