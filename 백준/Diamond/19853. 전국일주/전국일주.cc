#include <bits/stdc++.h>
using namespace std;
#define Lmove(it) if(it==L.begin())it=L.end();it--;
#define Rmove(it) it++;if(it==L.end())it=L.begin();
struct node{int l,r,v;};
list<node> L;
auto it=L.begin(),go=it,nx=it;

char s[10];
int q(int a,int b){
    printf("? %d %d\n",a,b);
    fflush(stdout);
    scanf("%s",s);
    return s[0]=='M';
}

int main() {
    int n;scanf("%d",&n);
    list<node> L; node in;
    int road[3]={q(1,2),q(2,3),q(3,1)};
    L.push_back({road[2],road[0],1});
    L.push_back({road[0],road[1],2});
    L.push_back({road[1],road[2],3});
    
    it=L.begin();
    for(;it!=L.end();it++)if(it->l!=it->r)break;
    if(it==L.end())it--;

    for(int i=4;i<=n;i++){
        road[0]=q(i,it->v);
        bool b=it->r==road[0];
        go=it;if(b){Lmove(go);}else {Rmove(go)};
        road[1]=q(i,(*go).v);
        if(b){
        	in={road[1],road[0],i};
            go->r=road[1],it->l=road[0];
        	Rmove(go);
        }
        else{
        	in={road[0],road[1],i};
            go->l=road[1],it->r=road[0];
        }
        it=L.insert(go,in);
        nx=it;Lmove(nx); if(nx->l!=nx->r)it=nx;
        nx=it;Rmove(nx); if(nx->l!=nx->r)it=nx;
    }
    auto st=L.begin();
    for(;st!=L.end();st++)if(st->l!=st->r)break;
    printf("! ");
    for(it=st;it!=L.end();it++)printf("%d ",it->v);
    for(it=L.begin();it!=st;it++)printf("%d ",it->v);
    return 0;
}