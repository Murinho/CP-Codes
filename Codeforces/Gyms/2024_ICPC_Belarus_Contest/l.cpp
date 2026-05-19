#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sz(a) ((ll)a.size())
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define nl '\n'
#define fst first
#define snd second
#define vi vector<ll>
#define pii pair <ll,ll>

using namespace std;

const ll maxn = 1e5+10;

ll p[5] = {2,2,2,269,7487};
vector < vector <pii> > combs;
ll n,a[maxn];

void dfs(int pos, ll max_color, int color_ins, vi &colors){
    if (pos >= 0) colors.pb(color_ins);

    if (sz(colors) == 5){
        //cout<<"here"<<nl;
        //for(auto au : colors) cout<<au<<" ";
        //cout<<nl;
        map <ll,ll> aux;
        fore(i,0,max_color+1){
            ll num=1;
            fore(j,0,5){
                if (colors[j] == i) num *= p[j];
            }
            if (num>1) aux[num]++;
        }
        vector <pii> v;
        for(auto au : aux) v.pb(au); //{llave, valor};
        combs.pb(v);
    }
    else{
        fore(i,0,max_color+2){
            dfs(pos+1,max(i,max_color),i,colors);
        }
    }
    if (pos >= 0) colors.pop_back();
}

void print_combs(){
    for(auto comb : combs){
        for(auto au : comb) cout<<au.fst<<": "<<au.snd<<nl;
        cout<<"---------"<<nl;
    }
}

int main(){
    fast;
    vi colors;
    dfs(-1,0,0,colors);
    //print_combs();
    //return 0;
    cin>>n;
    map <ll,ll> mp;
    fore(i,0,n){
        ll x;
        cin>>x;
        mp[x]++;
    }
    bool ok;
    for(auto comb : combs){
        ok=true;
        for(auto au : comb){
            if (mp[au.fst] < au.snd){ // la frecuencia siempre debe ser >= a la de la combinacion.
                ok=false;
                break;
            }
        }
        if (ok){
            ll tam=0;
            for(auto au : comb) tam += au.snd;
            cout<<tam<<nl;
            for(auto au : comb){
                fore(i,0,au.snd) cout<<au.fst<<" ";
            }
            cout<<nl;
            return 0;
        }
    }
    cout<<0<<nl;
    return 0;
}


