#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define x first
#define y second
#define in(p) (p.x>=0&&p.x<100&&p.y>=0&&p.y<100)
#define ok(a,b,c) (in(a)&&a!=b&&a!=c)
pii go[8]={{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1}};

bool kill(pii q,pii k1,pii k2){
    auto [qx,qy]=q;auto [k1x,k1y]=k1;auto [k2x,k2y]=k2;
    return qx==k1x||qx==k2x||qy==k1y||qy==k2y||abs(qx-k1x)==abs(qy-k1y)||abs(qx-k2x)==abs(qy-k2y);
}

int main() {
    pii q,k1,k2;scanf("%d%d%d%d%d%d",&q.x,&q.y,&k1.x,&k1.y,&k2.x,&k2.y);
    if(kill(q,k1,k2))return !printf("1");
    map<pii,vector<pair<pii,pii>>> ma;
    for(int d=1;d<=100;d++)
        for(auto [qdx,qdy]:go){
            bool two=1;
            pii nq={q.x+qdx*d,q.y+qdy*d};
            if(!in(nq))continue;
            for(auto [kdx,kdy]:go){
                pii nk1={k1.x+kdx,k1.y+kdy};
                if(ok(nk1,nq,k2)&&!kill(nq,nk1,k2))ma[nq].push_back({nk1,k2}),two=0;
                pii nk2={k2.x+kdx,k2.y+kdy};
                if(ok(nk2,nq,k1)&&!kill(nq,k1,nk2))ma[nq].push_back({k1,nk2}),two=0;
            }
            if(two)return !printf("2");
        }
    for(auto [qf,v]:ma){
        bool bk1=1;
        for(auto [kf1,kf2]:v){
            bool bq2=0;
            for(int d=1;d<=100;d++){
                for(auto [qdx,qdy]:go){//퀸의 두 번째 움직임
                    pii nq={qf.x+qdx*d,qf.y+qdy*d};
                    if(!in(nq))continue;
                    bool bk2=1;
                    for(auto [kdx,kdy]:go){//왕의 두 번째 움직임
                        pii nk1={kf1.x+kdx,kf1.y+kdy};
                        if(ok(nk1,nq,kf2)&&!kill(nq,nk1,kf2))bk2=0;
                        pii nk2={kf2.x+kdx,kf2.y+kdy};
                        if(ok(nk2,nq,kf1)&&!kill(nq,kf1,nk2))bk2=0;
                    }
                    bq2|=bk2;
                }
            }bk1&=bq2;
        }
        if(bk1)return !printf("3");
    }


    /*for(auto [qf,v]:ma){
        for(int d=1;d<=100;d++){
            for(auto [qdx,qdy]:go){//퀸의 두 번째 움직임
                pii nq={qf.x+qdx*d,qf.y+qdy*d};
                if(!in(nq))continue;
                bool three=1;
                for(auto [kf1,kf2]:v){//왕의 첫 번째 움직임이 완료된 상태. 첫 퀸의 공격을 피한 왕들임.
                    for(auto [kdx,kdy]:go){//왕의 두 번째 움직임
                        pii nk1={kf1.x+kdx,kf1.y+kdy};
                        if(ok(nk1,nq,kf2)&&!kill(nq,nk1,kf2))three=0;
                        pii nk2={kf2.x+kdx,kf2.y+kdy};
                        if(ok(nk2,nq,kf1)&&!kill(nq,kf1,nk2))three=0;
                    }
                }
                if(three)return !printf("3");
            }
        }
    }*/
    return !printf("4");
}