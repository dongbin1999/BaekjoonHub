#include <bits/stdc++.h>
using namespace std;
const int sz=17;
typedef pair<int,int> pii;
#define l first
#define r second
pii sparse[sz][1<<sz]; //j번 블럭이 누르는 왼쪽/오른쪽 블럭의 번호
pii board[400001];//최대 높이,블록 번호
pii block[1<<sz];//{블럭타입, 블럭 위치}
int push[1<<sz];//i번째 블록이 누르고 있는 블럭의 개수

int HCC(int bnum,vector<int> b){//b : 닿는 블럭번호들의 집합.
    if(b.empty())return 0;
    if(b.size()==1)return  sparse[0][bnum].l;
    else{
        auto [left,right]=sparse[0][bnum];
        for(int i=sz-1;i>=0;i--)
            if(block[sparse[i][left].r].second<block[sparse[i][right].l].second)
                left=sparse[i][left].r,right=sparse[i][right].l;
        return sparse[0][left].r;
    }
}

void update(int bnum,vector<int> v){
    if(v.size()==1) sparse[0][bnum]={v[0],v[0]};
    else if(v.size()==2) sparse[0][bnum]={v[0],v[1]};
    for(int i=1;i<sz;i++){
        sparse[i][bnum].l=sparse[i-1][sparse[i-1][bnum].l].l;
        sparse[i][bnum].r=sparse[i-1][sparse[i-1][bnum].r].r;
    }
}

int main(){
    int q;scanf("%d",&q);
    for(int i=1;i<=q;i++){
        int c,a;scanf("%d%d",&c,&a);
        block[i]={c,a};
        if(c==1){
            int height=0;
            for(int j=a;j<a+4;j++)
                height=max(height,board[j].first);
            vector<int> v;
            for(int j=a;j<a+4;j++){
                auto [h,b]=board[j];
                if(h==height&&b&&(v.empty()||v.back()!=b))v.push_back(b);
            }
            update(i,v);
            push[i]=(int)v.size();
            for(auto j:v)push[i]+=push[j];
            if(v.size()==2){
                int hcc=HCC(i,v);
                if(hcc)push[i]-=1+push[hcc];
            }
            //printf("hcc : %d ,i : %d, height : %d, v : ",HCC(i,v),i,height);
            //for(auto j:v)printf("%d ",j);printf("\n");
            printf("%d\n",push[i]);
            for(int j=a;j<a+4;j++)board[j]={height+1,i};
        }
        else{
            return !printf("0");
        }
    }
    return 0;
}