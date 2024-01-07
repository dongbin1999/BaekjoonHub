#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<vector<int>> dice) {
    pair<int,vector<int>> ans={-1,{}};
    int n=dice.size();
    for(int s=0;s<1<<n;s++){
        if(__builtin_popcount(s)!=n/2)continue;
        vector<int> a(601);a[0]=1;
        vector<int> tmp;
        //A가 얻는 점수.
        for(int j=0;j<n;j++)
        if(s>>j&1){
            tmp.push_back(j+1);
            vector<int> nx(601);
            for(int i=0;i<=600;i++)
                if(a[i])for(auto add:dice[j])nx[add+i]+=a[i];
            a=nx;
        }
        //B가 얻는 점수.
        for(int j=0;j<n;j++){
            if(s>>j&1)continue;
            vector<int> nx(601);
            for(int i=0;i<=600;i++)
                for(auto del:dice[j])nx[max(0,i-del)]+=a[i];
            a=nx;
        }
        int tmpscore=0;
        for(int i=1;i<=600;i++)tmpscore+=a[i];
        ans=max(ans,{tmpscore,tmp});
    }
    return ans.second;
}