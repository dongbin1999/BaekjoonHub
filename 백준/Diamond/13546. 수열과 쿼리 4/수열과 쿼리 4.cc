#include <bits/stdc++.h>
using namespace std;
struct qu{int l,r,idx;};
int a[100500],ans[100500],root;
int group[320],cnt[100500];
deque<int> dq[100500];

void add(int num,int idx,bool b){
	int x;
	if(!dq[num].empty()){
		x=dq[num].back()-dq[num].front();
		cnt[x]--,group[x/root]--;
	}
	b?dq[num].push_back(idx):dq[num].push_front(idx);
	x=dq[num].back()-dq[num].front();
	cnt[x]++,group[x/root]++;
}

void del(int num,int idx,bool b){
	int x;
	x=dq[num].back()-dq[num].front();
	cnt[x]--,group[x/root]--;
	b?dq[num].pop_back():dq[num].pop_front();
	if(!dq[num].empty()){
		x=dq[num].back()-dq[num].front();
		cnt[x]++,group[x/root]++;	
	}
}

int f(int n){
	for(int i=n/root;i>=0;i--){
		if(!group[i])continue;
		for(int j=(i+1)*root-1;j>=i*root;j--)
			if(cnt[j])return j;
	}
	return 0;
}

int main() {
	int n,k;scanf("%d%d",&n,&k);
	root=sqrt(n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int m;scanf("%d",&m);
	vector<qu> v(m);
	for(int i=0;i<m;i++)scanf("%d %d",&v[i].l,&v[i].r),v[i].idx=i;
	sort(v.begin(),v.end(),[](qu a,qu b){
		int ar=a.r/root,br=b.r/root;
		return ar==br? a.l<b.l:ar<br;
	});
	int l=v[0].l,r=v[0].r;
	for(int i=l;i<=r;i++)add(a[i],i,1);
	for(auto cur:v){
		while(cur.l<l)add(a[--l],l,0);
		while(cur.r>r)add(a[++r],r,1);
		while(cur.l>l)del(a[l],l,0),l++;
		while(cur.r<r)del(a[r],r,1),r--;
		ans[cur.idx]=f(n);
	}
	for(int i=0;i<m;i++)printf("%d\n",ans[i]);
	return 0;
}