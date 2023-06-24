#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main(){
    map<pii,vector<int>> ma;
    ma[{3,2}]={0,0,1,1,0};
    ma[{3,3}]={0,1,1,1,0,0};
    ma[{4,2}]={0,1,1,0,0,0};
    ma[{4,3}]={0,1,0,1,1,0,0};
    ma[{4,4}]={0,1,0,1,1,1,0,0};
    ma[{5,5}]={0,1,0,1,1,0,1,1,0,0};
    int n,m,b=0;scanf("%d%d",&n,&m);
    if(n<m)swap(n,m),b=1;
    int ni=n,mi=m;
    vector<int> v;
    while(n>=1&&m>=2){
        v.push_back(0),v.push_back(1),v.push_back(1);
        n-=1,m-=2;
    }
    v.push_back(0);n--;
    while(m--)v.push_back(1);
    while(n--)v.push_back(0);
    int ans=0;
    if(n<6){
        if(ma[{ni,mi}].size()>0)v=ma[{ni,mi}];
        int nn=v.size();
        for(int len=1;len<nn;len++){
            bool ok=false;
            for(int l=0,r=l+len;r<nn;l++,r++)
                if(v[l]==v[r])ok=true;
            if(ok)ans+=len;
        }
    }
    else ans=(n+m)*(n+m-1)/2;
    printf("%d\n",ans);
    for(auto i:v)printf("%c",'a'+(i^b));
    return 0;
}