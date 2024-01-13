#include<bits/stdc++.h>
using namespace std;

vector<int> solution(int n, vector<int> info) {
    pair<int,vector<int>> ans={0,{-1}};
    for(int s=0;s<1<<11;s++){
        int need=0;
        for(int i=0;i<=10;i++)if(s>>i&1)need+=info[i]+1;
        if(need>n)continue;
        int ryan=0,apeach=0;
        for(int i=0;i<=10;i++)
            if(s>>i&1)ryan+=10-i;
            else if(info[i])apeach+=10-i;
        if(ryan<=apeach)continue;
        pair<int,vector<int>> tmp;
        tmp.first=ryan-apeach;
        vector<int> v;
        for(int i=0;i<=10;i++)
            if(s>>i&1)v.push_back(info[i]+1);
            else v.push_back(0);
        v.back()+=n-need;
        reverse(v.begin(),v.end());
        tmp.second=v;
        ans=max(ans,tmp);
    }
    reverse(ans.second.begin(),ans.second.end());
    return ans.second;
}