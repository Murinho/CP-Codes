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
#define RB(x) (x<n?r[x]:0)
 
using namespace std;
 
const ll maxn = 2e5+10;
const ll B = 241;
const ll M = 1e9+9;
 
void csort(vector<int>& sa, vector<int>& r, int k){
	int n=sa.size();
	vector<int> f(max(255,n),0),t(n);
	fore(i,0,n)f[RB(i+k)]++;
	int sum=0;
	fore(i,0,max(255,n))f[i]=(sum+=f[i])-f[i];
	fore(i,0,n)t[f[RB(sa[i]+k)]++]=sa[i];
	sa=t;
}
vector<int> constructSA(string& s){
	int n=s.size(),rank;
	vector<int> sa(n),r(n),t(n);
	fore(i,0,n)sa[i]=i,r[i]=s[i];
	for(int k=1;k<n;k*=2){
		csort(sa,r,k);csort(sa,r,0);
		t[sa[0]]=rank=0;
		fore(i,1,n){
			if(r[sa[i]]!=r[sa[i-1]]||RB(sa[i]+k)!=RB(sa[i-1]+k))rank++;
			t[sa[i]]=rank;
		}
		r=t;
		if(r[sa[n-1]]==n-1)break;
	}
	return sa;
}
 
string s;
ll h[maxn],p[maxn];
 
ll conv(char c){
    return (c-'a'+1);
}
 
ll getHash(int l, int len){
    ll r = l+len;
    ll ret = (h[r]-h[l]*p[len]%M + M)%M;
    return ret;
}
 
void precalc(){
    p[0]=1;
    fore(i,1,maxn) p[i] = (p[i-1]*B)%M;
 
    h[0] = conv(s[0]);
    fore(i,0,sz(s)){
        h[i+1] = ((h[i]*B)+conv(s[i]))%M;
    }
}   
 
bool firstCheck(){
    string t = s;
    sort(ALL(t));
    fore(i,1,sz(t)) if (t[i] == t[i-1]) return true;
    return false;
}
 
int main() {
    fast;
    cin>>s;
    s = "$" + s;
    precalc();
    
    if (!firstCheck()) cout<<-1<<nl;
    else{
        vector <int> sa = constructSA(s);
        ll stapos = 0, bestlen = -1;
        fore(i,1,sz(sa)){
            if (s[sa[i-1]] != s[sa[i]]) continue;
            int l = 1;
            int r = sz(s) - max(sa[i-1],sa[i]);
            while(l < r && bestlen < r){
                ll mid = (l+r+1)/2;
                ll h1 = getHash(sa[i-1],mid);
                ll h2 = getHash(sa[i],mid);
                if (h1 == h2) l = mid;
                else r = mid-1;
            }
            if (bestlen < r) stapos = sa[i], bestlen = r;
        }
        fore(i,stapos,stapos+bestlen) cout<<s[i];
        cout<<nl;
    }
    return 0;
}
