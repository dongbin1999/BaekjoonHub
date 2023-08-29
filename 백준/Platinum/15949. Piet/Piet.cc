#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define mx(a,b) a=max(a,b)
#define mn(a,b) a=!a?b:min(a,b)

pii go[4]={{0,1},{1,0},{0,-1},{-1,0}};//RDLU
int dp=0,cc=3,numbering,block[102][102],bound[10002][4];
char a[102][102];

pii get_codel(int num,int dpdir,int codeldir){
    int b=bound[num][dpdir];
    if(codeldir==0)for(int i=100;i>=1;i--)if(block[b][i]==num)return{b,i};
    if(codeldir==2)for(int i=1;i<=100;i++)if(block[b][i]==num)return{b,i};
    if(codeldir==1)for(int i=100;i>=1;i--)if(block[i][b]==num)return{i,b};
    if(codeldir==3)for(int i=1;i<=100;i++)if(block[i][b]==num)return{i,b};
    return {-1,-1};
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<102;i++)for(int j=0;j<102;j++)a[i][j]='X';
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf(" %c",&a[i][j]);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        if(block[i][j]||a[i][j]=='X')continue;
        block[i][j]=++numbering;
        char al=a[i][j];
        queue<pii> q;q.push({i,j});
        while(!q.empty()){
            auto [x,y]=q.front();q.pop();
            mx(bound[numbering][0],y),mn(bound[numbering][2],y);
            mx(bound[numbering][1],x),mn(bound[numbering][3],x);
            for(auto [dx,dy]:go){
                int nx=x+dx,ny=y+dy;
                if(nx<1||nx>n||ny<1||ny>m||block[nx][ny]||a[nx][ny]!=al)continue;
                q.push({nx,ny}),block[nx][ny]=numbering;
            }
        }
    }
    string ans;
    int x=1,y=1;
    while(1){
        ans.push_back(a[x][y]);
        bool move=0;
        int TRY=8;
        do{
            int dpdir=dp%4,codeldir=(dp+cc)%4;
            pii codel=get_codel(block[x][y],dpdir,codeldir);
            auto [cx,cy]=codel;auto [dx,dy]=go[dpdir];
            if(a[cx+dx][cy+dy]!='X'){
                x=cx+dx,y=cy+dy,move=1;
                break;
            }
            if(TRY%2)dp++;else cc+=2;
        }while(--TRY);
        if(!move)break;
    }
    cout<<ans;
}