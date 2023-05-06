#include <bits/stdc++.h>
using namespace std;

int diff[2][1001][1001];
int ans[1001][1001];

int main() {
	int n,m;scanf("%d %d",&n,&m);
	int d=2*n*m-n-m;
	for(int s=2;s<=n+m;s++)
		for(int x=min(s-1,n);x>=1;x--)
		{
			int y=s-x;if(y>m)continue;
			if(x<n)diff[0][x][y]=d--;
			if(y<m)diff[1][x][y]=d--;
		}
	ans[1][1]=2*n*m-n-m+1;
	for(int x=1;x<=n;x++)
	{
		if(x!=1)ans[x][1]=ans[x-1][1]+pow(-1,(x+1)&1)*diff[0][x-1][1];
		for(int y=2;y<=m;y++)
			ans[x][y]=ans[x][y-1]+pow(-1,(x+y)&1)*diff[1][x][y-1];
	}
	for(int x=1;x<=n;x++)
	{
		for(int y=1;y<=m;y++)printf("%d ",ans[x][y]);
		printf("\n");
	}
	return 0;
}