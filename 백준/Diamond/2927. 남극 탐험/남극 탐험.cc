#include <bits/stdc++.h>
using namespace std;
const int sz=1<<15;
/*
sub[i]:i의 서브트리 크기
top[i]:i가 속한 체인의 가장 깊이가 얕은 정점번호
in[i]:i의 dfsnumber.
out[i]:i의 자손중 가장 큰 dfsn값.(서브트리에 대한 쿼리에 쓰임)
child[i]:i의 자식노드들.
segtree에 update할때는 dfsn(in[i])을 사용.
*/
int sub[sz],dep[sz],par[sz],top[sz],in[sz],out[sz],arr[sz*2],u[sz],dfsnumbering;
vector<int> tree[sz],child[sz];

int find(int a){
    if(u[a]<0)return a;
    return u[a]=find(u[a]);
}

bool merge(int a,int b){
    a=find(a),b=find(b);
    if(a==b)return false;
    u[a]+=u[b],u[b]=a;
    return true;
}

void update(int i,int val){
    i+=sz,arr[i]=val;
    while(i>>=1)arr[i]=arr[i<<1]+arr[i<<1|1];
}

int query(int s,int e,int node,int ns,int ne){
    if(e<ns||ne<s)return 0;
    if(s<=ns&&ne<=e)return arr[node];
    int mid=(ns+ne)/2;
    return query(s,e,node*2,ns,mid)+query(s,e,node*2+1,mid+1,ne);
}

//sub[i],child[i],par[i],dep[i]구하기.
void dfs(int cur,int pa){
	sub[cur]=1;
	for(auto go:tree[cur])
		if(go!=pa){
			child[cur].push_back(go),par[go]=cur,dep[go]=dep[cur]+1;
			dfs(go,cur); sub[cur]+=sub[go];
		}
}

//cur의 heavy edge를 (cur,child[cur][0]) 으로 만들어줌.
void dfs1(int cur){
	for(auto &go:child[cur]){
		dfs1(go);
		if(sub[go]>sub[child[cur][0]])swap(go,child[cur][0]);
	}
}

void dfs2(int cur){
	in[cur]=++dfsnumbering;
	for(auto go:child[cur]){
		top[go]=go==child[cur][0]?top[cur]:go;
		dfs2(go);
	}
}

int ans(int a,int b){
    int ret=0;
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]])swap(a,b);
        int head=top[a];
        ret+=query(in[head],in[a],1,0,sz-1);
        a=par[head];
    }
    if(dep[a]>dep[b])swap(a,b);
    ret+=query(in[a],in[b],1,0,sz-1);
    return ret;
}

int main(){
    int n;scanf("%d",&n);
    vector<int> v(n+1);
    for(int i=1;i<=n;i++)scanf("%d",&v[i]);
    
    int m;scanf("%d",&m);
    vector<vector<int>> q;
    char s[20];int x,y;
    while(m--){
    	scanf("%s %d %d",s,&x,&y);
    	q.push_back({s[0],x,y});
    }
    
    int root=-1;
    memset(u,-1,sizeof(u));
	for(auto i:q)
		if(i[0]=='b'&&merge(i[1],i[2])){
			tree[i[1]].push_back(i[2]);
			tree[i[2]].push_back(i[1]);
			root=i[1];
		}
		
	for(int i=1;i<=n;i++){
		if(merge(root,i)){
			tree[root].push_back(i);
			tree[i].push_back(root);
		}
	}
    dfs(root,root);dfs1(root);dfs2(root);
	for(int i=1;i<=n;i++)update(in[i],v[i]);
	
	
	memset(u,-1,sizeof(u));
    for(auto i:q){
        if(i[0]=='p')update(in[i[1]],i[2]);
        else if(i[0]=='b')printf(merge(i[1],i[2])?"yes\n":"no\n");
        else{
        	if(find(i[1])!=find(i[2]))printf("impossible\n");
        	else printf("%d\n",ans(i[1],i[2]));
        }
    }
    return 0;
}