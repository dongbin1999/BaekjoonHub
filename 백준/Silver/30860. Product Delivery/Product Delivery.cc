#include<bits/stdc++.h>
using namespace std;
int l[1000001],r[1000001];

int main(){
    int n;scanf("%d",&n);
    int cur=-1,ans=1;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&l[i],&r[i]);
        if(cur>r[i])ans++,cur=l[i];
        else cur=max(cur,l[i]);
    }
    printf("%d",ans);
}