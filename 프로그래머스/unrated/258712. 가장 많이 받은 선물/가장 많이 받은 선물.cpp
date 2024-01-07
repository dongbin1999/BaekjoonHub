#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    map<string,map<string,int>> ma;
    map<string,int> gift;
    for(auto i:gifts){
        string a,b;
        int idx=0;
        while(i[idx]!=' ')idx++;
        for(int j=0;j<idx;j++)a+=i[j];
        for(int j=idx+1;j<i.size();j++)b+=i[j];
        ma[a][b]++,ma[b][a]--;
        gift[a]++,gift[b]--;
    }
    vector<int> ans(friends.size());
    for(int i=0;i<friends.size();i++)
        for(int j=0;j<friends.size();j++){
            if(i==j)continue;
            string a=friends[i],b=friends[j];
            if(ma[a][b]>0||(ma[a][b]==0&&gift[a]>gift[b]))
                ans[i]++;
        }
    return *max_element(ans.begin(),ans.end());
}