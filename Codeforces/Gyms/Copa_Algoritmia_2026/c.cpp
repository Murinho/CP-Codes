#include <bits/stdc++.h>
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define pb push_back
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define ALL(a) a.begin(), a.end()
#define sz(a) ((ll)a.size())
#define pii pair<ll,ll>

using namespace std;
const ll MAXN = 1e5;
bool prim[MAXN + 5];

void criba(){

    for(ll i = 2; i<=MAXN; i++){
        prim[i] = true;
    }

    for(ll i = 2; i<=MAXN; i++){
        if(prim[i]){
            for(ll j = i*2; j<=MAXN; j+=i){
                prim[j] = false;
            }
        }
    }
}

int main(){
    fast;
    ll tt; cin>>tt;
    while(tt--){
        ll x; cin>>x;
        if(x%2 == 0 && x != 2){
            if(x != 2)cout<<"First"<<endl;
            else cout<<"Second"<<endl;
            continue;
        }
        ll cont = 0;
        for(ll i = 1; i * i <= x; i++){
            if(x%i == 0){
                cont++;
                if(x/i != i)cont++;
            }
        }

        if(cont == 2){
            if(x == 3)cout<<"First"<<endl;
            else cout<<"Second"<<endl;
        }else{
            ll aux = x;
            while(aux%3 == 0){
                aux/=3;
            }
            if(aux == 1){
                if(x == 9)cout<<"Second"<<endl;
                else cout<<"First"<<endl;
            }else{
                cout<<"First"<<endl;
            }
        }
    }
}