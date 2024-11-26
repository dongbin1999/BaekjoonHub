#include <bits/stdc++.h>
using namespace std;
typedef array<int,2> pii;
typedef array<int,3> arr;
int main(){
    int n;scanf("%d",&n);
    vector<pii> s(1),b(1);
    for(int i=1;i<=n;i++)s.push_back({i,i}),b.push_back({n+1-i,n+1-i});
    vector<arr> ans;
    while(s!=b){
        int cx=-1,ci=-1,ch=-1;
        for(int i=1;i<n;i++){
            if(b[i][0]!=i)cx=max(cx,b[i][0]);
            if(b[i][1]!=i)cx=max(cx,b[i][1]);
        }
        for(int i=1;i<n;i++)if(b[i][0]==cx){ci=i,cx=b[i][0],ch=0;break;}
        else if(b[i][1]==cx){ci=i,cx=b[i][1],ch=1;break;}
        for(int ni=ci+1;ni<=n;ni++){
            ci=ni-1;int nh,nx;
            if(b[ni][0]<b[ni][1])nh=0,nx=b[ni][0];
            else nh=1,nx=b[ni][1];
            if(nx>=cx)break;
            ans.push_back({ci,cx,nx}),swap(b[ci][ch],b[ni][nh]),ch=nh;
        }
    }
    printf("%d\n",ans.size());
    for(auto [x,y,z]:ans)printf("%d %d %d\n",x,y,z);
}