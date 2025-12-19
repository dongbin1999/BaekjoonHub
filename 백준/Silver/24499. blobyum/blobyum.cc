#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;scanf("%d%d",&a,&b);b=a-b;
    vector<int> v(a);
    for(auto &x:v)scanf("%d",&x);
    int ans=0,all=accumulate(v.begin(),v.end(),0),sum=0;
    for(int i=0;i<b;i++)sum+=v[i];
    ans=max(ans,all-sum);
    for(int i=0;i<a;i++)sum+=v[(i+b)%a]-v[i],ans=max(ans,all-sum);
    printf("%d",ans);
}