#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
pii go[4]={{0,1},{0,-1},{1,0},{-1,0}};
char s[5][5];
void solve(int n){
    for(int i=0;i<n;i++)scanf("%s",s[i]);
    int nn=n*n,ans=0;
    for(int i=1;i<1<<nn;i++){
        bool ok=1;
        for(int j=0;j<nn;j++)if((i>>j&1)&&s[j/n][j%n]=='X'){ok=0;break;}
        if(!ok)continue;
        for(int j=0;j<nn;j++){
            if(!(i>>j&1))continue;
            int xx=j/n,yy=j%n;
            for(auto [dx,dy]:go){
                int x=xx,y=yy,cnt=0;
                while(x>=0&&x<n&&y>=0&&y<n&&s[x][y]!='X'){
                    if(i>>(x*n+y)&1)cnt++;
                    x+=dx,y+=dy;
                }
                ok&=cnt==1;
            }
        }
        if(ok)ans=max(ans,__builtin_popcount(i));
    }
    printf("%d\n",ans);
}

int main(){
    int n;
    while(1){
        scanf("%d",&n);
        if(!n)break;
        solve(n);
    }
    return 0;
}