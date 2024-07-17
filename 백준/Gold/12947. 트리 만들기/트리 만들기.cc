#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    vector<int> v(n);
    for(int i=0;i<n;i++)scanf("%d",&v[i]);
    int ans=0,x=0,y=0;
    for(int i=n-1;i>=0;i--){
        if(v[i]==1)ans=max(ans,x+y);
        x++,y++;
        if(v[i]==1)y=0;
    }
    ans=max(ans,x+y);
    printf("%d",ans);
}