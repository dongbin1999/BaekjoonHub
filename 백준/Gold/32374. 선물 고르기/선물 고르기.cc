#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;scanf("%d%d",&n,&k);
    vector<int> a(n),b(n),c(k);
    for(auto &x:a)scanf("%d",&x);
    for(auto &x:b)scanf("%d",&x);
    for(auto &x:c)scanf("%d",&x);

    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    int i=k-1,j=n-1;
    while(i>=0&&c[i]==b[j])i--,j--;
    int box=b[j],mx=0;
    for(auto &x:a)if(box>=x)mx=max(mx,x);
    printf("%d",mx);
    return 0;
}