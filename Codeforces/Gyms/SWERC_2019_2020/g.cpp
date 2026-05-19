#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define sz(a) ((ll)a.size())
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair <ll,ll>
#define ppb pop_back
#define ALL(a) a.begin(), a.end()

using namespace std;

const ll maxn = 1e5+100;
const ll maxs = 205;

bool cmp(string &a, string &b){
    fore(i,0,min(sz(a),sz(b))){
        if (a[i] < b[i]) return true;
        else if (a[i] > b[i]) return false;
    }
    if (sz(a) < sz(b)) return true;
    return false;
}

ll s,n,k,a[maxn];
bool amigos[maxs][maxs];
bool used[maxn];
map <string,ll> mp;
vi poss[maxs];
vector <string> v;
ll estorbo_cnt[maxn];

void convertir_animales(){
    v.resize(s);
    for(auto &elm : v) cin >> elm;

    sort(ALL(v),cmp);

    ll cnt = 0;
    for(auto &elm : v){
        mp[elm] = cnt;
        cnt++;
    }
}

void construir_amigos(){
    fore(i,0,k){
        string x,y;
        cin >> x >> y;
        int u = mp[x];
        int v = mp[y];
        amigos[u][v] = amigos[v][u] = true;
    }
}

int checar_candidatura(){
    fore(i,0,s){
        if (estorbo_cnt[i] == 0 && sz(poss[i]) > 0) return i;
    }
    return -1;
}

void construir_poss(){
    fore(i,1,n+1){
        string aux;
        cin >> aux;
        a[i] = mp[aux];
    }

    fore(i,1,n+1){
        poss[a[i]].pb(i);
    }

    fore(i,0,s){
        reverse(ALL(poss[i]));
    }
}

void calc_estorbo(int ini, int fin, int who){
    fore(i,ini,fin+1){
        if (used[i]) continue;
        if (!amigos[who][a[i]]) estorbo_cnt[who]++;
    }
}

void poner_animal(int who){
    int cur = poss[who].back();
    poss[who].ppb();
    used[cur] = true;

    fore(i,0,s){
        if (!amigos[who][i]) estorbo_cnt[i]--;
    }
    if (sz(poss[who])){
        int nx = poss[who].back();
        calc_estorbo(cur+1,nx,who); // quien le estorba a who en [cur+1,nx].
    }
}

void init(){
    fore(i,0,s) amigos[i][i] = true;
}

int main(){
    fast;
    cin >> s >> k >> n;
    init();
    convertir_animales();
    construir_amigos();
    construir_poss();

    fore(i,0,s) calc_estorbo(1,poss[i].back(),i);

    fore(i,1,n+1){
        int who = checar_candidatura();
        cout << v[who] << " ";
        poner_animal(who);
    }
    cout << nl;
    return 0;
}