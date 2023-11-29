#include <bits/stdc++.h>
using namespace std;
int ans=0;

string s;
void go(int idx,bool nine,int val){
    if(idx>=s.size()){
        ans=max(ans,val);
        return;
    }
    go(idx+1,nine,val*(s[idx]-'0'));
    if(nine)go(idx+1,nine,val*9);
    go(idx+1,nine|1,val*(s[idx]-'0'-1));
}

int main() {
    cin>>s;
    go(0,0,1);
    if(s[0]=='1'&&s.size()>1)go(1,1,1);
    cout<<ans;
}