#include<bits/stdc++.h>

using namespace std;

int string_to_int(string s){
    int p=0;
    for(auto c:s){
        p*=10;
        p+=(c-'0');
    }
    return p;
}

int que(string s){
    cout << s <<"\n";
    cout.flush();
    
    string u,v;
    cin>>u>>v;
    if(v=="GRANTED"){
        return -10;
    }
    string x,y;
    cin>>x>>y;
    x[0]='0';

    return string_to_int(x);

}

int main(){
    int s=0, m=0;
    string res="";
    for(int i=1;i<=20;i++){
        res+="A";
        int r = que(res);
        if(r==-10){
            return 0;
        }
        if(m<r)m=r, s=i;
    }

    res="";
    for(int i=0;i<s;i++)res+="A";

    for(int i=0;i<s;i++){
        m=0;
        char fin = res[i];
        for(int j=0;j<26;j++){
            res[i]=(char)('a'+j);
            int r = que(res);
            if(r==-10){
                return 0;
            }
            if(r>m)m=r, fin=res[i];
        }

        for(int j=0;j<26;j++){
            res[i]=(char)('A'+j);
            int r = que(res);
            if(r==-10){
                return 0;
            }
            if(r>m)m=r, fin=res[i];
        }

        for(int j=0;j<10;j++){
            res[i]=(char)('0'+j);
            int r = que(res);
            if(r==-10){
                return 0;
            }
            if(r>m)m=r, fin=res[i];
        }

        res[i]=fin;
    }
}