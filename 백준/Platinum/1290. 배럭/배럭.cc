#include <bits/stdc++.h>
using namespace std;

int simul(int n,int u)
{
    int ret=0;
    while(u>0){
            u=max(0,u-n),n-=u,ret++;
            if(n*2<=u)return 1e9;
    }
    return ret;
}

int main() {
    int n,b,u;scanf("%d %d %d",&n,&b,&u);
    if(n>=b) return !printf("1");

    if(n<=u) //배럭부터 빨리 부수는게 최선임.
    {
        int bb=max(0,b-2*n),uu=max(0,u-(2*n-b)),nn=n-uu;
        //2턴 지났는데 배럭이 안깨졌거나, 내마린수*2<=상대마린수가 돼버림.
        if(bb || nn*2<=uu) return !printf("-1");
        int turn=2;
        //직접 시뮬레이션.
        while(uu>0){
            uu=max(0,uu-nn),nn-=uu,turn++;
            if(nn*2<=uu)return !printf("-1");
        }
        return !printf("%d",turn);
    }
    else //일단, 배럭이 한번에 부서질 피까지는 상대마린을 다죽이면서 까놔야함.
    {
        int ans=1e9;
        int base=1,nn=n,bb=b-n,uu=u;
        while(nn<bb) base++,bb=max(0,bb-(n-u));
        //이제, 배럭이 한번에 부서질 피임. 배럭을 add턴 전처리 후에 부술거임.
        for(int add=0;add<=bb;add++)
        {
            int nnn=n,bbb=max(0,bb-(n-u)*add),uuu=max(0,uu-((n-u)*add-bb));
            if(!bbb&&!uuu) ans=min(ans,base+add);
            else
            {
                uuu=max(0,uu-(n-bbb)),nnn=max(0,nnn-uuu);//1턴을 들여서 배럭을 부순거임.
                ans=min(ans,add+1+base+simul(nnn,uuu));
            }
        }
        printf("%d",ans==1e9?-1:ans);
    }
    return 0;
}