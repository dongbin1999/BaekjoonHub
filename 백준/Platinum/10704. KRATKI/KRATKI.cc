#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;scanf("%d%d",&n,&k);
    deque<int> dq;
    int x=k,y=0;
    while(1){
        y++;
        for(int i=x,j=(x-1)/k*k;i>j;i--)dq.push_front(i);
        if(x==n)break;
        x=min(x+k,n);
    }
    if(y>k)return !printf("-1");
    for(auto i:dq)printf("%d ",i);
    return 0;
}