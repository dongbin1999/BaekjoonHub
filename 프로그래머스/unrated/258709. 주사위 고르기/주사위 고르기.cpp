#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<vector<int>> dice) {
    pair<int,vector<int>> ans={-1,{}};
    int n=dice.size();
    for(int s=0;s<1<<n;s++){
        if(__builtin_popcount(s)!=n/2)continue;
        vector<int> a(501);a[0]=1;//a[i]:A가 B보다 i점 높은 경우의 수
        vector<int> A_dice;
        
        //A가 얻는 점수.
        for(int j=0;j<n;j++)
        if(s>>j&1){
            vector<int> nx(501);
            for(int i=0;i<=500;i++)
                if(a[i])for(auto add:dice[j])nx[add+i]+=a[i];
            a=nx;
            A_dice.push_back(j+1);
        }
        
        //B가 얻는 점수.
        for(int j=0;j<n;j++){
        if(s>>j&1)continue;
            vector<int> nx(501);
            for(int i=0;i<=500;i++)
                for(auto del:dice[j])nx[max(0,i-del)]+=a[i];
            a=nx;
        }
        
        int number_of_win=0;
        //A가 1점이라도 높으면 승리.
        for(int i=1;i<=500;i++)number_of_win+=a[i];
        ans=max(ans,{number_of_win,A_dice});
    }
    return ans.second;
}