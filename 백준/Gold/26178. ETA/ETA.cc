#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main(){
    int x,y;scanf("%d/%d",&x,&y);
    if(y==1)x*=2,y*=2;
    deque<pii> v;
    int sum=0,n=0,s=0;
    while(1){
        s+=x,n+=y;
        if(n>1e6||s+1<n)return !printf("impossible");
        if(v.empty())v.push_back({1,2}),sum+=1;
        while(v.back().second<n)v.push_back({v.back().second,v.back().second+1}),sum+=v.back().first;
        if(sum>=s)break;
    }

    while(sum>s){
        auto [a,b]=v.back();
        int d=min(sum-s,a-1);
        if(d<=0)break;
        sum-=d,v.pop_back(),v.push_front({a-d,b});
    }
    if(sum!=s)return !printf("impossible");
    printf("%d %d\n",n,v.size());
    for(auto [a,b]:v)printf("%d %d\n",a,b);
    return 0;
}