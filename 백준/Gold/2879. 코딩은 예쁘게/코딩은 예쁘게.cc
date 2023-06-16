#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%d",&n);
    vector<int> a(n),b(n),c;
    int pre=0;
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
        c.push_back(pre-b[i]+a[i]);
        pre=b[i]-a[i];
    }
    int pl=0,mi=0;
    for(int i=0;i<n;i++)c[i]>0?pl+=c[i]:mi-=c[i];
    printf("%d",max(pl,mi));
    return 0;
}
