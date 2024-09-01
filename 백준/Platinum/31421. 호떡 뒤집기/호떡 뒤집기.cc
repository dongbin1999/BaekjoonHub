#include<bits/stdc++.h>
using namespace std;

char s[500005];

int main(){
    int n;scanf("%d %s",&n,s+1);
    vector<int> ans;
    for(int i=1;i<n;i++)if(s[i]!=s[i+1])ans.push_back(i);
    if(s[n]=='W'){
        printf("%d\n",ans.size());
        for(auto i:ans)printf("%d\n",i);
        return 0;
    }
    if(ans.size()<2)return !printf("-1");
    swap(ans[ans.size()-2],ans.back());
    printf("%d\n",ans.size());
    for(auto i:ans)printf("%d\n",i);
}