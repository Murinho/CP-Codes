#include<bits/stdc++.h>
#define pb push_back

using namespace std;

int n;
vector<int> m;

int vis[725];

int main(){
    cin>>n;

    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        m.pb(2*y+360);
    }

    for(int i=0;i<n;i++){
        int u=m[i], v=m[(i+1)%n];

        if(u>v)swap(u,v);

        if(v-u==360){
            cout << "yes";
            return 0;
        }
        if(v-u < 360){
            for(int j=u;j<=v;j++)vis[j]=1;
        }
        else{
            for(int j=0;j<=u;j++)vis[j]=1;
            for(int j=v;j<720;j++)vis[j]=1;
        }
    }

    for(int i=0;i<720;i++){
        if(vis[i]==0){
            cout << "no " << (i<360? "-":"") <<(abs(i-360))/2 << (i%2 ?  ".5" : ".0")<<"\n";
            return 0; 
        }
    }

    cout << "yes\n";

    
}