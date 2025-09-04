#include<bits/stdc++.h>
using namespace std;

int main(){
    set<string> se;
    int n;cin>>n;
    while(n--){
        string s;cin>>s;
        se.insert(s);
    }
    cin>>n;
    int ans=0;
    while(n--){
        string s;cin>>s;
        ans+=se.count(s);
    }
    cout<<ans;
}