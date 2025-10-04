#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    int ans=1,c=1;
    for(int i=1;i<s.size();i++){
        if(s[i-1]<s[i])c++;
        else c=1;
        ans+=c;
    }
    cout<<ans;
}
