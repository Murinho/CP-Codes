#include <bits/stdc++.h>
using namespace std;

int h,w,k,i,t,cnt=0;

void print(char c){
    cout<<c;
    cnt++;
    if(cnt==w){
        cout<<"\n";
        cnt=0;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>h>>w>>k>>i>>t;
    i--,t--;
    for(int j=0;j<i;j++)print('I');
    for(int j=0;j<t;j++)print('T');
    for(int j=0;j<k;j++)print('K');
    print('I');
    print('T');
}