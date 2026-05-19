#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'

using namespace std;

int main(){
    fast;
    int n;
    cin>>n;
    unordered_map<string, int>m;
    string res="NONE";

    for(int i=0; i<n;i++){
        string s;
        cin>>s;
        m[s]++;


        if(2*m[s]>n){
            res=s;
        }

    }

    cout<<res<<"\n";
    return 0;
}