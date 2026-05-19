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

int n;
int res[105][105];

bool que(vector<int>p){
    vector<int>aux[31];

    int pr = p[0];

    for(auto v:p){
        v--;
        if(v<pr)continue;
        cout << "? " << pr <<" "<<v<<endl;
        cout.flush();
        int ra;
        cin>>ra;
        ra++;
        if(ra<0)return 1;

        aux[ra].pb(v+1);
        res[pr][v]=ra-1;
    }

    for(int i=0;i<31;i++)for(int j=i+1;j<31;j++){
        for(auto a:aux[i])for(auto b:aux[j]){
            if(b<a) res[b][a-1]=j-1;
            else res[a][b-1]=j-1;
        }
    }

    for(int i=0;i<31;i++){
        if(aux[i].size()){
            if(que(aux[i]))return 1;
        }
    }

    return 0;

}

bool solve(){
    cin>>n;
    if(n==-2)return 1;

    vector<int>nmms;
    for(int i=1;i<=n+1;i++)nmms.pb(i);

    if(que(nmms))return 1;

    cout << "! \n";
    for(int i=1;i<=n;i++){
        for(int j=0;j+i<=n;j++)cout<<res[i][j+i]<<" ";
        cout <<endl;
        cout.flush();
    }

    return 0;
}



int main(){
    fast;

    int t;
    cin>>t;
    while(t--){
        if(solve())break;
    }
    
    return 0;
}