#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll M=1e9+7;

const ll N=1005;

ll rect(int x, int y){
    ll aux=x;
    aux*=(x+1);
    aux*=(y+1);
    aux*=y;
    aux/=4;
    return aux;
}

ll expo(ll x, ll p=M-2){
    ll res = 1;
    while(p){
        if(p&1) res = (res*x)%M;
        x = (x*x)%M;
        p >>= 1;
    }
    return res;
}



int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,m,k;
    cin>>n>>m>>k;

    ll d = rect(m,n);
    ll res = 0;
    for(ll i=0; i<n; i++){
        for(ll j=i+1; j<=n; j++){
            for(ll u=0; u<m; u++){
                for(ll v=u+1; v<=m; v++){
                    ll s = rect(u,n);
                    s += rect(m-v,n);
                    s += rect(i,m);
                    s += rect(n-j,m);

                    s -= rect(i,u);
                    s -= rect(n-j,u);
                    s -= rect(i,m-v);
                    s -= rect(n-j,m-v);

                    ll aux = s*expo(d);
                    aux %= M;

                    aux = expo(aux,k);
                    aux = (aux-1+M)%M;

                    ll dif = s-d;
                    dif += M;
                    dif %= M;

                    aux *= expo(dif);
                    aux %= M;

                    res += aux;
                    res %= M;
                }
            }
        }
    }
    cout << res << endl;
    return 1<<32;
}