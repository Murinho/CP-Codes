#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pi pair<int,int>
#define f first
#define s second
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define ld long double

using namespace std;

const ll maxn = 5005;

ld ex[5005][55];

int t[55], pn[55];
ld p[55];

int main(){
    fast;

    int n,r,m;
    cin >> n >> r >> m;

    for(int i=0;i<m;i++){
        cin>> t[i+1] >> p[i+1] >> pn[i+1]; 
    }

    t[0]=0;

    for(int i=m;i>=0;i--){
        if(i==m){
            for(int j=0;j<5005;j++){
                if(j <= r + t[m] - n){
                    ex[j][m]=n-t[m];
                } else {
                    ex[j][m]=1e18;
                }
            }
        } else {
            for(int j=0;j<5005;j++){
                if(j <= r + t[i] - n){
                    int l=t[i+1]-t[i];

                    ex[j][i]=ex[j + l][i+1]+l;
                    ex[j][i]+=(1.0-p[i+1])*(ld)(l)/p[i+1];

                    ld aux=0;

                    aux=p[i+1]*(ex[j+l][i+1] + l) + (1.0 - p[i+1])*(l+pn[i+1]+ex[pn[i+1]+j][i+1]);

                    ex[j][i]=min(ex[j][i],aux);

                } else {
                    ex[j][i]=1e18;
                }
            }
        }
    }

    cout<< fixed << setprecision(8) << ex[0][0]<<"\n";
    return 0;
}