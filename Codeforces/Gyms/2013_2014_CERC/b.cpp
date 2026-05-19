#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define vi vector<ll>
#define vvi vector<vi>
#define nl '\n'
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(),a.end()
#define pii pair <ll,ll>
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)

using namespace std;


ll tc;

vector <string> get_words(string &s){
    vector <string> ret;
    string t = "";
    for(auto &c : s){
        if (c == ' '){
            ret.pb(t);
            t = "";
        }
        else t += c;
    }
    if (sz(t)) ret.pb(t);
    return ret;
}   

void solve(){
    set <string> st;
    vector <string> v;
    string s;
    
    getline(cin,s);
    vector <string> vocab = get_words(s);
    
    while(1){
        string t;
        getline(cin,t);
        if (t == "what does the fox say?") break;

        vector <string> words = get_words(t);
        if (words.size() > 3) break;
        fore(i,2,sz(words)){
            st.insert(words[i]);
        }   
    }

    int cnt = 0;
    for(auto &word : vocab){
        if (!st.count(word)){
            if (cnt > 0) cout << " ";
            cout << word;
            cnt++;
        }
    }
    cout << nl;
    return;
}

int main(){
    fast;
    cin >> tc;
    cin.ignore();
    while(tc--){
        solve();
    }
    return 0;
}