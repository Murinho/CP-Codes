#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; ++i)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define ALL(u) u.begin(), u.end()
#define vi vector<ll>
#define vvi vector <vi>
#define sz(a) ((ll)a.size())
#define lsb(x) ((x)&(-x))
#define PI acos(-1.0)
#define pii pair <ll,ll>
#define fst first
#define snd second

using namespace std;

const ll N = 2e5+10;

struct node{
    ll sum,pre;
};

node merge(node x, node y){
    node ret;
    ret.sum = x.sum + y.sum;
    ret.pre = min(x.pre,x.sum + y.pre);
    return ret;
}

node tree[4*N];
ll n,q;

void up(int widx, int val, int idx = 1, int l = 0, int r = (2*n)-1){
    if (l == r){
        tree[idx] = {val,val};
        return;
    }
    int mid = (l+r)>>1;
    if (widx <= mid) up(widx,val,2*idx,l,mid);
    else up(widx,val,2*idx + 1,mid+1,r);
    tree[idx] = merge(tree[2*idx],tree[2*idx + 1]);
}

node query(int wl, int wr, int idx=1, int l=0, int r = 2*n - 1){
    if (wl <= l && r <= wr) return tree[idx];
    int mid = (l+r)>>1;
    if (wr <= mid) return query(wl,wr,2*idx,l,mid);
    if (wl > mid) return query(wl,wr,2*idx + 1,mid+1,r);
    return merge(query(wl,wr,2*idx,l,mid),query(wl,wr,2*idx + 1,mid+1,r));
}

void solve(){
    cin>>n>>q;
    pii a[n*2];
    fore(i,0,n) cin>>a[i].fst;
    fore(i,0,n) cin>>a[i].snd, a[i+n] = a[i];
    fore(i,0,2*n){
        up(i,a[i].fst - a[i].snd);
    }
    while(q--){
        int ty,i;
        cin>>ty>>i;
        i--;
        if (ty == 1){
            auto it = query(i,i+n-1);
            if (it.pre >= 0){
                cout<<-1<<nl;
                continue;
            }
            int st=i,en=i+n-1,mid,pos=i;
            while(st <= en){
                mid = (st+en)>>1;
                it = query(i,mid);
                if (it.pre < 0){
                    pos = mid;
                    en = mid-1;
                }
                else st = mid+1;
            }
            pos %= n;
            cout<<pos+1<<nl;
        }
        else{
            ll x;
            cin>>x;
            if (ty == 2) a[i].fst = a[i+n].fst = x;
            else a[i].snd = a[i+n].snd = x;
            up(i,a[i].fst - a[i].snd);
            up(i+n,a[i+n].fst - a[i+n].snd);
        }
    }
}

int main(){
    fast;
    solve();
    return 0;
}