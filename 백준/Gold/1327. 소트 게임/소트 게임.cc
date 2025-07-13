#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;scanf("%d%d",&n,&k);
    unordered_map<string,int> ma;
    string init,ans;
    for(int i=0;i<n;i++){
        char c;scanf(" %c",&c);
        init+=c;
    }
    ma[init]=0;
    ans=init,sort(ans.begin(),ans.end());
    queue<string> q;q.push(init);
    while(!q.empty()){
        auto x=q.front();q.pop();
        int d=ma[x];
        if(ans==x)return !printf("%d",d);
        for(int i=0;i+k-1<n;i++){
            auto nx=x;
            reverse(nx.begin()+i,nx.begin()+i+k);
            if(!ma.count(nx))q.push(nx),ma[nx]=d+1;
        }
    }
    printf("-1");
}