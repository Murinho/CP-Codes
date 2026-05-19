#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s1,s2,r1,r2;
    cin>>s1>>s2;
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    int p=-1;
    for(int i=0,ac=0;i<min(s1.size(),s2.size());i++){
        if(s1[i]-'0'+s2[i]-'0'+ac>9)ac=1,p=i;
        else ac=0;
    }
    if(p<0)cout<<"0";
    else{
        for(int i=0;i<=p;i++)r1+='9'-s1[i]+'0';
        for(int i=0;i<=p;i++)r2+='9'-s2[i]+'0';
        r1+='0',r2+='0';
        int i;
        for(i=0;r1[i]=='9';i++)r1[i]='0';
        r1[i]++;
        for(i=0;r2[i]=='9';i++)r2[i]='0';
        r2[i]++;
        while(r1.back()=='0')r1.pop_back();
        while(r2.back()=='0')r2.pop_back();
        reverse(r1.begin(),r1.end());
        reverse(r2.begin(),r2.end());
        if(r1.size()<r2.size())cout<<r1;
        else if(r1.size()>r2.size())cout<<r2;
        else cout<<min(r1,r2);
    }
}
