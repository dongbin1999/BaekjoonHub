#include<bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> S) {
    vector<string> answer;
    for(auto s:S){
        int zzo=0,i=0;
        string ns;
        while(i<s.size()){
            ns+=s[i++];
            while(ns.size()>=3&&ns.substr(ns.size()-3,3)=="110")
                zzo++,ns.pop_back(),ns.pop_back(),ns.pop_back();
        }
        string x;i=0;
        while(i<ns.size()){
            x+=ns[i++];
            if(x.size()>=3&&x.substr(x.size()-3,3)=="111"){
                x.pop_back();x.pop_back();x.pop_back();
                if(zzo>0)while(zzo--)x+="110";
                x+="111";
            }
        }
        string y;
        while(!x.empty()&&x.back()=='1')y+='1',x.pop_back();
        if(zzo>0)while(zzo--)x+="110";
        while(!y.empty())x+=y.back(),y.pop_back();
        answer.push_back(x);
    }
    return answer;
}