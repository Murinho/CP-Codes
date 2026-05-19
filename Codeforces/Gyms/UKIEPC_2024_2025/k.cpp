// Problem: K. Knitting
// Contest: Codeforces - 2024 United Kingdom and Ireland Programming Contest (UKIEPC 2024)
// URL: https://codeforces.com/gym/105446/problem/K
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using namespace std;

int main(){

    int n,k,p;
    cin>>n>>k>>p;
    int m, i=0;
    cin>>m;

    set<pair<int,int>> st;
    deque<int> dq;
    vector<int> vis (k+1,0), aux(k+1, 0);
    vector<int>ans(n);
    
    bool pasa=1;
    
    for(;i<m;i++){
        cin>>ans[i];
        if(i>=p){
            int y = dq.front();
            dq.pop_front();
            vis[y]=0;
        }
        if(vis[ans[i]]!=0)pasa=false;
        else vis[ans[i]]=1;
        aux[ans[i]]++;
        dq.push_back(ans[i]);
    }
    
    if(!pasa){
    	cout<<"impossible";
        return 0;
    }

    for(int j=1;j<=k;j++){
        if(vis[j]==0)st.insert({aux[j],j});
    }

    for(;i<n;i++){
        if(i>=p){
            int y = dq.front();
            dq.pop_front();
            st.insert({aux[y],y});
            vis[y]=0;
        }
        if(st.size()==0){
            cout<<"impossible";
            return 0;
        }
        int z = st.begin()->first;
        int x = st.begin()->second;
        st.erase(st.begin());
        ans[i] = x;
        vis[x] = 1;
        aux[x]++;
        dq.push_back(x);
    }

    for(auto a:ans)cout<<a<<" ";    

    return 0;
}