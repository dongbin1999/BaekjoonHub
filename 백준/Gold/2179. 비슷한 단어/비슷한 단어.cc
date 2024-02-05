#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int n;cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    for(int i=100;i>=1;i--){
        unordered_map<string,vector<int>> ma;
        pair<int,int> ans={1e9,1e9};
        for(int j=0;j<n;j++){
            if(v[j].size()<i)continue;
            string sub=v[j].substr(0,i);
            if(ma.count(sub))ans=min(ans,{ma[sub][0],j});
            ma[v[j].substr(0,i)].push_back(j);
        }
        auto [x,y]=ans;
        if(x<1e9){
            cout<<v[x]<<endl<<v[y];
            return 0;
        }
    }
    cout<<v[0]<<endl<<v[1];
    return 0;
}