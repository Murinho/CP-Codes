#include <bits/stdc++.h>
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define pb push_back
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define ALL(a) a.begin(), a.end()
#define sz(a) ((ll)a.size())
#define pii pair<ll,ll>
#define nl '\n'
#define fore(i,a,b) for(int i=a; i<b; i++)
#define ld long double
#define ppb pop_back

using namespace std;

const ll maxn = 1e5+10;
const ll M = 1e9+9;
const ll B = 131;

ll pws[maxn],h[maxn];
int d1[maxn],d2[maxn];
string s;
int cnt = 0;
int ogn;

void clean(){
    fore(i,0,maxn){
        pws[i] = h[i] = d1[i] = d2[i] = 0;
    }
}

ll conv(char c){ return (c-'a'+1);}

bool sameHash(int l1, int len1, int l2, int len2){
    if (len1 != len2) return false;
    int r1 = l1 + len1, r2 = l2 + len2;
    ll h1 = (h[r1]-h[l1]*pws[len1]%M + M)%M;
    ll h2 = (h[r2]-h[l2]*pws[len2]%M + M)%M;
    return h1 == h2;
}

void precalc(){
    pws[0] = 1;
    fore(i,1,maxn) pws[i] = (pws[i-1]*B)%M;
    h[0] = conv(s[0]);
    fore(i,0,sz(s)) h[i+1] = ((h[i]*B)+conv(s[i]))%M;
}

// manacher stuff:
void manacher(){
    int l=0,r=-1,n=sz(s);
    fore(i,0,n){
        int k=i>r?1:min(d1[l+r-i],r-i);
        while(i+k<n&&i-k>=0&&s[i+k]==s[i-k]) k++;
        d1[i]=k--;
        if (i+k>r) l=i-k,r=i+k;
    }
    l=0, r=-1;
    fore(i,0,n){
        int k=i>r?1:min(d2[l+r-i+1],r-i+1);k++;
        while(i+k<=n&&i-k>=0&&s[i+k-1]==s[i-k])k++;
        d2[i]=--k;
        if (i+k-1>r)l=i-k,r=i+k-1;
    }
}

void printManacher(){
    cout << "d1 (odds): " << nl;
    fore(i,0,sz(s)) cout << d1[i] << " ";
    cout << nl;

    cout << "d2 (evens): " << nl;
    fore(i,0,sz(s)) cout << d2[i] << " ";
    cout << nl;
}

bool doit(bool rev){
    clean();

    // hashing precalc
    precalc();

    // manacher precalc
    manacher();

    int tam = sz(s);
    int mid = tam/2; // exclusive

    // first type, prefix doesn't move
    fore(i,0,mid){
        int len = i+1;
        if (!sameHash(0,len,len,len)){
            continue;
        }
        int len2 = sz(s) - (2*len);
        if (len2%2 == 0){
            int center = (len*2) + (len2/2);
            if (d2[center] < len2/2) continue;
        }
        else{
            int center = (len*2) + (len2/2);
            if (d1[center] < (len2/2)+1) continue;
        }
        if (!rev){
            cout << i+cnt+2 << " " << ogn-cnt << nl;
        }
        else{
            cout << (ogn+1)-(ogn-cnt) << " " << (ogn+1)-(i+cnt+2) << nl;
        }
        return true;
    }

    // second type, the prefix is the reversed thing
    fore(i,0,mid){
        int len = i+1;
        if (!sameHash(0,len,sz(s)-len,len)){
            continue;
        }
        int len2 = sz(s) - (2*len);
        if (len2%2 == 0){
            int center = len + (len2/2);
            if (d2[center] < len2/2) continue;
        }
        else{
            int center = len + (len2/2);
            if (d1[center] < (len2/2)+1) continue;
        }
        if (!rev){
            cout << cnt+1 << " " << i+cnt+1 << nl;
        }
        else{
            cout << (ogn+1)-(i+cnt+1) << " " << (ogn+1)-(cnt+1) << nl;
        }
        return true;
    }
    return false;
}

int main(){
    fast;
    cin >> s;
    ogn = sz(s);
    int l = 0;
    int r = sz(s)-1;
    while(r >= 0 && s[l] == s[r]){
        cnt++;
        l++, r--;
    }

    // the string is already a palindrome itself.
    if (cnt == sz(s)){
        cout << "1 1" << nl;
        return 0;
    }
    
    // remove useless shit
    fore(i,0,cnt) s.ppb();
    reverse(ALL(s));
    fore(i,0,cnt) s.ppb();
    reverse(ALL(s));

    if (doit(false)) return 0;

    reverse(ALL(s));

    if (doit(true)) return 0;

    cout << -1 << " " << -1 << nl;
    return 0;
}