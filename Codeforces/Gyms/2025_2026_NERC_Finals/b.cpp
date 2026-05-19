#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector <ll>
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(a) a.begin(), a.end()
#define fst first
#define snd second
#define pii pair<ll,ll>

using namespace std;

void sol(){

    int n,m;

    cin >> n>>m;

    priority_queue<int>a;

    priority_queue<int>b;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push(x);
    }

    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        b.push(x);
    }


    while(true){
        int ta=a.top();

        int tb =b.top();
        b.pop();
        tb-=ta;

        if(tb>0)b.push(tb);

        if(b.empty()){
            cout << "Alice\n";
            break;
        }
        
        ////

        tb=b.top();

        ta =a.top();
        a.pop();
        ta-=tb;

        if(ta>0)a.push(ta);

        if(a.empty()){
            cout << "Bob\n";
            break;
        }
    }




}

int main(){
    fast;
    int t;
    cin >> t;

    while(t--)sol();
}