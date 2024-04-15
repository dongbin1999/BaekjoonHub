#include<bits/stdc++.h>
using namespace std;
vector<int> tree[10001];
int cnt;
vector<int> num;
int go(int mx,int node=0,int pa=-1){
    int ret=num[node];
    vector<int> child;
    for(auto nx:tree[node])
        if(nx!=pa)child.push_back(go(mx,nx,node));
    sort(child.begin(),child.end());
    for(auto i:child)
        if(ret+i>mx)cnt++;
        else ret+=i;
    return ret;
}

int solution(int k, vector<int> _num, vector<vector<int>> links){
    num=_num;
    for(int i=0;i<links.size();i++)
        for(int j=0;j<2;j++){
            int x=links[i][j];
            if(x!=-1)tree[i].push_back(x),tree[x].push_back(i);
        }
    int ans=1e9,l=*max_element(num.begin(),num.end()),r=1e8,mid;
    while(l<=r){
        mid=(l+r)/2;
        cnt=1;
        go(mid);
        if(cnt<=k)ans=min(ans,mid),r=mid-1;
        else l=mid+1;
    }
    return ans;
}