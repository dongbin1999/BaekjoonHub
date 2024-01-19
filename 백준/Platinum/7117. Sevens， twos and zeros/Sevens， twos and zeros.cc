#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    vector<int> num={0,2,7};
    vector<string> vis(n);
    vis[2%n]="2",vis[7%n]="7";
    queue<int> q;q.push(2%n),q.push(7%n);
    while(!q.empty()){
        int r=q.front();q.pop();
        if(!r){
            for(auto i:vis[0])printf("%c",i);
            return 0;
        }
        if(vis[r].size()==20)continue;
        for(auto nx:num){
            vis[r]+=nx+'0';
            int nr=(r*10+nx)%n;
            if(vis[nr].empty())vis[nr]=vis[r],q.push(nr);
            vis[r].pop_back();
        }
    }
    printf("NAV");
    return 0;
}