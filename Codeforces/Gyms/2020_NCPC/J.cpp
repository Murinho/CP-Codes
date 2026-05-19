#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define pi pair<int,int>
#define pl pair<ll,ll>
#define f first
#define s second
#define nl '\n'
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define sz(a) ((ll)a.size())

using namespace std;

const ll maxn = 105;
const int M=1e9+7;

int k,q;
ll r,f;
int mi,ma;
pair<ll,pl>g[10];
int d[10];

int main(){
    fast;
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>g[i].f;
        cin>>g[i].s.f>>g[i].s.s;
        mi+=g[i].s.f;
        ma+=g[i].s.s;
    }

    sort(g,g+k);
    reverse(g,g+k);

    for(int i=0;i<k;i++)d[i]=g[i].s.s-g[i].s.f;

    cin>>q;
    for(int i=0;i<q;i++){
        cin>>r>>f;
        if(f<mi || f>ma){
            cout<<"no\n";
            continue;
        }
        int s=mi;
        ll t=0;
        for(int i=0;i<k;i++){
            if(s+d[i]<=f){
                s+=d[i];
                t+=g[i].f*g[i].s.s;
            } else if(s<f){
                t+=g[i].f*(g[i].s.f+f-s);
                s=f;
            } else {
                t+=g[i].f*g[i].s.f;
            }
        }
        if(t<r*f){
            cout<<"no\n";
            continue;
        }


        s=ma;
        t=0;
        for(int i=0;i<k;i++){
            if(s-d[i]>=f){
                s-=d[i];
                t+=g[i].f*g[i].s.f;
            } else if(s>f){
                t+=g[i].f*(g[i].s.s+f-s);
                s=f;
            } else {
                t+=g[i].f*g[i].s.s;
            }
        }

        if(t>r*f){
            cout<<"no\n";
            continue;
        }
        cout<<"yes\n";
    }

    return 0;
}