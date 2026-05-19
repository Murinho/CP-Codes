#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define sz(a) ((ll)a.size())

using namespace std;

const ll maxn = 105;
const int M=1e9+7;

string s1,s2;

string peano(int a){
    if(a==0)return "0";
    else return "S("+peano(a-1)+")";
}

int main(){
    fast;
    cin>>s1>>s2;
    int x=0,y=0;
    for(auto l:s1)if(l=='S')x++;
    for(auto l:s2)if(l=='S')y++;

    string r=peano(x*y);

    cout<<r;

    return 0;
}