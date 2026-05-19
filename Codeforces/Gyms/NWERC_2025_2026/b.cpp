#include <bits/stdc++.h>
#define ll long long
#define pb push_back

#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define pi pair<int,int>
#define f first
#define s second

using namespace std;

vector<int>res;

void imp(){
    cout << res.size()<<"\n";

    for(auto u:res)cout<<u<<" ";
}

vector<int>ayuda={0,4,40,400,44,404,440,444};

void lol(int n, int t){

    if(n%(1000/t)==0){
        while(n){
            res.pb(200);
            n-=(200/t);
        }
        return;
    }


    while(n%10==0){
        n/=10;
        t*=10;
    }

    if(n%5!=4 || (n/5)%2){
        while(n>=5){
            res.pb(5*t); 
            n-=5;
        }
        if(n==2){
            res.pb(2*t);
        }
        
        if(n==1){
            res.pb(t);
        }
        
        if(n==3){
            res.pb(2*t);
            res.pb(t);
        }
        if(n==4){
            res.pb(2*t);
            res.pb(2*t);
        }
    } else{
        
        if(n%20 != 4){
            while(n){
                res.pb(2*t); 
                n-=2;
            }
        } else {
            res.pb(2*t);
            res.pb(2*t);
            n-=4;
            lol(n,t);
        }
    }
}

int main(){
    fast;
    int n;
    cin>>n;

    for(auto r:ayuda){
        if(n%2000==r){
            cout<<"splittable\n";
            return 0;
        }
    }

    lol(n,1);
    imp();
}