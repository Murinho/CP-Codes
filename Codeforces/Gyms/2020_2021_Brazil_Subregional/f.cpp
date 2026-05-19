#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; ++i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll> 
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second

using namespace std;

string s;

ll pts[3],games[3];
bool leftsvs,leftwon,rightwon;

void init(){
    leftsvs=true;
    leftwon=rightwon=false;
}

void matchWin(){
    if (games[1] == 2) leftwon=true;
    if (games[2] == 2) rightwon=true;
}

void gameWin(){
    if (pts[1]==10){
        games[1]++;
        pts[1]=pts[2]=0;
    }
    else if (pts[2]==10){
        games[2]++;
        pts[1]=pts[2]=0;
    }
    else if (max(pts[1],pts[2]) >= 5){
        if (pts[1]-2 >= pts[2]){
            games[1]++;
            pts[1]=pts[2]=0;
        }
        else if (pts[1] <= pts[2]-2){
            games[2]++;
            pts[1]=pts[2]=0;
        }
    }
}

int main(){
    fast;
    cin>>s;
    init();
    for(auto elm : s){
        if (elm == 'S'){
            if (!leftwon && !rightwon){
                if (leftsvs) pts[1]++;
                else pts[2]++;
                gameWin();
                matchWin();
            }
        }
        else if (elm == 'R'){
            if (!leftwon && !rightwon){
                if (leftsvs) pts[2]++, leftsvs=false;
                else pts[1]++, leftsvs=true;
                gameWin();
                matchWin();
            }
        }
        else{
            if (leftwon){
                cout<<games[1]<<" (winner) - "<<games[2]<<nl;
            }
            else if (rightwon){
                cout<<games[1]<<" - "<<games[2]<<" (winner)"<<nl;
            }
            else{
                if (leftsvs) cout<<games[1]<<" ("<<pts[1]<<"*) - "<<games[2]<<" ("<<pts[2]<<")"<<nl;
                else cout<<games[1]<<" ("<<pts[1]<<") - "<<games[2]<<" ("<<pts[2]<<"*)"<<nl;
            }   
        }
    }
}