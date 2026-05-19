#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int r,c;
    cin>>r>>c;
    string s[r];
    for(int i=0;i<r;i++)
        cin>>s[i];
    vector<pair<int,int>>p;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(s[i][j]=='#')
                p.push_back({i,j});
    for(;p[0].first<p[1].first;){
        p[0].first++;
        s[p[0].first][p[0].second]='#';
    }
    for(;p[0].second<p[1].second;){
        p[0].second++;
        s[p[0].first][p[0].second]='#';
    }
    for(;p[0].second>p[1].second;){
        p[0].second--;
        s[p[0].first][p[0].second]='#';
    }
    for(;p[1].second<p[2].second;){
        p[1].second++;
        s[p[1].first][p[1].second]='#';
    }
    for(;p[1].second>p[2].second;){
        p[1].second--;
        s[p[1].first][p[1].second]='#';
    }
    for(;p[1].first<p[2].first;){
        p[1].first++;
        s[p[1].first][p[1].second]='#';
    }
    for(int i=0;i<r;i++)
        cout<<s[i]<<"\n";
    return 1<<32;
}