#include<bits/stdc++.h>
using namespace std;
char a[1000002],b[1000002];

int main(){
    int n;scanf("%d %s %s",&n,a,b);
    bool d=a[0]!=b[0];int ans=0;
    for(int i=1;i<n;i++){
        bool cd=a[i]!=b[i];
        if(d!=cd)ans++,d^=1;
    }
    if(!ans&&a[0]!=b[0])ans++;
    printf("%d",ans);
    return 0;
}