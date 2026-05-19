#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; ++i)
#define rofe(i,a,b) for(ll i=a-1;i>=b; i--)
#define ALL(u) u.begin(),u.end()
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first 
#define snd second

using namespace std;


string vertical(string s){
    string t="";
    for(auto c : s){
        if (c == 'b') t += "p";
        else if (c == 'p') t += "b";
        else if (c == 'd') t += "q";
        else if (c == 'q') t += "d";
        else t += ".";
    }
    return t;
}

string rotate(string s){
    string t = "";
    rofe(i,sz(s),0){
        if (s[i] == 'b') t += "q";
        else if (s[i] == 'p') t += "d";
        else if (s[i] == 'd') t += "p";
        else if (s[i] == 'q') t += "b";
    }
    return t;
}

string horizontal(string s){
    string t = "";
    rofe(i,sz(s),0){
        if (s[i] == 'b') t += "d";
        else if (s[i] == 'p') t += "q";
        else if (s[i] == 'd') t += "b";
        else if (s[i] == 'q') t += "p";
    }
    return t;
}

string doAllOps(string s, string t){
    for(auto c : t){
        if (c == 'h') s = horizontal(s);
        else if (c == 'v') s = vertical(s);
        else s = rotate(s);
    }
    return s;
}

string s,t;
int f[3];

int main(){
    fast;
    cin>>s;
    cin>>t;
    //string allops = doAllOps(s,t);
    for(auto c : t){
        if (c == 'h') f[0]++;
        else if (c == 'v') f[1]++;
        else f[2]++;
    }
    fore(i,0,3) f[i]%=2;

    for(auto c : t){
        if (c == 'h' && f[0]){
            f[0]--;
            s = horizontal(s);
        }
        else if (c == 'v' && f[1]){
            f[1]--;
            s = vertical(s);
        } 
        else if (c == 'r' && f[2]){
            f[2]--;
            s = rotate(s);
        }
    }
    //cout<<s<<", "<<allops<<nl;
    cout<<s<<nl;
    return 0;
}