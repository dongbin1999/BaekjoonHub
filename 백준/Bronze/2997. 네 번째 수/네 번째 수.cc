#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v(3);
    for(auto &x:v)scanf("%d",&x);
    sort(v.begin(),v.end());
    if(v[1]+v[1]==v[0]+v[2])printf("%d",v.back()+v[2]-v[1]);
    else printf("%d",v[2]+v[0]-v[1]);
}