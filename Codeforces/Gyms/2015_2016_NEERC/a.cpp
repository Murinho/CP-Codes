#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(),a.end()
#define fst first
#define snd second

using namespace std;


int main(){
    fast;
    freopen("alex.in", "r", stdin);   // Read input from input.in
    freopen("alex.out", "w", stdout); // Write output to output.out
    cout.precision(10);

    double x,y;
    cin>>x>>y;
    
    double l=0,r=max(x,y);

    while(r-l > 1e-5){

        double mid = (r+l)/2.0;                                                                     

        if((x/3.0 >= mid && y>=mid) || (x/2.0 >= mid && y/2.0 >= mid) || (y/3.0 >= mid && x>=mid)){
            l=mid;
        }
        else{
            r=mid;
        }
    }

    cout << r << nl;
    return 0;
}