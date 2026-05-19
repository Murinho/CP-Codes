#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define pb push_back
#define vi vector <ll>
#define vvi vector<vi>
#define pii pair <ll,ll>
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(), a.end()

using namespace std;



int main(){
    fast;
    int n,k;
    cin>>n>>k;

    int d,s;
    cin>>d>>s;

    double v= double(n*d-s*k)/(n-k);

    if(v<0 || v>100){
        cout<<"impossible\n";
    } else {
        cout<<fixed<<setprecision(8)<<v<<"\n";
    }



   
    return 0;
}