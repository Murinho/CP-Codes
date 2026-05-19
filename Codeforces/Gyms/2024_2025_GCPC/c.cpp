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

const ll maxn = 4100;
const ll M = 1e9+9;
const ll B = 131;

bool isVar(char c){
    int val = (int)(c-'a');
    if (0 <= val && val <= 25) return true;
    val = (int)(c-'A');
    if (0 <= val && val <= 25) return true;
    return false;
}

string s,t;
ll n,qys,hg[maxn],pws[maxn],hs[maxn][maxn];
vi vars,suf[maxn];

void computeSuffixHashes(){
    fore(i,0,sz(vars)){
        hs[i][0] = suf[i][0];
        fore(j,0,sz(suf[i])){
            hs[i][j+1] = ((hs[i][j]*B)+suf[i][j])%M;
        }
    }
}

void computeSuffixes(){
    fore(i,0,sz(vars)){
        map <char,ll> mp;
        ll id=1;
        fore(j,i,sz(vars)){
            ll pos = vars[j];
            char c = s[pos];
            if (!mp[c]) mp[c]=id, id++;
            suf[i].pb(mp[c]);
        }
    }
    /* Print suffixes 
    cout<<"Suffixes: "<<nl; 
    fore(i,0,sz(vars)){
        fore(j,0,sz(suf[i])) cout<<suf[i][j]<<" ";
        cout<<nl;
    } */
}

ll convChar(char c){
    return (c-'#'+1);
}

void calculatePowers(){
    pws[0]=1;
    fore(i,1,maxn) pws[i] = (pws[i-1]*B)%M;
}

void computeGeneralHash(){ //compute hash of 't' string (with variables as '#')
    hg[0] = convChar(t[0]);
    fore(i,0,sz(t)) hg[i+1] = ((hg[i]*B)+convChar(t[i]))%M;
}

ll getGeneralHash(string qword){
    ll qhash = 0;
    fore(i,0,sz(qword)) qhash = ((qhash*B)+convChar(qword[i]))%M;
    return qhash;
}

ll getVarsHash(vi &qvars){
    ll qhash = 0;
    fore(i,0,sz(qvars)) qhash = ((qhash*B)+qvars[i])%M;
    return qhash;
}

ll getGeneralIntervalHash(ll l, ll r){
    ll len = r-l;
    ll res = (hg[r]-hg[l]*pws[len]%M + M)%M;
    return res;
}

ll getSuffixIntervalHash(int sufid, int l, int r){ //r is exclusive.
    ll len = r-l;
    ll res = (hs[sufid][r]-hs[sufid][l]*pws[len]%M + M)%M;
    return res;
}

int main(){
    fast;
    cin>>n;
    s = ""; //original.
    t = ""; //with variables wildcards.
    fore(i,0,n){
        string word;
        cin>>word;
        if (i>0) s += "_", t += "_";
        s += word;
        if (sz(word) == 1 && isVar(word[0])){
            vars.pb(sz(t));
            t += "#";
        }
        else t += word;
    }
    calculatePowers();
    computeGeneralHash();
    computeSuffixes();
    computeSuffixHashes();
    cin>>qys;
    while(qys--){
        ll k;
        cin>>k;
        string word;
        string qword="";
        vi qvars;
        map <char,ll> mp;
        ll id=1;
        fore(i,0,k){
            ll tam = sz(qword);
            cin>>word;
            if (i>0) qword += "_";
            if (sz(word) == 1 && isVar(word[0])){
                qword += "#";
                char c = word[0];
                if (!mp[c]) mp[c]=id, id++;
                qvars.pb(mp[c]);
            }
            else qword += word;
        }
        ll qhash = getGeneralHash(qword);
        ll qvarshash = getVarsHash(qvars);
        bool ok=false;
        ll sufid=0; //suffix id
        ll varpos = 0; //with respect of positions of vars.
        fore(i,sz(qword),sz(t)+1){
            //Move varpos: 
            while(varpos < sz(vars) && vars[varpos]<i) varpos++;
            
            //First check if general hash matches:
            if (qhash == getGeneralIntervalHash(i-sz(qword),i)){
                int sufstart = 0;
                int sufend = varpos-sufid;
                if (qvarshash == getSuffixIntervalHash(sufid,sufstart,sufend)){
                    ok = true;
                    break;
                }
            }
            if (sufid<sz(vars) && vars[sufid] == i-sz(qword)) sufid++;
        }
        if (ok) cout<<"yes"<<nl;
        else cout<<"no"<<nl;
    }
    return 0;
}