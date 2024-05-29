#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b;scanf("%d%d%d",&n,&a,&b);
    int x=0,B,ans=0; if(!n)ans--;//0 제외
    while(n--)scanf("%d",&B),x+=1<<B;
    //mod a가 key인 수들의 집합
    unordered_map<int,vector<int>> X,Y;
    for(int i=0;i<1<<16;i++){
        bool ok=1;for(int j=0;j<16;j++)if((x>>j&1)&&!(i>>j&1))ok=0;
        if(ok)X[i%a].push_back(i);
    }
    x>>=16;
    for(int i=0;i<1<<15;i++){
        bool ok=1;for(int j=0;j<15;j++)if((x>>j&1)&&!(i>>j&1))ok=0;
        if(ok)Y[(i<<16)%a].push_back(i<<16);
    }
    
    for(auto [mod,V]:Y){
        int m=(a-mod)%a;
        for(auto i:V){
            if(i>b)continue;
            auto idx=upper_bound(X[m].begin(),X[m].end(),b-i)-X[m].begin();
            ans+=idx;
        }
    }
    printf("%d",ans);
    return 0;
}