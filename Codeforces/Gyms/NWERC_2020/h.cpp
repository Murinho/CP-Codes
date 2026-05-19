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

ll n;
vi a;

int main(){
    fast;
    cin >> n;
    a.resize(n);

    for(auto &elm : a) cin >> elm;

    sort(ALL(a));

    ll mid = n/2;

    // 5/2 = 2, [0,4]
    // 4/2 = 2, [0,3]
    int l = mid - 1;
    int r = mid;

    ll cnt = 0;
    while(cnt < n){
        if (cnt%2 == 0){
            cout << a[r] << " ";
            r++;
        }
        else{
            cout << a[l] << " ";
            l--;
        }
        cnt++;
    }
    cout << nl;
    return 0;
}