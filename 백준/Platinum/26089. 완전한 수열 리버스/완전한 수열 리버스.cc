#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int z=0;z<=n;z++)for(int t=0;t+z<=n;t++)
        if(abs(z-t)<=1&&z-1+z+t-1==m){
            deque<int> dq;
            int f=n-z-t;
            while(z&&t)dq.push_back(0),dq.push_back(2),z--,t--;
            if(z)dq.push_back(0);
            else if(t) dq.push_front(2);
            while(f--)dq.push_back(4);
            for(auto i:dq)printf("%d ",i);
            return 0;
        }
    return 0;
}