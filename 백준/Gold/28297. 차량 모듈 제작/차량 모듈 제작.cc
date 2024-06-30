#include<bits/stdc++.h>
using namespace std;
typedef double d;
typedef array<d,3> arr;
typedef tuple<d,int,int> tup;
const d pi=acos(-1);

int u[1001];
int find(int x){return u[x]<0?x:u[x]=find(u[x]);}
bool merge(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return 0;
    if(-u[x]<-u[y])swap(x,y);
    u[x]+=u[y],u[y]=x;
    return 1;
}

d dist(arr a,arr b){return sqrt((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]));}
d L(arr a,arr b){
    d D=dist(a,b);
    if(D<=a[2]+b[2])return 0.0;
    if(a[2]<b[2])swap(a,b);
    double S=a[2]-b[2];
    d cx=S/D,x=acos(cx);
    d ret=2.0*sqrt(D*D-S*S);
    ret+=((pi-x)*2*a[2])+(x*2*b[2]);
    return ret;
}

int main(){
    memset(u,-1,sizeof(u));
    int n;scanf("%d",&n);
    vector<arr> a(n);
    for(auto &[x,y,r]:a)scanf("%lf%lf%lf",&x,&y,&r);
    priority_queue<tup,vector<tup>,greater<tup>> pq;
    for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)
        pq.push({L(a[i],a[j]),i,j});
    d ans=0.0;
    while(!pq.empty()){
        auto [len,l,r]=pq.top();pq.pop();
        if(merge(l,r))ans+=len;
    }
    printf("%.10lf",ans);
}