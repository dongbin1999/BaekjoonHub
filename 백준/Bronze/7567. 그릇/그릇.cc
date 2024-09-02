#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;cin>>s;
    int ans=10;
    for(int i=1;i<s.size();i++)
        ans+=5+(s[i]!=s[i-1])*5;
    printf("%d",ans);
}