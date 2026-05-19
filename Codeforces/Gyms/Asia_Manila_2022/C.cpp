#include <bits/stdc++.h>
#define pi pair<int,int>
#define f first
#define s second
#define ll long long
#define pb push_back
#define ll long long
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'

using namespace std;

const int C=2e5+5;

int n,k;
int g[C];

int ap[C];

int main(){
    fast;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>g[i];
        
    }
    map<int,int>m;
    int v=1;
    for(int i=0;i<n;i++){
        if(m[g[i]]==0){
            m[g[i]]=v;
            v++;
        }
    }

    for(int i=0;i<n;i++)g[i]=m[g[i]];

    for(int j=0;j<k;j++){
        for(int i=1;i<=n;i++)ap[i]=0;
        for(int i=0;i<n;i++)ap[g[i]]++;

        bool lol=1;

        for(int i=0;i<n;i++){
            if(g[i]!=ap[g[i]]){
                lol=0;
                g[i]=ap[g[i]];
            }
        }
        if(lol)break;
    }

    for(int i=0;i<n;i++)cout<<g[i]<<" ";

    return 0;
}