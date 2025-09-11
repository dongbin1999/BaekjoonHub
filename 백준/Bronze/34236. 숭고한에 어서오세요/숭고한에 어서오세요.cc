#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    vector<int> v(n);
    for(auto &x:v)scanf("%d",&x);
    printf("%d",v.back()+v[1]-v[0]);
}