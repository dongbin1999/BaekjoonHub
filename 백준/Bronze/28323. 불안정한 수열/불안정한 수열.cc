#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    vector<int> v(n);
    for(auto &x:v)scanf("%d",&x),x&=1;
    v.erase(unique(v.begin(),v.end()),v.end());
    printf("%d",v.size());
}