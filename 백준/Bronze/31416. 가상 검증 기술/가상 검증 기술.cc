#include <bits/stdc++.h>
using namespace std;
void solve(){
    int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
    int l=1,r=1e4,mid,ans=r;
    while(l<=r){
        int mid=(l+r)/2;
        bool ok=mid>=b*d;
        int cnt=0,dohoon=mid-b*d;
        cnt+=dohoon/a+mid/a;
        ok&=cnt>=c;
        if(ok)ans=min(ans,mid),r=mid-1;
        else l=mid+1;
    }
    printf("%d\n",ans);
}

int main() {
    int tc;scanf("%d",&tc);
    while(tc--)solve();
}