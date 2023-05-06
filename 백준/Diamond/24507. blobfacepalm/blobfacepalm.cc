#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;scanf("%d",&n);
	if(n%4==0){
		printf("Yes\n");
		vector<int> ans(n+n,0),v[2],vis(n,0);
		for(int i=n-1;i>=1;i--)v[i%2].push_back(i);
		for(int i=0;i<v[1].size();i++)ans[i]=ans[i+v[1][i]+1]=v[1][i];
		vis[v[0][0]]=1, ans[n/2]=ans[n/2+v[0][0]+1]=v[0][0];
		int x=n/2+v[0][0]+2,y=n+1;
		if(x-y-1) vis[x-y-1]=1,ans[x]=ans[y]=x-y-1;
		for(int i=n+2,j=0;j<v[0].size();j++){
			if(vis[v[0][j]])continue;
			vis[v[0][j]]=1,ans[i]=ans[i+v[0][j]+1]=v[0][j];
			i++;
		}
		for(auto i:ans)printf("%d ",i);
		
	}
	else if(n%4==1){
		printf("Yes\n");
		if(n==1)return !printf("0 0");
		else if(n==5)return !printf("4 1 3 1 2 4 3 2 0 0");
		vector<int> ans(n+n,0),v[2],vis(n+1,0);
		for(int i=n-1;i>=1;i--)v[i%2].push_back(i);
		for(int i=0;i<v[0].size();i++)ans[i]=ans[i+v[0][i]+1]=v[0][i];
		vis[v[1][0]]=1, ans[n/2+1]=ans[n/2+1+v[1][0]+1]=v[1][0];
		int x=n+1,y=n/2;
		vis[x-y-1]=1,ans[x]=ans[y]=x-y-1;
		for(int i=n+2,j=0;j<v[1].size();j++){
			if(vis[v[1][j]])continue;
			vis[v[1][j]]=1,ans[i]=ans[i+v[1][j]+1]=v[1][j];
			i++;
		}
		for(auto i:ans)printf("%d ",i);
	}
	else printf("No");
	return 0;
}