#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    vector<int> ans={1},v,a(n,1e9);
    set<int> se;
    for(int i=2;i<=n;i++)se.insert(i);
    for(int i=1;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]>a[i-1])v.push_back(i);
        else if(a[i]<a[i-1]&&!v.empty()){
            se.erase(i),ans.push_back(i);
            se.erase(v.back()),ans.push_back(v.back()),v.pop_back();
        }
    }
    ans.push_back(n),se.erase(n);
    vector<int> x={ans[0]};
    for(int i=1;i<ans.size();i++){
        if(x.back()<ans[i]){
            auto it=se.lower_bound(x.back());
            while(it!=se.end()&&*it<ans[i])x.push_back(*it),se.erase(*it),it=se.lower_bound(x.back());
        }
        else{
            auto it=se.upper_bound(ans[i]);
            while(it!=se.begin()&&*(--it)>x.back())x.push_back(*it),se.erase(*it),it=se.upper_bound(ans[i]);
        }
        x.push_back(ans[i]);
    }
    for(auto i:x)printf("%d ",i);
}