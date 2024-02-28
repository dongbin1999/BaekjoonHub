#include<bits/stdc++.h>
using namespace std;

int f(int distance,vector<int> &rocks,int n){
    int l=1,r=distance,mid,ans=0;
    while(l<=r){
        mid=l+r>>1;
        int cnt=0,x=0,nx=0;
        while(1){
            while(nx<rocks.size()&&rocks[nx]-rocks[x]<mid)nx++;
            cnt+=nx-x-1;
            if(nx==rocks.size())break;
            x=nx;
        }
        if(n>=cnt)ans=max(ans,mid),l=mid+1;
        else r=mid-1;
    }
    return ans;
}


int solution(int distance, vector<int> rocks, int n) {
    rocks.push_back(0),rocks.push_back(distance);
    sort(rocks.begin(),rocks.end());
    int ans=f(distance,rocks,n);
    for(auto &x:rocks)x=distance-x;
    sort(rocks.begin(),rocks.end());
    ans=max(ans,f(distance,rocks,n));
    return ans;
}