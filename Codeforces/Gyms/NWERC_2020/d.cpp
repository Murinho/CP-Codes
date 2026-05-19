#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pi pair<int,int>
#define f first
#define s second
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)



using namespace std;

void find() {
    int x,y;
    ll d;
    x=5e5, y=5e5;

    cout<<x <<" "<<y<<"\n";
    cout.flush();
    cin>>d;

    while(d){

        int u=sqrt(d);

        pi dic[4];
        dic[0].f=max(x-u,0);
        dic[0].s=y;

        dic[1].f=min(x+u,(int)1e6);
        dic[1].s=y;

        dic[2].s=max(y-u,0);
        dic[2].f=x;

        dic[3].s=min(y+u,(int)1e6);
        dic[3].f=x;
    
        ll tam[4];

        for(int i=0;i<4;i++){
            cout<<dic[i].f <<" "<<dic[i].s<<"\n";
            cout.flush();
            cin>>tam[i];

            if(tam[i]<d){
                d=tam[i];
                x=dic[i].f;
                y=dic[i].s;
            }
            if(d==0)return;
        }
    }
}

int main(){
    fast;
    
    int n;
    cin>>n;

    for(int i=0;i<n;i++)find();
    
    return 0;
}