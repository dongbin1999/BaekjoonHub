#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;scanf("%d%d",&n,&m);
    if(n==m&&m==1)return !printf("-1");
    vector<int> a(n),b(m);
    int x=5e8,y=10,z=4e5;
    for(int i=-n+1,j=0;i<=n-1;i+=2,j++)a[j]=x+y*i;
    for(int i=-m+1,j=0;i<=m-1;i+=2,j++)b[j]=x+z*i;
    if(n>1){
        a[0]--,a.back()+=3;//avg:a
        a[n/2]--;//cnt:b
    }
    else{
        b[0]-=3,b.back()++;//avg:a
        b[m/2]++;//cnt:b
    }
    set<int>se;
    se.insert(a.begin(), a.end());
    se.insert(b.begin(), b.end());
    assert(se.size()==n+m);
    long long as=0,bs=0;
    for(auto i:a)as+=i,assert(i>=1&&i<=1e9);for(auto i:b)bs+=i,assert(i>=1&&i<=1e9);
    assert(as*m>bs*n);
    for(auto i:a)printf("%d ",i);
    printf("\n");
    for(auto i:b)printf("%d ",i);
}