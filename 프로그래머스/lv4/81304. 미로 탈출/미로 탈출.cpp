#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tp;

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    int mask=1<<traps.size();
    vector<int> temp(mask,1e9);

    //시작 방에서 i번 방으로 이동하는 최단거리. j는 trap의 bitmask 상태를 나타낸다.
    vector<vector<int>> dist(n+1,temp);

    vector<vector<tp>> temp2(mask);
    vector<vector<vector<tp>>> graph(n+1,temp2);

    //b[i]==-1 : i번 노드는 함정 방이 아니다. / b[i]>=0 : i번 노드는 b[i]번째 함정 방이다.
    vector<int> b(n+1,-1);
    for(int i=0;i<traps.size();i++)b[traps[i]]=i;

    //모든 trap발동 상태에 대해, 간선 방향을 미리 구해둔 그래프를 만든다.
    for(int bit=0;bit<mask;bit++)
        for(auto edge:roads){
            int x=edge[0],y=edge[1],cost=edge[2];
            //현재 간선의 양끝 노드중 하나의 trap만 발동중일 경우, 간선방향을 swap한다.
            if((b[x]>=0&&(bit>>b[x]&1))^(b[y]>=0&&(bit>>b[y]&1)))swap(x,y);
            //노드 x에서, trap발동 상태가 bit일 때, {도착지, 도착했을 때 trap발동 상태, 도착하는 비용}이 담겨있는 간선을 추가한다.
            graph[x][bit].push_back({y,b[y]<0?bit:bit^(1<<b[y]),cost});
        }

    priority_queue<tp,vector<tp>,greater<tp>> pq;
    //아무 트랩도 발동하지 않은 상태에서 start 노드에서 다익스트라 시작.
    pq.push({0,start,0}),dist[start][0]=0;
    while(!pq.empty()){
        auto [cost,node,bit]=pq.top();pq.pop();
        if(cost>dist[node][bit])continue;
        for(auto [nxNode,nxBit,w]:graph[node][bit]){
            if(dist[nxNode][nxBit]>cost+w){
                dist[nxNode][nxBit]=cost+w;
                pq.push({dist[nxNode][nxBit],nxNode,nxBit});
            }
        }
    }
    return *min_element(dist[end].begin(),dist[end].end());
}