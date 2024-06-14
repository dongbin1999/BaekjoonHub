#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll nhp,shp,na,nh,sa,sh;scanf("%lld%lld%lld%lld%lld%lld",&nhp,&shp,&na,&nh,&sa,&sh);
    //1방컷
    if(shp<=na){printf("NARUTO\n");return;}
    if(nhp+nh<=sa){printf("SASUKE\n");return;}
    if(na>sh){
        if(nh>sa){printf("NARUTO\n");return;}
        else{//나루토는 공격중에 방어하면안됨.
            ll ndie=(nhp+sa-1)/sa;
            //ll overflow
            if((__int128)ndie*(__int128)na>=(__int128)shp){printf("NARUTO\n");return;}
        }
    }
    //이제 나루토는 이길 방법 없음. 그럼 사스케는 이길 수 있을까?
    if(sa>nh){
        if(sh>na){printf("SASUKE\n");return;}
        else{//사스케는 공격중에 방어하면안됨.
            ll sdie=(shp+na-1)/na;
            //ll overflow
            if((__int128)(sdie-1)*(__int128)sa>=(__int128)nhp){printf("SASUKE\n");return;}
        }
    }
    //둘 다 이길 방법 없음.
    printf("DRAW\n");
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
}