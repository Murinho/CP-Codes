#include<bits/stdc++.h>
using namespace std;

unordered_set<int>vl[600];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    for(int i=0;i<20;i++)
        for(int j=0;j<30;j++)
            for(int k=0;k<30;k++)
                vl[i*30+j].insert(k*31+(j+i*k)%31);
    string s;
    cin>>s;
    int x,y;
    if(s[0]=='s'){
        cin>>x;
        for(int i:vl[x-1])cout<<i+1<<" ";
        cout<<"\n";
    }else{
        cin>>x>>y;
        for(int i=0;i<600;i++)
            if(vl[i].count(x-1)&&vl[i].count(y-1))
                cout<<i+1<<"\n";
    }
}
