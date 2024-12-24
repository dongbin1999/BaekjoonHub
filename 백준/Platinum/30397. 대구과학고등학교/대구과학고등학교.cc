#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    multiset<int> a,b;
    for(int i=0;i<n;i++){
        int x;scanf("%d",&x);
        a.insert(x);
    }
    for(int i=0;i<n;i++){
        int x;scanf("%d",&x);
        b.insert(-x);
    }
    int ans=0,cnt=n;
    vector<int> aa;
    for(auto i:a){
        auto it=b.upper_bound(-i);
        if(it!=b.end())aa.push_back(i),b.erase(it),ans+=100,cnt--;
    }
    while(!aa.empty())a.erase(a.find(aa.back())),aa.pop_back();

    for(auto i:a){
        auto it=b.lower_bound(-i);
        if(it!=b.end())aa.push_back(i),b.erase(it),ans+=20,cnt--;
    }
    ans-=50*cnt;
    printf("%d",ans);
}