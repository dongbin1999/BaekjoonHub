#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

const int sz=5000000;
int up[sz+1];
pii ans[sz+2];

vector<int> solution(int e, vector<int> starts) {
    for(int i=1;i<=e;i++)
        for(int j=i;j<=e;j+=i)
            up[j]++;
    vector<int> answer;
    memset(ans,0x3f,sizeof(ans));
    for(int i=e;i>=1;i--)
        ans[i]=min(ans[i+1],{-up[i],i});
    for(auto i:starts)answer.push_back(ans[i].second);
    return answer;
}