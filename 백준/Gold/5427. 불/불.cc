#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

char s[1001][1001];
bool fire[1001][1001];
bool vis[1001][1001];
pii go[4]={{0,1},{0,-1},{1,0},{-1,0}};

int solve()
{
	int w,h;scanf("%d %d",&h,&w);
		
		for(int i=1;i<=w;i++)
		{
			scanf("%s",s[i]+1);
			fill(vis[i]+1,vis[i]+1+h,false);
			fill(fire[i]+1,fire[i]+1+h,false);
		}
		queue<pair<pii,int>> q[4];
		for(int i=1;i<=w;i++)	
			for(int j=1;j<=h;j++)
            {
                if(s[i][j]=='*') fire[i][j]=true,q[0].push({{i,j},0});
				if(s[i][j]=='@') vis[i][j]=true,q[2].push({{i,j},0});
            }
		int turn=0;
		while(true)
		{
			if(q[turn%2+2].empty()) break;
			
			while(!q[turn%2].empty())
			{
				pair<pii,int> cur=q[turn%2].front();q[turn%2].pop();
				for(auto to:go)
				{
					int x=cur.first.first+to.first,
					y= cur.first.second+to.second;
					if(x<1||x>w||y<1||y>h||s[x][y]=='#'||fire[x][y]) continue;
					fire[x][y]=true,q[(turn+1)%2].push({{x,y},turn+1});
				}
			}
			int t=turn%2+2;
			while(!q[t].empty())
			{
				pair<pii,int> cur=q[t].front();q[t].pop();
				int xx=cur.first.first,yy=cur.first.second;
				if(xx==1||xx==w||yy==1||yy==h) return cur.second+1;
				for(auto to:go)
				{
					int x=cur.first.first+to.first,
					y= cur.first.second+to.second;
					if(x<1||x>w||y<1||y>h||s[x][y]=='#'||fire[x][y]||vis[x][y]) continue;
					vis[x][y]=true,q[(t+1)%2+2].push({{x,y},cur.second+1});
				}	
			}	
			turn++;
		}
		return 1e9;
}

int main() {
	int tc;scanf("%d",&tc);
	while(tc--)
	{
		int ans=solve();
		if(ans==1e9) printf("IMPOSSIBLE\n");
		else printf("%d\n",ans);
	}
	return 0;
}