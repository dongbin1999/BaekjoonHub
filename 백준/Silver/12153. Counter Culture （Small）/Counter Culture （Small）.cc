#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int v[1000001];
int rev(int x){
    string s= to_string(x);
    reverse(s.begin(),s.end());
    return stoi(s);
}
int main(){
    memset(v,-1,sizeof(v));
    queue<pii> q;
    q.push({1,1});v[1]=1;
    while(!q.empty()){
        auto [x,d]=q.front();q.pop();
        int nx=x+1;
        if(v[nx]==-1){
            v[nx]=d+1;
            q.push({nx,d+1});
        }
        nx=rev(x);
        if(nx>x&&v[nx]==-1){
            v[nx]=d+1;
            q.push({nx,d+1});
        }
    }
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        printf("Case #%d: %d\n",i,v[x]);
    }
}