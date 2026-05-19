#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int h,m;
    cin>>h>>m;
    cout<<(h%30*12==m?"yes":"no")<<"\n";
}