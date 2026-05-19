#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sz(a) ((ll)a.size())
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define nl '\n'

using namespace std;

string t[7];

void init(){
    t[0] = "What is the name of your team?";
    t[1] = "Our name is ";
    t[2] = "My apologies, I did not understand. What is your team name?";
    t[3] = "We are team ";
    t[4] = "I am really sorry. Could you please repeat it once again?";
    t[5] = "WE ARE TEAM ";
    t[6] = "Oh, now I see. Here are your badges. Good luck!";
}

int main(){
    fast;
    init();
    string s;
    getline(cin,s);
    fore(i,0,7){
        if (i%2 == 0) cout<<t[i]<<nl;
        else{
            cout<<t[i];
            if (i != 5) cout<<s<<"."<<nl;
            else{
                for(auto au : s){
                    char c = toupper(au);
                    cout<<c;
                }
                cout<<"!!!"<<nl;
            }
        }
    }
    return 0;
}