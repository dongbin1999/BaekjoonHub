#include <bits/stdc++.h>
using namespace std;

vector<int> tree[10001];
int x[10001];

void go(int node, int lv, int pa){
	x[lv]++;
	for(auto to:tree[node])
		if(to!=pa) go(to,lv+1,node);
	return;
}

int main() {
	int n,k;scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++){
		int a,b;scanf("%d%d",&a,&b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	go(1,0,1);
	int ans=0;
	for(int i=0;i<n;i++)ans+=min(k,x[i]);
	printf("%d",ans);
	return 0;
}