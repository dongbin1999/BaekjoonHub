#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(auto &x:v)cin>>x;
    vector<int> vv=v;
    sort(v.begin(),v.end(),greater<int>());
    reverse(vv.begin(),vv.end());
    int ans=0,cur=0;
    for(auto i:vv)if(v[cur]==i)ans++,cur++;
    cout<<n-ans;
    return 0;
}