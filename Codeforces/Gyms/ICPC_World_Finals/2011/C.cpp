#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(int i=a;i<b;++i)
#define rofe(i,a,b) for(ll i=a-1;i>=b;--i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define lsbpos(x) __builtin_ffs(x)
#define PI acos(-1.0)
#define pii pair<ll,ll>
#define fst first
#define snd second
#define eb emplace_back
#define ppb pop_back
#define i128 __int128_t
 
using namespace std;

const ll maxn = 202;

struct Bigint {
    string a;
    int sign;

    Bigint(){}
    void operator = (string b) {
        a= (b[0]=='-' ? b.substr(1) : b);
        reverse(a.begin(), a.end());
        (*this).Remove0(b[0]=='-' ? -1 : 1);
    }
    Bigint(string x) {(*this)=x;}
    Bigint(ll x) {(*this)=to_string(x);}
    void operator = (ll x){*this=to_string(x);}

    char operator[](int i){return a[i];}
    int size() {return a.size();}
    Bigint inverseSign() {sign*=-1; return (*this);}

    Bigint Remove0(int newSign) {
        sign = newSign;
        for(int i=a.size()-1; i>0 && a[i]=='0'; i--) a.pop_back();
        if(a.size()==1 && a[0]=='0') sign=1;
        return (*this);
    }

    bool operator == (Bigint x) {return sign==x.sign && a==x.a;}
    bool operator == (string x) {return *this==Bigint(x);}
    bool operator == (ll x)     {return *this==Bigint(x);}
    bool operator != (Bigint x) {return !(*this==x);}
    bool operator != (string x) {return !(*this==x);}
    bool operator != (ll x)     {return !(*this==x);}

    bool operator < (Bigint b) {
        if (sign!=b.sign) return sign<b.sign;
        if(a.size()!=b.size()) return a.size()*sign<b.size()*sign;
        for(int i=a.size()-1; i>=0; i--)
            if(a[i] != b[i]) return a[i]<b[i];
        return false;
    }
    bool operator <  (string x) {return *this<Bigint(x);}
    bool operator <  (ll x)     {return *this<Bigint(x);}
    bool operator <= (Bigint b) {return *this==b || *this<b;}
    bool operator <= (string b) {return *this==b || *this<b;}
    bool operator <= (ll b)     {return *this==b || *this<b;}
    bool operator >  (Bigint b) {return !(*this==b || *this<b);}
    bool operator >  (string x) {return !(*this==x || *this<x);}
    bool operator >  (ll b)     {return !(*this==b || *this<b);}
    bool operator >= (Bigint b) {return *this==b || *this>b;}
    bool operator >= (string b) {return *this==b || *this>b;}
    bool operator >= (ll b)     {return *this==b || *this>b;}

    Bigint operator + (Bigint b) {
        if(sign != b.sign) return (*this)-b.inverseSign();
        Bigint sum;
        for(int i=0, carry=0; i<a.size() || i<b.size() || carry; i++){
            if (i<a.size()) carry+=a[i]-'0';
            if (i<b.size()) carry+=b[i]-'0';
            sum.a += (carry % 10 + 48);
            carry /= 10;
        }
        return sum.Remove0(sign);
    }
    Bigint operator +  (string x) {return *this+Bigint(x);}
    Bigint operator +  (ll x)     {return *this+Bigint(x);}
    Bigint operator ++ (int) {*this+=1; return *this-1;}
    Bigint operator ++ ()    {*this+=1; return *this;}
      void operator += (Bigint x) {*this = *this+x;}
      void operator += (string x) {*this = *this+x;}
      void operator += (ll x)     {*this = *this+x;}


    Bigint operator - ( Bigint b ) {
        if(sign != b.sign) return (*this)+b.inverseSign();
        if(*this < b) return (b - *this).inverseSign();
        Bigint sub;
        for(int i=0,borrow=0; i<a.size(); i++) {
            borrow = a[i]-borrow-(i<b.size() ? b.a[i] : '0');
            sub.a += borrow>=0 ? borrow+'0' : borrow + 58;
            borrow = borrow>=0 ? 0:1;
        }
        return sub.Remove0(sign);
    }
    Bigint operator - (string x) {return *this-Bigint(x);}
    Bigint operator - (ll x)     {return *this-Bigint(x);}
    Bigint operator -- (int) {*this-=1; return *this+1;}
    Bigint operator -- ()    {*this-=1; return *this;}
      void operator -= (Bigint x) {*this = *this-x;}
      void operator -= (string x) {*this = *this-x;}
      void operator -= (ll x)     {*this = *this-x;}

    Bigint operator * (Bigint b) {
        Bigint mult("0");
        for(int i=0, k=a[i]; i<a.size(); i++, k=a[i]) {
            while(k-- -'0') mult=mult+b;
            b.a.insert(b.a.begin(),'0');
        }
        return mult.Remove0(sign * b.sign);
    }
    Bigint operator * (string x) {return *this*Bigint(x);}
    Bigint operator * (ll x)     {return *this*Bigint(x);}
      void operator *= (Bigint x) {*this = *this*x;}
      void operator *= (string x) {*this = *this*x;}
      void operator *= (ll x)     {*this = *this*x;}

    Bigint operator / (Bigint b) {
        if(b.size()==1 && b[0]=='0') b.a[0]/=(b[0]-'0');
        Bigint c("0"), d;
        for(int j=0; j<a.size(); j++) d.a += "0";
        int dSign = sign*b.sign; b.sign=1;
        for(int i=a.size()-1; i>=0; i--) {
            c.a.insert(c.a.begin(),'0');
            c=c+a.substr(i,1);
            while(!(c<b)) c=c-b, d.a[i]++;
        }
        return d.Remove0(dSign);
    }
    Bigint operator / (string x) {return *this/Bigint(x);}
    Bigint operator / (ll x)     {return *this/Bigint(x);}
      void operator /= (Bigint x) {*this = *this/x;}
      void operator /= (string x) {*this = *this/x;}
      void operator /= (ll x)     {*this = *this/x;}

