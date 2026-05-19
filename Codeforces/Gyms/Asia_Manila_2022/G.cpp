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

const int C=4e5+5;

int n,k;
int g[C];

vector<pi>lol;
vector<int>aux;
int res,mx;
int c;

int ap1[C],ap2[C];

int main(){
    fast;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        if(r-l+1>=k){
            res++;
            continue;
        }
        lol.pb({l%k,(r+1)%k});

        aux.pb(l%k);
        aux.pb((r+1)%k);
    }

    sort(aux.begin(),aux.end());

    map<int,int>m;

    int v=1;
    for(auto l:aux){
        if(m[l]==0){
            m[l]=v;
            v++;
        }
    }

    for(auto l:lol){
        if(m[l.f]<m[l.s]){
            ap1[m[l.f]-1]++;
            ap1[m[l.s]-1]--;
            ap2[m[l.f]-1]++;
            ap2[m[l.s]-1]--;
        } else {
            ap1[m[l.f]-1]++;
            ap2[m[l.s]-1]--;
            ap2[m[l.f]-1]++;
        }
    }

    for(int i=0;i<v;i++){
        c+=ap1[i];
        mx=max(mx,c);
    }

    for(int i=0;i<v;i++){
        c+=ap2[i];
        mx=max(mx,c);
    }

    cout<<res+mx;

    return 0;
}