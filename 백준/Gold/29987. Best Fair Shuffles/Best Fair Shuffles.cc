#include <bits/stdc++.h>
using namespace std;
int a[1000001];

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        a[x]=i;
    }
    int cnt=0,ans=0;
    for(int i=2;i<=n;i++)cnt+=a[i-1]>a[i];
    while(cnt)ans++,cnt>>=1;
    printf("%d",ans);
}