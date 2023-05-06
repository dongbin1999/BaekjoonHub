#include <bits/stdc++.h>
using namespace std;
struct Q{int l,r,idx;};

int a[100001],group[350],root,mid=100000;
deque<int> dq[200001];

void add(int x,int idx,bool lr){
	int t; x+=mid;
	if(!dq[x].empty()){
		t=dq[x].back()-dq[x].front();
		group[t/root]--,a[t]--;
	}
	lr?dq[x].push_back(idx):dq[x].push_front(idx);
	t=dq[x].back()-dq[x].front();
	group[t/root]++,a[t]++;
}
void del(int x,int idx,bool lr){
	int t; x+=mid;
	t=dq[x].back()-dq[x].front();
	group[t/root]--,a[t]--;
	lr?dq[x].pop_back():dq[x].pop_front();
	if(!dq[x].empty()){
		t=dq[x].back()-dq[x].front();
		group[t/root]++,a[t]++;
	}
}

int f(int n){
	for(int i=n/root;i>=0;i--)
		if(group[i])
			for(int j=(i+1)*root;j>=i*root;j--)
				if(a[j])return j;
	return 0;			
}

int main(){
	int n;scanf("%d",&n);
	root=sqrt(n);
	vector<int> A(n+1,0);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]),A[i]+=A[i-1];
	int m;scanf("%d",&m);
	vector<Q> v(m);
	vector<int> ans(m);
	for(int i=0;i<m;i++)scanf("%d%d",&v[i].l,&v[i].r),v[i].l--,v[i].idx=i;
	sort(v.begin(),v.end(),[](Q a,Q b){
		int x=a.l/root,y=b.l/root;
		return x==y?a.r<b.r:x<y;
	});
	
	int l=v[0].l,r=v[0].r;
	for(int i=l;i<=r;i++)add(A[i],i,1);
	for(auto cur:v){
		while(cur.l<l)add(A[--l],l,0);
		while(r<cur.r)add(A[++r],r,1);
		while(cur.l>l)del(A[l],l,0),l++;
		while(r>cur.r)del(A[r],r,1),r--;
		ans[cur.idx]=f(n);
	}
	for(auto i:ans)printf("%d\n",i);
    return 0;
}