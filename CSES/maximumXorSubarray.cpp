#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(int i=a; i<b; i++)
#define rofe(i,a,b) for(int i=a-1; i>=b; i--)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector <vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second
#pragma GCC target("popcnt")
 
using namespace std;

const ll maxn = 2e5+5;
const ll maxk = 30;
 
struct TrieNode{
    TrieNode *l;
    TrieNode *r;
};

struct TrieNode *getNode(void){
    struct TrieNode *ret = new TrieNode;
    ret->l = NULL; //0
    ret->r = NULL; //1
    return ret;
}

void insert(TrieNode *root, string s){
    TrieNode * cur = root;
    rofe(i,sz(s),0){
        if (s[i] == '0'){
            if (!cur->l) cur->l = getNode();
            cur = cur->l;
        }
        else{
            if (!cur->r) cur->r = getNode();
            cur = cur->r;
        }
    }
}

int search(TrieNode *root, string s){
    TrieNode * cur = root;
    ll ret=0;
    rofe(i,sz(s),0){
        if (s[i] == '0'){
            if (cur->l){
                cur = cur->l;
            }
            else{
                cur = cur->r;
                ret += (1<<i);
            }
        }
        else if (s[i] == '1'){
            if (cur->r){
                cur = cur->r;
                ret += (1<<i);
            }
            else cur = cur->l;
        }
    }
    return ret;
}

ll sum[maxk][maxn],n,a[maxn],ans=0,val;
string s="",t="";

int main(){
    fast;
    cin>>n;
    fore(i,1,n+1){
        cin>>a[i];
        ans = max(ans,a[i]);
        fore(j,0,maxk){
            if (((1<<j)&a[i]) == (1<<j)) sum[j][i] = sum[j][i-1]^1;
            else sum[j][i] = sum[j][i-1];
        }
    }

    //Do the insertions and queries.
    TrieNode *root = getNode();
    fore(i,0,maxk) s += "0";
    insert(root,s); //insert zero initially.

    fore(i,1,n+1){
        s = "",t="";
        val=0;
        fore(j,0,maxk){
            if (sum[j][i]==0) s += "1", t += "0";
            else s += "0", val += (1<<j), t += "1";
        }
        //cout<<i<<", val: "<<val<<" need -> "<<s<<nl;
        ll ret = search(root,s);
        //cout<<"myret: "<<ret<<nl;
        ans = max(ans,val^ret);
        insert(root,t);
    }
    cout<<ans<<nl;
    return 0;
}