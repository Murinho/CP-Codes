#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define in insert
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(),a.end()
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define nl '\n'
#define ppb pop_back
#define ld long double

using namespace std;

const int C=1e5+5;

int n;
int g[C];
int un,ds;
int m=1e9;


string ayuda(vector<int>a){
    string s="";
    s+='(';
    int k=a.size();
    if(k==1){
        return to_string(a[0]);
    }
    for(int i=0;i<k;i++){
        s+=to_string(a[i]);
        if(i!=k-1)s+='+';
    }
    s+=')';
    return s;
}

int main(){
    fast;
    cin>>n;
    multiset<pair<int,vector<int>>>a;
    for(int i=0;i<n;i++){
        cin>>g[i];
        if(g[i]==1)un++;
        else {
            a.in({g[i],{g[i]}});
        }
    }

    while(un){
        auto j=a.begin();
        if(j==a.end()){
            a.in({1,{1}});
            un--;
            continue;
        }

        if(un==2){
            if((*j).f==1){
                auto aux=*j;
                a.erase(j);
                aux.f+=2;
                aux.s.pb(1);
                aux.s.pb(1);
                a.in(aux);
                break;
            }
            if((*j).f>2){
                a.in({2,{1,1}});
                break;
            }
            if(next(j)==a.end()){
                a.in({2,{1,1}});
                break;
            }
            if((*next(j)).f==2){
                auto logan=*j;
                auto roge=*next(j);

                logan.f++;
                logan.s.pb(1);

                roge.f++;
                roge.s.pb(1);

                a.erase(next(j));
                a.erase(j);
                a.in(logan);
                a.in(roge);
                break;
            }
            a.in({2,{1,1}});
            break;
        }
        if((*j).f>2){
            if(un==1){
                auto aux=*j;
                a.erase(j);
                aux.f++;
                aux.s.pb(1);
                a.in(aux);
                break;
            } 
            a.in({1,{1}});
            un--;
            continue;
        }
    
         
        auto aux=*j;
        a.erase(j);
        aux.f++;
        aux.s.pb(1);
        a.in(aux);
        un--;
        
    }

    bool usd=0;

    for(auto l:a){
        if(usd)cout<<'*';
        cout<<ayuda(l.s);
        usd=1;  
    }

    return 0;
}