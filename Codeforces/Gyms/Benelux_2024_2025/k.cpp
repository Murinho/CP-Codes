#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fore(i,a,b) for(ll i = a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define nl '\n'
#define pii pair <ll,ll>
#define vi vector<ll>
#define vvi vector<vi>
#define fst first
#define snd second
#define sz(a) ((ll) a.size())
#define ALL(a) a.begin(),a.end()
#define ppb pop_back
#define eb emplace_back
#define i128 __int128_t

using namespace std;

const ll M = 1000000000000061;
const ll B = 131;
const ll maxn = 5010;
const ll maxsub = 22512500; //should be: 12502500

int tam[maxsub],seen[maxsub],pv[maxsub];
string s;
unordered_map <ll,int> mp;
int n;

ll conv(char &c){
    return (c-'a'+1);
}

int main(){
    fast;
    cin>>s;
    n = sz(s);

    // get all the different substrings.
    int cnt=0,id;
    ll ha;
    fore(i,0,n){
        ha = conv(s[i]);
        fore(j,i,n){
            ha = ((ha*B)+conv(s[j]))%M;
            if (!mp.count(ha)){
                mp[ha] = cnt;
           		tam[cnt] = j-i+1;
                pv[cnt] = j;
                seen[cnt]=1;
                cnt++;
            }
            else{
            	id = mp[ha];
	            if (pv[id] < i){
	            	pv[id] = j;
	            	seen[id]++;
	            }
            }
        }
    }
    int ans = n+1;
    int score=0;
    fore(i,0,cnt){
        score = n - (seen[i]*(tam[i]-1)) + tam[i];
        ans = min(ans,score);
    }
    cout<<ans<<nl;
    return 0;
}