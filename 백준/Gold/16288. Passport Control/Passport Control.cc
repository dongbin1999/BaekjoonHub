#include<bits/stdc++.h>
using namespace std;
vector<int> asc;
int f(int x){
    int idx=upper_bound(asc.begin(),asc.end(),x)-asc.begin();
    return idx-(asc[idx-1]==x);
}
int main(){
    int n,k;scanf("%d%d",&n,&k);
    vector<int> v(n);
    for(auto &x:v)scanf("%d",&x);
    reverse(v.begin(),v.end());
    for(auto x:v){
        if(asc.empty()){asc.push_back(x);continue;}
        if(asc.back()<x)asc.push_back(x);
        else asc[f(x)]=x;
    }
    printf(asc.size()<=k?"YES":"NO");
}