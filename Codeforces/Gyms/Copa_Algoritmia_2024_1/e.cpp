#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i<b;++i)
#define rofe(i,a,b) for(ll i=a-1;i>=b;--i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define lsbpos(x) __builtin_ffs(x)
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
#define ull unsigned long long
 
using namespace std;

const int N = 1e5+10;
const ull p=257;
char s[N],t[N];
ull pre[N],suff[N],pw[N];

ull pre_hash(int l, int r){
    return pre[r]-pre[l-1]*pw[r-l+1];
}

ull suff_hash(int l, int r){
    return suff[l]-suff[r+1]*pw[r-l+1];
}

bool cmp(int now, int pos1, int pos2){ //pos1 > pos2.
    int len = pos1-now+1;
    int l=1, r=len+1;
    while(l < r){
        int mid = l+r>>1;
        ull h1,h2;
        h1 = suff_hash(pos1-mid+1,pos1);
        if (mid <= pos2-now+1) h2 = suff_hash(pos2-mid+1,pos2);
        else h2 = suff_hash(now,pos2)*pw[mid-(pos2-now+1)]+pre_hash(pos2+1,now+mid-1);
        if (h1 == h2) l=mid+1;
        else r = mid;
    }
    if (l == len+1) return false;
    if (l<=pos2-now+1) return s[pos1-l+1] < s[pos2-l+1];
    return s[pos1-l+1] < s[now+l-1];
}

void solve(){
    scanf("%s",s+1);
    int n =strlen(s+1);
    strcpy(t+1,s+1);
    int l=1;
    sort(t+1,t+n+1);
    for(;l<=n && s[l] == t[l]; ++l);
    if (l == n+1){
        printf("%s\n",t+1);
        return;
    }

    suff[n+1]=0;
    pw[0]=1;
    for(int i=n; i; --i) suff[i]= suff[i+1]*p + s[i];
    fore(i,1,n+1) pw[i] = pw[i-1]*p;
    
    int pos = l;
    fore(i,l+1,n+1) if (cmp(l,i,pos)) pos=i;

    reverse(s+l,s+pos+1);
    printf("%s\n",s+1);
    return;
}

signed main(){
    ll tc;
    cin>>tc;
    while(tc--){ solve();}
}