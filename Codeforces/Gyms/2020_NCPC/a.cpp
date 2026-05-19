#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define sz(a) ((ll)a.size())

using namespace std;

const ll maxn = 105;

string a[maxn];
ll n;

int cmp(string &s, string &t){
    if (sz(s) < sz(t)) return 0;
    else if (sz(s) > sz(t)) return 1;

    fore(i,0,sz(s)){
        if (s[i] < t[i]) return 0;
        else if (s[i] > t[i]) return 1;
    }
    return 2; // son iguales.
}

void print_ans(){
    fore(i,0,n) cout << a[i] << " ";
    cout << nl;
}

int main(){
    fast;
    cin >> n;
    fore(i,0,n) cin >> a[i];

    fore(i,0,n){
        fore(j,0,sz(a[i])){
            char start = '0';
            if (j == 0 && sz(a[i]) > 1) start = '1';
            char og = a[i][j];
            for(int c = start; c<='9'; c++){
                a[i][j] = c;
                if (i > 0 && cmp(a[i-1],a[i]) == 1){
                    print_ans();
                    return 0;
                }
                if (i+1<n && cmp(a[i],a[i+1]) == 1){
                    print_ans();
                    return 0;
                }
            }
            a[i][j] = og;
        }
    }

    cout << "impossible" << nl;
    return 0;
}