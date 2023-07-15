#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    vector<int> pl,mi;
    for(int i=0;i<n;i++){
        int a,b;scanf("%d%d",&a,&b);
        pl.push_back(a+b),mi.push_back(a-b);
    }
    return !printf("%d\n",max(*max_element(pl.begin(),pl.end())-*min_element(pl.begin(),pl.end()),
    *max_element(mi.begin(),mi.end())-*min_element(mi.begin(),mi.end())));
}