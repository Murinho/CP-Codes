#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define ALL(a)  a.begin(),a.end()
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define nl '\n'

using namespace std;
const int C=6e5+5;
int n,k;
int a[C];

void solve(){
    cin>>n>>k;

    for(int i=0;i<=3*n;i++)a[i]=0;

    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        a[p]++;
    }
    stack<int>aux;

    int res=0;

    for(int j=3*n;j>0;j--){
        if(a[j]<=k && a[j]!=1){
            aux.push(j);
            continue;
        }
        int p=j;

        while(a[p]>k){
            int tp = aux.top();
            aux.pop();
            a[tp]+=a[p]-1;
            a[p]=1;
            p=tp;
        }

        if(a[p]<=k && a[p]!=1){
            aux.push(p);
        }

        res=max(res,p-j);
    }
    cout << res <<"\n";
}

int main(){
    fast;

    int t;
    cin>>t;
    while(t--)solve();
    
    return 0;
}