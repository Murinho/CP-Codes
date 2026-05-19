#include <bits/stdc++.h>
#define ll long long
#define pb push_back

#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define pi pair<int,int>
#define f first
#define s second

using namespace std;

int n;

int v[1005];

vector<pi>res;

void lol(){
    res.pb({n-2,n-3});
    int aux=v[n-4];
    for(int i=n-4;i<n-1;i++)v[i]=v[i+1];
    v[n-1]=aux;
}

void op(int a, int b){
    res.pb({b+1,a+1});
    int aux1=v[b];
    int aux2=v[b+1];
    int aux3=v[b+2];

    for(int i=b+2;i>a+2;i--)v[i]=v[i-3];

    v[a]=aux1;
    v[a+1]=aux2;
    v[a+2]=aux3;
}

void cyc(){
    res.pb({n-4,n-2});
    res.pb({n-3,n-4});
    res.pb({n-3,n-4});
    swap(v[n-1],v[n-3]);
    swap(v[n-2],v[n-3]);
}

void crc(){
    res.pb({n-3,n-2});
    res.pb({n-4,n-3});
    res.pb({n-4,n-2});
    res.pb({n-4,n-3});
    cyc();
}

int main(){
    fast;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>v[i];
        v[i]--;
    }

    for(int j=0;j<n-3;j++){
        int p=j;
        for(int k=j;k<n;k++)if(v[k]==j)p=k;

        while(p>n-3){
            p--;
            lol();
        }

        if(p==j)continue;

        op(j,p);
    }

    int t=n-3;

    for(int i=n-3;i<n;i++)if(v[i]==n-3)t=i;

    while(t!=n-3){
        t--;
        cyc();
    }

    if(v[n-1]!=n-1)crc();

    cout << res.size()<<"\n";
    for(auto v:res){
        cout << v.f << " "<< v.s<<"\n";
    }
}