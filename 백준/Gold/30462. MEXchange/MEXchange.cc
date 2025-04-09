#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%d",&n);
    vector<int> v(n);
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
        if(i&&v[i]<v[i-1])return !printf("No");
        if(i+2<v[i])return !printf("No");
    }
    if(v.back()!=n+1)return !printf("No");
    printf("Yes\n");
    vector<int> ans(n);
    set<int> se;
    for(int i=1;i<=n;i++)se.insert(i);
    for(int i=1;i<n;i++)if(v[i-1]!=v[i])ans[i]=v[i-1],se.erase(v[i-1]);
    for(int i=n-1;i>=0;i--)if(!ans[i])ans[i]=*prev(se.end()),se.erase(ans[i]);
    for(auto i:ans)printf("%d ",i);
}