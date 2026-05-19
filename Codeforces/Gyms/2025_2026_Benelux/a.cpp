#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(), a.end()
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int main(){
    fast;
    string s;
    cin>>s;

    ld res=0;
    ll C=1;
    int n=s.size();

    for(int i=0;i<n;i++){
        res+=(ld)(s[i]-'0')*(n-i)/C;
        C*=10;
        if(i==18)break;
    }
    res*=0.9;
    ld xd=0;
    for(int i=n-1;i>=0;i--){
        xd+=s[i]-'0';
        xd/=10;
    }

    res+=xd;

    cout << fixed << setprecision(8)<< res;
    

    
}