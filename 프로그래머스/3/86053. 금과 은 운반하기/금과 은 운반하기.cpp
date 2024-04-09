#include<bits/stdc++.h>
using namespace std;
typedef __int128 ll;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    int n=g.size();
    ll l=0,r=2e18,mid,ans=2e18;
    while(l<=r){
        mid=l+r>>1;
        ll x=0,y=0,sum=0;
        for(int i=0;i<n;i++){
            ll truck=0,time=mid;
            if(t[i]<=time)truck++,time-=t[i];
            truck+=time/(ll)(t[i]*2);
            x+=min((ll)g[i],truck*(ll)w[i]);
            y+=min((ll)s[i],truck*(ll)w[i]);
            sum+=min(truck*(ll)w[i],(ll)g[i]+(ll)s[i]);
        }
        if(x>=a&&y>=b&&sum>=a+b)ans=min(ans,mid),r=mid-1;
        else l=mid+1;
    }
    return ans;
}