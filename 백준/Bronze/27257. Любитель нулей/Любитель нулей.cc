#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    while(s.back()=='0')s.pop_back();
    int ans=0;
    for(auto i:s)ans+=i=='0';
    cout<<ans;
}