#include<bits/stdc++.h>

using namespace std;

int x;

int main(){
    cin>>x;
    if(x<=-3){
        cout<<-(x+4)*(x+4)+8;
        return 1<<32;
    }
    if(x>-3 && x<=2){
        cout<<-2*x+1;
        return 1<<32;
    }
    cout<<x*x*x-14*x+17;
}