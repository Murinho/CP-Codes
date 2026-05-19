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

using namespace std;

struct Node{
    bool fav;
    ll val;
    Node *left;
    Node *right;

    Node(int val, bool _fav){
        this->val = val;
        this->fav = _fav;
        this->left = nullptr;
        this->right = nullptr;
    }
};

ll n,m,k;
string s;

int main(){
    fast;
    cin>>n>>m>>k;
    Node *head = new Node(0,0); //place 0.
    Node *pv = head;
    Node *cur = nullptr; //the current node i am looking at.
    ll totp = 0;
    fore(i,1,n+1){
        cin>>s;
        ll cnt = 0;
        for(auto &elm : s) if (elm == 'P') cnt++;
        cur = new Node(cnt,(k == i ? true : false));
        cur->left = pv; //link it to its previous one.
        pv = cur;
        totp += cnt;
    }
    
    fore(i,0,totp){
        cin>>s;
        cin>>s;
        while(s.back() != 'y') s.ppb();
        reverse(ALL(s));
        while(s.back() != 'y') s.ppb();
        
        ll mov = sz(s)-3; //amount of rank the current team will go up.
            
        // move the team.
        if (mov > 0){
            Node* last = cur;
            last->right = nullptr; // sera el ultimo equipo.

        }


        while(cur != head && cur->val == 0){
            cur = cur->left;
        }
    }

    ll ans = 0;
    cur = head;
    for(;;){
        if (cur->fav == true) break;
        cur = cur->right;
        ans++;
    }
    cout<<ans<<nl;
    return 0;

}