#include<bits/stdc++.h>

using namespace std;

int main(){

    string a, b;
    cin>>a>>b;

    vector<int> s1(26,0), s2(26,0);

    for(auto c:a)s1[c-'a']++;
    for(auto c:b)s2[c-'a']++;
    
    for(int i=0;i<26;i++){
        for(int j=0;j<max(s1[i],s2[i]);j++){
            char c= i + 'a';
            cout<<(c);
        }
    }

    return 0;
}