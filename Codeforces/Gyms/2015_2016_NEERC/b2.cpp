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

const ll maxn = 1e5+2;

char a[maxn][2];
ll b,w,cnt=0;
char c1 = '@';
char c2 = '.';

int main(){
    fast;
    freopen("black.in", "r", stdin);  
    freopen("black.out", "w", stdout);
    cin >> b >> w;
    
    if (b > w){
        swap(c1,c2);
    }
    fore(i,1,min(b,w)){
        cnt++;
        a[cnt][0] = a[cnt][1] = c1;
        cnt++;
        a[cnt][0] = a[cnt][1] = c2;
    }
    cnt++;
    a[cnt][0] = a[cnt][1] = c1;
    ll dif = abs(w-b)+1;
    fore(i,0,dif){
        cnt++;
        a[cnt][0] = c2;
        a[cnt][1] = c1;
        cnt++;
        a[cnt][0] = a[cnt][1] = c1;
    }

    cout << 2 << " " << cnt << nl;
    fore(j,0,2){
        fore(i,1,cnt+1) cout << a[i][j];
        cout << nl;
    }
    return 0;
}