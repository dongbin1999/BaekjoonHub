#include <bits/stdc++.h>
using namespace std;
char a[1000],b[1000];
void solve(){
    scanf("%s %s",a,b);
    int q=0,n=strlen(a),m=strlen(b),z[2]={0},o[2]={0};
    for(int i=0;i<n;i++){
        z[0]+=a[i]=='0';
        z[1]+=b[i]=='0';
        o[0]+=a[i]=='1';
        o[1]+=b[i]=='1';
        if(a[i]=='?')q++;
    }
    if(n!=m||z[0]+q<z[1]){printf("-1\n");return;}
    int ans=0;
    for(int i=0;i<n;i++)if(a[i]=='?'){
        if(z[0]<z[1]&&b[i]=='0')a[i]='0',z[0]++,ans++;
        else if(o[0]<o[1]&&b[i]=='1')a[i]='1',o[0]++,ans++;
        else if(z[0]<z[1])a[i]='0',z[0]++,ans++;
        else a[i]='1',o[0]++,ans++;
    }
    if(z[0]>z[1]){
        for(int i=0;i<n&&z[0]>z[1];i++)
            if(a[i]=='0'&&b[i]=='1') a[i]='1',z[0]--,o[0]++,ans++;
        for(int i=0;i<n&&z[0]>z[1];i++)
            if(a[i]=='0') a[i]='1',z[0]--,o[0]++,ans++;
    }
    int tmp=0;
    for(int i=0;i<n;i++)tmp+=a[i]!=b[i];
    ans+=(tmp+1)/2;
    printf("%d\n",ans);
}
int main(){
    int t;scanf("%d",&t);
    for(int i=1;i<=t;i++){
        printf("Case %d: ",i);
        solve();
    }
}