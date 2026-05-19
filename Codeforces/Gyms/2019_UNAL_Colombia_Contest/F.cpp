// Problem: F. Fraction Formula
// Contest: Codeforces - 2019 ICPC Universidad Nacional de Colombia Programming Contest
// URL: https://codeforces.com/gym/102307/problem/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i<b;++i)
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

ll n;
vector<ll> e;
string t;

void init(){
	e.clear(), e.resize(n+1);
}

void reduceFraction(pii &p){
	if (p.fst == 0 || p.snd == 0) return;
	ll mcd = __gcd(abs(p.fst),abs(p.snd));
	p.fst /= mcd, p.snd /= mcd;
	return;
}

pii sumFraction(pii p1, pii p2){
	if (p1.fst == 0 && p1.snd == 0) return p2;
	if (p2.fst == 0 && p2.snd == 0) return p1;
	//comun denominador:
	ll lcm = abs(p1.snd*p2.snd)/__gcd(p1.snd,p2.snd);
	p1.fst *= (lcm/p1.snd);
	p2.fst *= (lcm/p2.snd);
	pii res = {p1.fst + p2.fst,lcm};
	reduceFraction(res);
	return res;
}

bool isSign(char &c){
	if (c == '+' || c == '-') return true;
	return false;
}

pii dfs(int pos, int r){
	int signo = +1;
	pii frac;
	frac.fst = frac.snd = 0;
	bool denom = false;
	pos++;
	string num = "";
	while(pos <= r){
		if (isSign(t[pos])){
			if (t[pos] == '+') signo = +1;
			else signo = -1;
			num = "";
		}
		else if (t[pos] == '/' || t[pos] == ')'){
			if (sz(num)){
				ll aux = stoi(num);
				if (!denom) frac.fst = aux, denom = true;
				else frac.snd = aux, denom = false;
				num = "";
			}
		}
		else if (t[pos] == '('){
			pii aux = dfs(pos,e[pos]);
			aux.fst *= signo;
			frac = sumFraction(frac,aux);
			signo = +1;
			pos = e[pos];
			num = "";
		}
		else num += t[pos];
		pos++;
	}
	frac.fst *= signo;
	reduceFraction(frac);
	return frac;
}

int main(){
    fast;	
    /*
    pii aux = sumFraction({1,2},{0,0});
    reduceFraction(aux);
    cout<<aux.fst<<"/"<<aux.snd<<nl; 
    return 0; */
    string s;
    while(cin>>s){
    	//editar la entrada.
    	t = "((";
    	for(auto au : s){
    		if (isSign(au)) t += ")", t += au, t += "(";
    		else t += au;
    	}
    	t += "))";
    	
    	n = sz(t);
    	init();
    	
    	//stack to know where to go and stop:
    	stack <int> stk;
    	fore(i,0,sz(t)){
    		if (t[i] == '(') stk.push(i);
    		else if (t[i] == ')'){
    			e[stk.top()] = i;
    			stk.pop();
    		}
    	}
    	//cout<<t<<nl;
    	//fore(i,0,n+1) if (e[i]) cout<<i<<" --> "<<e[i]<<nl;
    	pii ans = dfs(0,e[0]);
    	
    	if (ans.fst == 0 || ans.snd == 0){
    		ans.fst = 0, ans.snd = 1;
    	}
    	cout<<ans.fst<<"/"<<ans.snd<<nl;
    }
	return 0;
}