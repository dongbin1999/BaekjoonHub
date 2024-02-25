#include <bits/stdc++.h>
using namespace std;

int graph[501][501];
int main(){
    int V,E,a,b,c;
    scanf("%d %d",&V,&E);
    for(int i=1;i<=V;i++)
        for(int j=1;j<=V;j++)
            graph[i][j] = 1e9;
    while(E--){
        scanf("%d %d %d",&a,&b,&c);
        graph[a][b] = c;
    }

    for(int via=1;via<=V;via++)
    for(int s=1;s<=V;s++)
        for(int e=1;e<=V;e++)
                graph[s][e] = min(graph[s][e],graph[s][via]+graph[via][e]);
    int ans = 1e9;
    for(int i=1;i<=V;i++)
        ans=min(ans,graph[i][i]);
    printf("%d",ans==1e9?-1:ans);
    return 0;
}