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
 
using namespace std;
 
struct Node{
public:
    Node *left = nullptr;
    Node *right = nullptr;
    int val;
    bool preferido = 0;
 
    Node(int val, bool prefe){
        this->val = val;
        this -> preferido = prefe;
    }
};
 
int main(){
    fast;
    int n,m, r;
    cin>>n>>m>>r;
 
    int p2=0;
 
    Node *root = nullptr;
    Node *prefe = nullptr;
    Node *iterator = nullptr;
    
    for(int i=0;i<n;i++){
        string s2;
        cin>>s2;
        int p = 0;
        for(auto a:s2){
            if(a=='P'){
                p++;
                p2++;
            }
        }
        if(root == nullptr){
            root = new Node(p, (r-1 == i ? 1:0));
            iterator = root;
        }
        else{
            iterator->right =  new Node(p, (r-1 == i ? 1:0));
            iterator->right->left = iterator;
            iterator = iterator->right;
        }
        if(r-1 == i)prefe=iterator;
        //cout<< iterator->val<< " ";
    }
 
    //cout<<p2<<nl;
 
    /*while(iterator != nullptr)
    {
        cout<<iterator->val<<" ";
        iterator = iterator->left;
    }*/
 
    int ans=-1;
    bool found =0;
 
    string s;
    Node *iterator2 = iterator;
    Node *iterator3 = iterator;
    
    while(p2--){
        cin>>s;
        cin>>s;
        //cout<<s<<nl;
        while(iterator!=nullptr && iterator->val == 0){
            iterator = iterator->left;
        }
        iterator2 = iterator;
        iterator3 = iterator;
        iterator->val--;
        if(s[s.size()-1] == '!'){
            string t = s.substr(6, s.size()-9);
            //cout<<t<<nl;
            int n2 = t.size();
            while(iterator->left != nullptr && n2--){
                iterator = iterator->left;
            }
            //cout<<iterator->val<<nl;
            if(t.size()>0){
            	iterator3 = iterator3->left;
                if(iterator->left !=nullptr)
                	iterator->left->right = iterator2;
                iterator2->left = iterator->left;
                iterator->left = iterator2;
                iterator2->right = iterator;
                iterator2 = iterator3;
                iterator = iterator2;
            }
        }
    }
    
    while(prefe!= nullptr)
    {
        ans++;
        prefe = prefe->left;
    }
 
    cout<<ans+1<<nl;
 
    return 0;
}