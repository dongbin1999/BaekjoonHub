#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<pair<int,string>> v(7);
    for(auto &[x,y]:v)cin>>y>>x;
    sort(v.begin(),v.end());
    cout<<v.back().second;
}