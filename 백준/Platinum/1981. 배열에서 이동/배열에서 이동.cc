#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define in(s,e,k) (s<=k&&k<=e)
pii go[4]={{0,1},{0,-1},{1,0},{-1,0}};

int a[100][100],vis[100][100];
int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&a[i][j]);
    int ans=200;
    for(int s=0;s<=200;s++){
        int l=0,r=200-s,mid;
        while(l<=r){
            mid=(l+r)/2;
            int e=s+mid;
            memset(vis,0,sizeof(vis));
            queue<pii> q;
            if(in(s,e,a[0][0]))q.push({0,0});
            while(!q.empty()){
                auto [x,y]=q.front();q.pop();
                for(auto [dx,dy]:go){
                    int nx=dx+x,ny=dy+y;
                    if(nx<0||nx>=n||ny<0||ny>=n||vis[nx][ny])continue;
                    if(in(s,e,a[nx][ny]))vis[nx][ny]=1,q.push({nx,ny});
                }
            }
            if(vis[n-1][n-1])ans=min(ans,mid),r=mid-1;
            else l=mid+1;
        }
    }
    printf("%d",ans);
    return 0;
}