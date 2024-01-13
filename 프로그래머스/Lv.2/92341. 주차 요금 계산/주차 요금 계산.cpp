#include<bits/stdc++.h>
using namespace std;

int ans[10000],exist[10000];

int cal(int x,vector<int> &fees){
    int ret=fees[1],extra=x-fees[0];
    int unit=max(0,(extra+fees[2]-1)/fees[2]);
    return ret+unit*fees[3];
}

vector<int> solution(vector<int> fees, vector<string> records) {
    map<int,int> ma;
    for(auto record:records){
        int t=stoi(record.substr(0,2))*60+stoi(record.substr(3,2));
        int car=stoi(record.substr(6,4));
        exist[car]=1;
        if(record.substr(11)=="IN")ma[car]=t;
        else ans[car]+=t-ma[car],ma[car]=60*24-1;
    }
    for(auto [car,t]:ma)ans[car]+=60*24-1-t;
    
    vector<int> answer;
    for(int i=0;i<=9999;i++)if(exist[i])answer.push_back(cal(ans[i],fees));
    return answer;
}