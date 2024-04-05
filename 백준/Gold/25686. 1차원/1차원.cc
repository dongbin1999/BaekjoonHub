#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    vector<int> v={1};
    while(v.size()<n){
        for(auto &i:v)i*=2;
        for(int i=v.size()-1;i>=0;i--)v.push_back(v[i]-1);
    }
    vector<int> ans;
    for(auto i:v)if(i<=n)ans.push_back(i);
    for(auto i:ans)printf("%d ",i);
    return 0;
}