    Bigint operator % (Bigint b) {
        if( b.size()==1 && b[0]=='0') b.a[0]/=(b[0]-'0') ;
        Bigint c("0");
        int cSign = sign*b.sign; b.sign=1;
        for( int i=a.size()-1; i>=0; i-- ) {
            c.a.insert( c.a.begin(),'0');
            c = c+a.substr(i,1);
            while(!(c<b)) c=c-b;
        }
        return c.Remove0(cSign);
    }
    Bigint operator % (string x) {return *this%Bigint(x);}
    Bigint operator % (ll x)     {return *this%Bigint(x);}
      void operator %= (Bigint x) {*this = *this%x;}
      void operator %= (string x) {*this = *this%x;}
      void operator %= (ll x)     {*this = *this%x;}

    void print() {
        if(sign==-1) putchar('-');
        for(int i=a.size()-1; i>=0; i--) putchar(a[i]);
    }
    friend istream& operator >>(istream &in,Bigint &x){
        string s; in>>s; x=s; return in;
    }
    friend ostream& operator <<(ostream &out,Bigint &x){
        if(x.sign==-1) putchar('-');
        for(int i=x.size()-1; i>=0; i--)
            putchar(x[i]);
        return out;
    }

    friend Bigint pow(Bigint base, Bigint pw){
        Bigint ans=1;
        while(pw!=0){
            if(pw%2 !=0) ans*=base;
            base*=base, pw/=2;
        }
        return ans;
    }
    friend Bigint pow(Bigint a, Bigint b,Bigint mod) {
        if (b==0) return Bigint(1);
        Bigint tmp=pow(a,b/2,mod);
        if ((b%2)==0) return (tmp*tmp)%mod;
        else return (((tmp*tmp)%mod)*a)%mod;
    }
    friend Bigint sqrt(Bigint x) {
        Bigint ans=x,tmp=(x+1)/2;
        while (tmp<ans) ans=tmp, tmp=(tmp+x/tmp)/2;
        return ans;
    }
    friend Bigint gcd(Bigint a,Bigint b){
        return a%b==0 ? b : gcd(b, a%b);
    }
    friend Bigint lcm(Bigint a,Bigint b){
        return a/gcd(a,b);
    }
};

char a[maxn+5][maxn+5],b[maxn+5][maxn+5];
bool vis[maxn+5][maxn+5];
int mov[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int n,m;
int bucket[6];

void init(){
	fore(i,0,n+2){
		fore(j,0,maxn+5){
			 b[i][j] = '0';
			 vis[i][j] = false;
		}
	}
	fore(i,0,6) bucket[i] = 0;
}

bool inside(int &x, int &y){
	if (0 <= x && x <= maxn+1 && 0 <= y && y <= maxn+1 && !vis[x][y]) return true;
	return false;
}

int flood_fill(int stfil, int stcol, char color){
	queue < pair <int,int> > q;
	q.push({stfil,stcol});
	vis[stfil][stcol] = true;
	int cc = 0;
	while(sz(q)){
		auto [fil,col] = q.front();
		q.pop();
		
		fore(i,0,4){
			int sfil = fil + mov[i][0];
			int scol = col + mov[i][1];
			
			if (inside(sfil,scol)){
				if (color == '0'){ // coloring with white.
					if (b[sfil][scol] == color){
						vis[sfil][scol] = true;
						q.push({sfil,scol});
					}
				}
				else{ // coloring with black.
					if (b[sfil][scol] == '1'){ // next is black.
						vis[sfil][scol] = true;
						q.push({sfil,scol});
					}
					else{ // next is white.
						flood_fill(sfil,scol,'0'); // call flood_fill for the whites.
						cc++;
					} 
				}
			}
		}
	}
	return cc;
}

string symbol = "WAKJSD";
int ord[6] = {1,5,3,2,4,0};

bool solve(int &tc){
	cin >> n >> m;
	if (n == 0) return false;
	
	init();
	
	fore(i,1,n+1){
		fore(j,1,m+1){
			cin >> a[i][j];
		}
	}
	
	// Use big integer to convert from hexadecimal -> decimal -> binary.
	fore(i,1,n+1){
		int col = maxn;
		for(int j = m; j>=1; j--){
			ll val = 0;
			if ('0' <= a[i][j] && a[i][j] <= '9') val = (ll)(a[i][j]-'0');
			else val = (ll)(a[i][j]-'a') + 10;
			
			for(int k = 0; k<4; k++){
				if ((1<<k)&val) b[i][col-k] = '1';
				else b[i][col-k] = '0';
			}
			col -= 4;
		}
	}
	
	// Map:
	/*
	fore(i,0,n+2){
		fore(j,1,maxn+2){
			cout<<b[i][j];
		}
		cout<<nl;
	} */
	
	flood_fill(0,0,'0'); // flood fill with color white to visit the background of the picture.
	
	fore(i,1,n+1){
		fore(j,1,maxn+1){
			if (!vis[i][j] && b[i][j] == '1'){
				int cc = flood_fill(i,j,'1');
				if (cc < sz(symbol)) bucket[cc]++;
			}
		}
	}
	
	cout << "Case "<<tc<<": ";
	fore(i,0,6){
		fore(j,0,bucket[ord[i]]) cout<<symbol[ord[i]];
	}
	cout<<nl;
	return true;
}

int main(){
    fast;
    for(int i = 1;;i++){
    	if (!solve(i)) break;
    }
    return 0;
}