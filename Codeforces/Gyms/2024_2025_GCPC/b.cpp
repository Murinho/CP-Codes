#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i<b;++i)
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
#define int long long int
 
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int32_t main(){
    fast;

    int n,h;
    cin>>n>>h;
    int ans=0;
    bool pasa=1;
    for(int i=0;i<n;i++){
        vector<int>nums(3);
        cin>>nums[0];
        cin>>nums[1];
        cin>>nums[2];
        sort(nums.begin(),nums.end());
        if(nums[0]>h){
            pasa=0;
        }
        if(nums[1]<=h){
            ans+=nums[0];
        }
        else ans+=nums[1];
    }
    if(pasa)cout<<ans<<"\n";
    else cout<<"impossible\n";

}