#include<bits/stdc++.h>
using namespace std;
char a[500005],b[500005];
int n,m;

int score(bool x){
    int l=0,r=1,mid,skip,ok,mx=0;while((x?b:a)[r]==(x?b:a)[0])r++;r--;
    while(l<=r){
        ok=1;
        mid=skip=(l+r)/2;
        vector<int> av,bv;
        (x?av:bv).push_back(0);
        int ax=x?0:1-mid,bx=x?1-mid:0;
        for(int i=0;i<n+m;i++){
            if((x?b:a)[i]==(x?b:a)[0])(x?bx:ax)++;
            else (x?bx:ax)--,(x?bv:av).push_back((x?bx:ax));
            if((x?a:b)[i]==(x?a:b)[0])(x?ax:bx)++;
            else if(skip)skip--;
            else (x?ax:bx)--,(x?av:bv).push_back((x?ax:bx));
        }
        for(int i=1;i<min(av.size(),bv.size());i++){
            if((x?av:bv)[i]<=0)break;
            else if((x?bv:av)[i]<=0){ok=false;break;}
        }
        if(ok)mx=max(mx,mid),l=mid+1;
        else r=mid-1;
    }
    return mx;
}

int solve(){
    scanf("%d %d %s %s",&n,&m,a,b);
    if(b[0]=='R')for(int i=0;i<n+m;i++)swap(a[i],b[i]);
    return score(0)-score(1);
}
int main(){
    int k,x=0;scanf("%d",&k);
    while(k--)x+=solve();
    printf(x>0?"First":"Second");
    return 0;
}