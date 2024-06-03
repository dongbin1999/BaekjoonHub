#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int u[500000],qnum[500001],snum[1000001],ith,new_setnum;
map<int,int> v[1000001];//집합 i에 포함된 {쿼리순서,정수}.
int find(int x){return u[x]<0?x:u[x]=find(u[x]);}
bool merge(int a,int b){
    a=find(a),b=find(b);
    if(a==b)return false;
    u[a]+=u[b],u[b]=a;
    return true;
}

void init(int n){
    ith=0,new_setnum=n-1;
    for(int i=0;i<n;i++)v[i][ith]=i,snum[i]=i,u[i]=-1;
}

vector<string> solution(int n, vector<vector<int>> queries) {
    init(n);
    vector<string> answer;
    for(auto Q:queries){
        int q=Q[0],x=Q[1],y=Q[2];
        ith++,x=find(x),y=find(y);
        int sx=snum[x],sy=snum[y];
        if(q==1){
            if(sx==sy)continue;
            //y들은 이제부터 무조건 같은 집합에 속하므로, 묶어서 하나의 정수로 취급한다.
            vector<int> M;
            for(auto [a,b]:v[sy])qnum[b]=ith,snum[b]=sx,M.push_back(b);
            for(int i=1;i<M.size();i++)merge(M[i-1],M[i]);
            v[sy].clear(),v[sx][qnum[M[0]]]=M[0];
        }
        else if(q==2){
            vector<int> M;
            //쿼리 순서가 [l~r]인 원소들을 새로운 집합에 옮긴다.
            ++new_setnum;
            int l=qnum[x],r=qnum[y];
            assert(sx==sy);
            auto it=v[sx].lower_bound(l);
            while(it!=v[sx].end()&&it->first<=r){
                int a=it->first,b=it->second;
                qnum[b]=ith,snum[b]=new_setnum,M.push_back(b);
                it=v[sx].erase(it);
            }
            //y들은 이제부터 무조건 같은 집합에 속하므로, 묶어서 하나의 정수로 취급한다.
            for(int i=1;i<M.size();i++)merge(M[i-1],M[i]);
            if(!M.empty())v[snum[M[0]]][qnum[M[0]]]=M[0];
        }
        else{
            if(snum[x]==snum[y])answer.push_back("Yes");
            else answer.push_back("No");
        }
    }
    return answer;
}