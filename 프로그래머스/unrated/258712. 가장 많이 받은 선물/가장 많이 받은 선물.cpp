#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    map<string,map<string,int>> ma;
    map<string,int> gift;
    string give,get;
    
    for(auto i:gifts){
        istringstream iss(i);
        iss>>give>>get;
        //ma[A][B] : A가 B에게 준 선물 수 - A가 B에게 받은 선물 수
        ma[give][get]++,ma[get][give]--;
        //gift[A] : A의 선물 지수 
        gift[give]++,gift[get]--;
    }
    
    int answer=0;
    map<string,int> ans;
    for(auto a:friends)for(auto b:friends)
        if(ma[a][b]>0||(ma[a][b]==0&&gift[a]>gift[b]))
                ans[a]++,answer=max(answer,ans[a]);

    return answer;
}