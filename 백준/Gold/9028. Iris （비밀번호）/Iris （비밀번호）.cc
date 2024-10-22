#include<bits/stdc++.h>
using namespace std;

char a[20],b[300000];

void solve(){
    scanf("%s",a+1);
    getchar();
    scanf("%[^\n]",b);
    int n=strlen(b),m=strlen(a+1);
    vector<int> cnt(11),ans;cnt[0]=1e9;
    for(int i=0;i<n;i++)
        for(int j=1;j<=m;j++)if(tolower(a[j])==tolower(b[i])&&cnt[j-1]){
            cnt[j-1]--,cnt[j]++;
            if(j==m)ans.push_back(i+1);
        }
    printf("%d ",ans.size());
    for(int i=0;i<min(3,(int)ans.size());i++)printf("%d ",ans[i]);
    printf("\n");
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
    return 0;
}