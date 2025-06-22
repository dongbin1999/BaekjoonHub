#include<bits/stdc++.h>
using namespace std;
typedef array<int,3> arr;
int main(){
    int k;scanf("%d",&k);
    arr ans={INT_MAX};
    for(int i=1;i*i<=k;i++){
        if(k%i)continue;
        ans=min(ans,{i+k/i,i,k/i});
    }
    auto [x,y,z]=ans;
    printf("%d\n",x);
    for(int i=1;i<=z;i++)printf("%d %d\n",i,i+1);
    for(int i=1;i<y;i++)printf("%d %d\n",i,z+i+1);
}