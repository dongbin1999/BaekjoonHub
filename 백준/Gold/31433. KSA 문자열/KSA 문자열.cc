#include<bits/stdc++.h>
using namespace std;
char s[1000000];
int main(){
    char ksa[4]="KSA";
    int a[3]={0,0,0},b[3]={0,0,0};
    scanf("%s",s);int n=strlen(s);
    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++)if(s[i]==ksa[(j+b[j])%3])a[j]++,b[j]++;
    int ans=1e9;
    for(int i=0;i<3;i++){
        int need=n-a[i];
        int tmp=need*2;
        int x=max(0,i-need);
        tmp+=x*2;
        ans=min(ans,tmp);
    }
    printf("%d",ans);
}