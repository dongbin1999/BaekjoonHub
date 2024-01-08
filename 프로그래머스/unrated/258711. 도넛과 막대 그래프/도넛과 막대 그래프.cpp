#include<bits/stdc++.h>
using namespace std;

int u[1000001],in[1000001],out[1000001],exist[1000001];

//union-find
int find(int a){return u[a]<0?a:u[a]=find(u[a]);}
bool merge(int a,int b){
    a=find(a),b=find(b);
    if(a==b)return false;
    u[a]+=u[b],u[b]=a;
    return true;
}

vector<int> solution(vector<vector<int>> edges) {
    int add=-1,doughnut=0,stick=0,eight=0;

    for(auto i:edges)in[i[1]]++,out[i[0]]++,exist[i[1]]=exist[i[0]]=1;
    
    //생성한 정점 찾기. (특징 : 나가는 간선 2개 이상, 들어오는 간선 없음)
    for(int i=1;i<=1000000;i++)if(out[i]>=2&&!in[i]){add=i;break;}
    
    //생성한 정점과 직접 이어진 간선들 모두 제거.
    for(auto i:edges)if(i[0]==add||i[1]==add)in[i[1]]--,out[i[0]]--;
    exist[add]=0;
    
    //막대 모양 그래프 특징 : 나가는 간선이 없는 정점이 유일하게 존재.
    //8자 모양 그래프 특징 : 나가는 간선, 들어오는 간선이 각각 정확히 2개인 정점이 유일하게 존재.
    for(int i=1;i<=1000000;i++){
        if(exist[i]&&!out[i])stick++;
        if(in[i]==2&&out[i]==2)eight++;
    }
    
    //그래프 연결 후,
    memset(u,-1,sizeof(u));
    for(auto i:edges){
        int s=i[0],e=i[1];
        if(s==add)continue;
        merge(s,e);
    }
    
    int all=0;
    //그래프 덩어리 개수 세기.
    for(int i=1;i<=1000000;i++)all+=exist[i]&&i==find(i);
    
    //남은 덩어리는 도넛 모양 그래프의 개수.
    doughnut=all-stick-eight;
    return {add,doughnut,stick,eight};
}