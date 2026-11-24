#include <bits/stdc++.h>
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define pb push_back
#define ll long long
#define F first
#define S second
#define vi vector<ll>
#define vvi vector<vi>
#define ALL(a) a.begin(), a.end()
#define sz(a) ((ll)a.size())
#define pii pair<ll,ll>

using namespace std;

ll rec(ll A, ll B, ll &cont, vector<pii> &ch, vector<ll> &val, vector<pii> &euler, bool &can){
    if(A == 0 & B == 0)return -1;
    cont++;
    ll ind = cont;
    euler[ind].F = ind;
    if(B&1){
        val[ind] = 2;
        B--;
    }else if(B > 0){
        if(A > 0){
            val[ind] = 1;
            A--;
        }else{
            val[ind] = 2;
            B--;
        }
    }else{
        val[ind] = 1;
        A--;
    }

    ch[ind].F = rec(A/2, (B + 1)/2, cont, ch, val, euler, can);
    ch[ind].S = rec((A + 1)/2, B/2, cont, ch, val, euler, can);
    euler[ind].S = cont;
    return ind;
}

void dfs(ll node, vector<pii> &ch, vector<ll> &val){
    cout<<val[node]<<" "<<ch[node].F + 1<<" "<<ch[node].S + 1<<endl;
    if(ch[node].F > 0)dfs(ch[node].F, ch, val);
    if(ch[node].S > 0)dfs(ch[node].S, ch, val);
}

ll dfs2(ll node, vector<pii> &ch, vector<ll> &val, bool &can){
    ll l = 0, r = 0;
    if(ch[node].F > 0){
        l = dfs2(ch[node].F, ch, val, can);
    }
    if(ch[node].S > 0){
        r = dfs2(ch[node].S, ch, val, can);
    }

    if(abs(l - r) > 1){
        can = false;
    }

    return l + r + val[node];
}

int main(){
    fast;
    ll A, B; cin>>A>>B;
    bool can = true;
    vector<pii> ch(A + B + 5, {-1, -1}), euler(A + B + 5);
    vector<ll> val(A + B + 5, 0);
    ll cont = -1;
    rec(A, B, cont, ch, val, euler, can);

    dfs2(0, ch, val, can);
    if(can){
        dfs(0, ch, val);
    }else{
        cout<<-1<<endl;
    }
}