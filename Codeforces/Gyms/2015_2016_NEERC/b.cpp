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


int main(){
    fast;
    //freopen("black.in", "r", stdin);   // Read input from input.in
    //freopen("black.out", "w", stdout); // Write output to output.out
    

    int x,y;
    cin>>y>>x;
    
    vector<vector<char>> grid;

    if(x > y){

        grid.push_back(vector<char> (1,'@'));

        for(int i=0;i<x-1;i++){
            grid[0].push_back('.');
            grid[0].push_back('@');
        }

        grid.push_back(vector<char> (grid[0].size(), '@'));

        grid.push_back(vector<char> (grid[0].size(), '.'));

        grid.push_back(vector<char> (1,'.'));

        for(int i=0;i<y-1;i++){
            grid[3].push_back('@');
            grid[3].push_back('.');
        }
        while(grid[3].size()<grid[2].size())grid[3].push_back('.');
        grid.push_back(vector<char> (grid[0].size(), '.'));

        cout<<6<< " "<< grid[0].size()<<nl;

        for(int i=0;i<grid[0].size();i++){
            cout<<"@"<<" ";
        }
        cout<<"\n";
    }
    else{

        grid.push_back(vector<char> (1,'.'));

        for(int i=0;i<y-1;i++){
            grid[0].push_back('@');
            grid[0].push_back('.');
        }

        grid.push_back(vector<char> (grid[0].size(), '.'));

        grid.push_back(vector<char> (grid[0].size(), '@'));

        grid.push_back(vector<char> (1,'@'));

        for(int i=0;i<x-1;i++){
            grid[3].push_back('.');
            grid[3].push_back('@');
        }
        while(grid[3].size()<grid[2].size())grid[3].push_back('@');
        grid.push_back(vector<char> (grid[0].size(), '@'));

        cout<<6<< " "<< grid[0].size()<<nl;

        for(int i=0;i<grid[0].size();i++){
            cout<<"."<<" ";
        }
        cout<<"\n";
    }

    

    for(auto a:grid){
        for(auto b:a)cout<<b<<" ";
        cout<<"\n";
    }
    
    return 0;
}