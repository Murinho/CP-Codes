#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int c=0;
    for(int i=0;i<1024;i++){
        int t=i^(i>>1);
        if(__popcount(t)==5)
            cout<<bitset<10>(i^(i>>1))<<" "<<c++<<"\n";
    }
}