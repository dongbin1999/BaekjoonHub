#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef array<int,3> tup;

int y[9][9],x[3][20],n,k;
void go(int bit,tup win,pii fight,tup idx){
    auto it=max_element(win.begin(),win.end());
    if(*it==k){if(it-win.begin()==0){printf("1");exit(0);}else return;}
    auto [a,b]=fight;
    if(a>b)swap(a,b);
    int c;for(int i=0;i<3;i++)if(i!=a&&i!=b)c=i;
    int A=x[a][idx[a]],B=x[b][idx[b]];
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        if(a&&i>0)continue;if(b&&j>0)continue;
        if(!a&&(bit>>i&1))continue;if(!b&&(bit>>j&1))continue;
        if(!a)A=i;if(!b)B=j;
        if(y[A][B]==2){//A win
            int nb=bit;if(!a)nb+=1<<i;if(!b)nb+=1<<j;
            tup nwin=win;nwin[a]++;
            tup nidx=idx;nidx[a]++,nidx[b]++;
            go(nb,nwin,{a,c},nidx);
        }
        else{//B win
            int nb=bit;if(!a)nb+=1<<i;if(!b)nb+=1<<j;
            tup nwin=win;nwin[b]++;
            tup nidx=idx;nidx[a]++,nidx[b]++;
            go(nb,nwin,{b,c},nidx);
        }
    }
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&y[i][j]);
    for(int i=0;i<20;i++)scanf("%d",&x[1][i]),x[1][i]--;
    for(int i=0;i<20;i++)scanf("%d",&x[2][i]),x[2][i]--;
    go(0,{0,0,0},{0,1},{0,0,0});
    printf("0");
}