#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int n;
ll c,d;
string a,b;
vector<int>h;
map<pair<ll,vector<int>>,ll>st;

void get1(int i,ll p){
    if(i==a.size()){
        if(p!=0&&p%c==0){
            auto cl=h;
            sort(cl.begin(),cl.end());
            if(p/c<9e18/d)
                st[{p/c*d,cl}]=p;
        }
        return;
    }
    if(a[i]!='0'||p)
        get1(i+1,p*10+a[i]-'0');
    h.push_back(a[i]-'0');
    get1(i+1,p);
    h.pop_back();
}
bool get2(int i,ll p){
    if(i==b.size()){
        auto cl=h;
        sort(cl.begin(),cl.end());
        if(st.count({p,cl})){
            cout<<"possible\n";
            cout<<st[{p,cl}]<<" "<<p<<"\n";
            return 1;
        }
        return 0;
    }
    if(b[i]!='0'||p)
        if(get2(i+1,p*10+b[i]-'0'))
            return 1;
    h.push_back(b[i]-'0');
    if(get2(i+1,p))return 1;
    h.pop_back();
    return 0;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>a>>b>>c>>d;
    ll g=gcd(c,d);
    c/=g,d/=g;
    get1(0,0);
    if(!get2(0,0)){
        cout<<"impossible";
    }
    return 1<<32;
}