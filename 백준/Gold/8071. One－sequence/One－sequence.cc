#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,s;scanf("%d%d",&n,&s);
    int x=n*(n-1)/2;
    if(x<abs(s)||(x+s)%2)
        return !printf("NIE");
    int mi=1;
    if(s<0)s*=-1,mi=-1;
    vector<int> v={0};
    while(v.size()<n){
        x=v.back();
        int l,r,sum;
        r=x+1,l=r-(n-v.size())+1,sum=(l+r)*(r-l+1)/2;
        //printf("%d %d %d\n",l,r,sum);
        if(s>=sum)v.push_back(r),s-=v.back();
        else v.push_back(x-1),s-=v.back();
    }

    for(auto i:v)printf("%d\n",i*mi);
}