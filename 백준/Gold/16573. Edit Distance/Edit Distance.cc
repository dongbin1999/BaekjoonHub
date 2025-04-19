#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;cin>>s;
    int o=0,z=0;
    for(int i=0;i<s.size();i++)o+=s[i]=='1';
    z=s.size()-o;
    string ss(s.size(),z>o?'1':'0');
    if(o==z){
        ss[0]=s[0]^1;
        for(int i=1;i<s.size();i++)ss[i]=s[0];
    }
    cout<<ss;
}