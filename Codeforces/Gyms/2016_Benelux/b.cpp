#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector<ll>
#define ALL(a) a.begin(),a.end()
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define nl '\n'
#ifdef LOCAL
#define debug(arg) cout << "[" << #arg << "]: " << arg << endl
#else
#define debug(arg) 42
#endif

using namespace std;

int main(){
    fast;

    string aux="RBL";
    sort(aux.begin(),aux.end());

    string s;
    cin>>s;
    
    string ans;

    for(int i=0;i<s.size();i++){
        if(i<s.size()-1){
            string auxi=s.substr(i,3);
            sort(auxi.begin(),auxi.end());
            if(auxi == aux){
                i+=2;
                ans+='C';
                continue;
            }
        }

        switch(s[i]){
            case 'R':{
                ans+='S';
                break;
            }
            case 'B':{
                ans+='K';
                break;
            }
            case 'L':{
                ans+='H';
                break;
            }
        }
    }
    cout<<ans;
    

    return 0;
}