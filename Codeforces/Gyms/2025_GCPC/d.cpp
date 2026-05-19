#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pi pair<int,int>
#define f first
#define s second
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)


using namespace std;

int n;

int main(){
    fast;
    cin >>n;
    int mxx=0, mnx=1e9, mxy=0, mny=1e9;

    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        mxx = max(mxx, x);
        mnx = min(mnx, x);

        mxy = max(mxy, y);
        mny = min(mny, y);

    }

    cout << 4 <<"\n";

    cout<< mnx << " " << mny <<"\n";
    cout<< mxx << " " << mny <<"\n";
    cout<< mxx << " " << mxy <<"\n";
    cout<< mnx << " " << mxy <<"\n";
   
    return 0;
}