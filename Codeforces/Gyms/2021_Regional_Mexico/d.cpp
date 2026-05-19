#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector<ll>
#define vvi vector <vi>
#define sz(a) ((ll)a.size())
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define fst first
#define snd second
#define pii pair <ll,ll>
#define nl '\n'

using namespace std;

int main(){
    fast;

    int n;
    cin>>n;

    set<int>a;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;

        while(a.count(x)){
            a.erase(x);
            x++;
        }
        a.insert(x);
    }

    if(n==1){
        cout <<"N\n";
        return  0;
    }

    if (a.size()<=2){
        cout <<"Y\n";
    }else {
        cout << "N\n";
    }

    return 0;
}