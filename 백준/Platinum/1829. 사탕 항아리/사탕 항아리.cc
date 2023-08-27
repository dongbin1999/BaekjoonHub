#include <bits/stdc++.h>
using namespace std;

map<int,vector<int>> v;//숫자, 그 크기의 숫자들의 위치
vector<pair<int,vector<int>>> f(){
    vector<pair<int,vector<int>>> ret;
    map<int,vector<int>> ma;
    for(auto [a,b]:v){
        int x=a,d=1;
        while(x){
            if(x&1)for(auto i:b)ma[d].push_back(i);
            x>>=1,d<<=1;
        }
    }
    map<vector<int>,int> ma2;
    for(auto [x,y]:ma)ma2[y]+=x;
    for(auto [x,y]:ma2)ret.push_back({y,x});
    return ret;
}

int main() {
    int n,k;scanf("%d%d",&n,&k);
    for(int i=k;i<n+k;i++)v[i].push_back(i-k+1);
    vector<pair<int,vector<int>>> init=f();
    pair<int,vector<pair<int,vector<int>>>> ans={init.size(),init};

    vector<pair<int,vector<int>>> pre;
    while(v.size()>1){
        vector<int> mi;
        map<int,vector<int>> vv;
        int half=v.size()/2;
        for(auto [a,b]:v)
            if(k+half<=a){
                for(auto x:b)mi.push_back(x),vv[a-half].push_back(x);
            }
            else{
                for(auto x:b)vv[a].push_back(x);
            }
        v=vv;
//        for(auto [x,y]:v){
//            printf("%d : ",x);
//            for(auto i:y)printf("%d ",i);
//            printf("\n");
//        }
        vector<pair<int,vector<int>>> tmp=f();
//        for(auto [x,y]:tmp){
//            printf("[%d] :",x);
//            for(auto i:y)printf("%d ",i);
//            printf("\n");
//        }
        pre.push_back({half,mi});
        for(auto i:pre)tmp.push_back(i);
        ans=min(ans,{tmp.size(),tmp});
    }

    printf("%d\n",ans.first);
    for(auto [x,y]:ans.second){
        printf("%d %d\n",y.size(),x);
        for(auto j:y)printf("%d ",j);
        printf("\n");
    }
    return 0;
}