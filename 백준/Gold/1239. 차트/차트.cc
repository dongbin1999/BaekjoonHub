#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    vector<int> v(n);
    for(auto &i:v)scanf("%d",&i);
    sort(v.begin(),v.end());
    int ans=0;
    do{
        int tmp=0,l=0,r=n-1,lx=v[l],rx=v[r],h=v[l],p=0;
        while(l<r){
            if(lx==rx)tmp++,lx=v[++l],h+=v[l],rx=v[--r],p=v[l];
            else if(lx<rx)lx+=v[++l],h+=v[l],p=v[l];
            else rx+=v[--r];
        }
        if(h-p==50)ans=max(ans,tmp);
    }while(next_permutation(v.begin(),v.end()));
    printf("%d",ans);
}