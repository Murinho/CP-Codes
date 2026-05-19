#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i<b;++i)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((int)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
 
using namespace std;

string s;
ll n,q;
multiset <ll> tams;
set <ll> lwbs;

void toggle(int pos){
    s[pos] = (s[pos] == '1' ? '0' : '1');
}

void printshit(){
    cout<<"----------------"<<nl;
    cout<<"Cur state:"<<nl;
    cout<<s<<nl;
    cout<<"LWBS: "<<nl;
    for(auto au : lwbs) cout<<au<<" ";
    cout<<nl<<"SIZES: "<<nl;
    for(auto au : tams) cout<<au<<" ";
    cout<<nl<<"----------------------"<<nl;
}

int main(){
    fast;
    cin>>s;
    s = "$" + s;
    n = sz(s);
    lwbs.insert(0);
    int pv=0;
    fore(i,1,n){
        if (s[i-1] != s[i]){
            lwbs.insert(i);
            tams.insert(i-pv);
            pv = i;
        }
    }
    lwbs.insert(n);
    tams.insert(n-pv);

    //printshit();

    cin>>q;
    while(q--){
        ll x;
        cin>>x;
        if (n == 2){
            cout<<1<<" "; //when the string has size(1)
            continue;
        }
        else if (x == 1){ //beginning (checked).
            if (s[x] == s[x+1]){ //1111.
                auto it = lwbs.find(x);
                ll nx = *next(it);
                ll dif = nx-x;
                tams.erase(tams.find(dif)); //erase the previous difference.
                lwbs.insert(x);
                tams.insert(1);
                lwbs.insert(x+1);
                tams.insert(dif-1);
            }
            else{ //011111.
                auto it = lwbs.find(x);
                auto nit = next(it);
                ll nx = *nit; //first next.
                ll nx2 = *next(nit); //second next.

                // erase right chunk lwb and size.
                lwbs.erase(nit); // erase first next from lwbs.
                tams.erase(tams.find(nx2-nx)); // erase that size.

                // erase current chunk size.
                tams.erase(tams.find(1));
                
                //insert the new size.
                tams.insert(nx2-x); 
            }
        }
        else if (x == n-1){ // (checked).
            if (s[x-1] == s[x]){ //11111.
                auto it = lwbs.lower_bound(x);
                ll r = *it;
                ll l = *prev(it);
                tams.erase(tams.find(r-l)); // remove big chunk size.
                tams.insert(r-l-1); // add prefix chunk size.
                tams.insert(1); // add suffix chunk size.
                lwbs.insert(x); // add lwb in x.
            }
            else{ //11110.
                auto it = lwbs.find(x);
                ll ant = *prev(it);
                ll dif = x-ant;
                tams.erase(tams.find(dif)); // erase the difference of left chunk.
                tams.erase(tams.find(1)); // erase the difference of right chunk.
                lwbs.erase(x); // erase the right lwb.
                tams.insert(dif+1); // insert the new difference.
            }
        }
        else{
            if (s[x-1] == s[x] && s[x] == s[x+1]){ // 111 -> 101. (checked).
                auto it = lwbs.lower_bound(x); // get the start of the range.
                it = prev(it);
                ll l = *it;
                ll nx = *next(it);
                //cout<<"this: "<<l<<" "<<nx<<nl;
                ll dif = nx-l;
                tams.erase(tams.find(dif)); // erase the complete range as it will be cut in half.
                lwbs.insert(x); //insert the cut.
                lwbs.insert(x+1); //start of right chunk.
                tams.insert(x-l); // left chunk.
                tams.insert(1); // mid chunk.
                tams.insert(nx-x-1); // right chunk.
            }
            else if (s[x-1] == s[x]){ //001 -> 011 (checked).
                auto it = lwbs.find(x+1); // this is the next position.
                ll l = *prev(it);
                ll r = *next(it);
                tams.erase(tams.find(x+1-l)); // erase the prefix size.
                tams.erase(tams.find(r-(x+1))); // erase the suffix size.
                tams.insert(x-l); // insert the erased size - 1. (left chunk).
                lwbs.erase(it); // erase lwb at x+1
                lwbs.insert(x); // insert lwb at x.
                tams.insert(r-x); // insert the new size (right chunk).
            }
            else if (s[x] == s[x+1]){ //011 -> 001.
                auto it = lwbs.find(x);
                ll l = *prev(it);
                ll r = *next(it);
                tams.erase(tams.find(r-x)); // remove (right chunk)
                tams.insert(r-x-1); // insert new (right chunk).
                tams.erase(tams.find(x-l)); // remove (left chunk).
                tams.insert(x-l+1); // insert new (left chunk).
                lwbs.erase(it); // erase current lwb.
                lwbs.insert(x+1); // insert new lwb.
            }
            else{ // join 2 chunks. 101 -> 111.
                auto it = lwbs.find(x);
                auto nit = next(it);
                auto pit = prev(it);
                ll l = *pit;
                ll r = *next(nit);
                tams.erase(tams.find(x-l)); // erase left chunk.
                tams.erase(tams.find(1)); // erase mid chunk.
                tams.erase(tams.find(r-x-1)); // erase right chunk.
                lwbs.erase(it); // erase mid lwb.
                lwbs.erase(nit); // erase right lwb.
                tams.insert(r-l); // insert the new big chunk.
            }   
        }
        toggle(x);
        //cout<<"ANS: "<<*tams.rbegin()<<nl;
        //printshit();
        cout<<*tams.rbegin()<<" ";
    }
    return 0;
}