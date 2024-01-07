#include<bits/stdc++.h>
using namespace std;

int u[1000001];
int find(int a){
    if(u[a]<0)return a;
    else return u[a]=find(u[a]);
}
bool merge(int a,int b){
    a=find(a),b=find(b);
    if(a==b)return false;
    u[a]+=u[b],u[b]=a;
    return true;
}

vector<int> solution(vector<vector<int>> edges) {
    int add=-1,doughnut=0,stick=0,eight=0;
    vector<int> in(1000001),out(1000001),vis(1000001);
    
    for(auto i:edges)in[i[1]]++,out[i[0]]++,vis[i[1]]=vis[i[0]]=1;
    for(int i=1;i<=1000000;i++)if(out[i]>=2&&!in[i]){add=i;break;}
    
    for(auto i:edges)if(i[0]==add||i[1]==add)in[i[1]]--,out[i[0]]--;
    for(int i=1;i<=1000000;i++){
        if(vis[i]&&i!=add&&!out[i])stick++;
        if(out[i]==in[i]&&out[i]==2)eight++;
    }
    
    memset(u,-1,sizeof(u));
    for(auto i:edges){
        int s=i[0],e=i[1];
        if(s==add)continue;
        merge(s,e);
    }
    
    int all=0;
    for(int i=1;i<=1000000;i++)all+=vis[i]&&i==find(i)&&i!=add;
    doughnut=all-stick-eight;
    return {add,doughnut,stick,eight};
}