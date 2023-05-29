#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int dest(vector<vector<int>> &tree,vector<int> &road){//x번 노드가 현재 road[x]번째 자식노드를 가리키고 있다. 
    int node=1;// [게임의 규칙] 1.
    while(!tree[node].empty()){// [게임의 규칙] 2.
        int nx=tree[node][road[node]];
        road[node]=(road[node]+1)%tree[node].size();// [게임의 규칙] 3.
        node=nx;
    }
    return node;
}

vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    
    vector<vector<int>> tree(edges.size()+2);
    for(auto i:edges) tree[i[0]].push_back(i[1]);
    
    //[게임의 규칙] 3. 과, 가장 번호가 작은 노드를 가리키는 간선을 초기 길로 설정한다는 조건을 위해 정렬한다.
    for(int i=0;i<tree.size();i++)
        sort(tree[i].begin(),tree[i].end());
    
    vector<int> road(tree.size(),0),v,answer,vis(tree.size(),0);
    vector<pii> range(tree.size(),{0,0});//노드 x에 숫자가 k번 떨어졌다면, k<=range[x]<=3k임을 의미한다.
    
    set<int> se;
    for(int i=0;i<target.size();i++)
        if(target[i]) se.insert(i);
    while(!se.empty()){
        //i+1번 노드의 정보가 target[i]에 있으므로, -1해줘야함.
        int x=dest(tree,road)-1;v.push_back(x);vis[x]++;
        range[x].first+=1,range[x].second+=3;
        if(target[x]<range[x].first) return {-1};
        if(range[x].first<=target[x]&&target[x]<=range[x].second){
            if(se.find(x)!=se.end())se.erase(x);
        }
    }
    for(auto i:v){
        int x=max(1,target[i]-(vis[i]-1)*3);
        target[i]-=x;vis[i]--;
        answer.push_back(x);
    }
    return answer;
}