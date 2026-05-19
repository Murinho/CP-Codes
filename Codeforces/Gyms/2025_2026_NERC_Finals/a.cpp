#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector <ll>
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(a) a.begin(), a.end()
#define fst first
#define snd second
#define pii pair<ll,ll>

using namespace std;

const int C=2e5+5;

ll lt[26];

ll cp[26];

string s[C];

int main(){
    fast;
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s[i];
        for(auto c:s[i]){
            lt[c-'A']++;
        }
    }


    for(int i=0;i<n;i++){
        
        for(auto c:s[i]){
            lt[c-'A']--;
        }

        for(int i=0;i<26;i++)cp[i]=lt[i]*m;

        for(auto c:s[i]){
            cp[c-'A']--;

        }



        ll r=m;

        for(int i=0;i<26;i++){
            if(lt[i])r=min(r,cp[i]/lt[i]);
            if(cp[i]<0)r=-1;
        }

        for(auto c:s[i]){
            lt[c-'A']++;
        }

        cout << r <<" ";

    }
}