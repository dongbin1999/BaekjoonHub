#include <bits/stdc++.h>
using namespace std;

int a[4][4],n,m,END,mx[1<<16];
void f(int score,int state){
    if(mx[state]>=score) return;
    mx[state]=max(mx[state],score);
    if(state==END) return;

    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        if(state>>(i*m+j)&1)continue;
        int add=0,val=0;
        for(int k=i;k<n;k++){
            if(state>>(k*m+j)&1)break;
            add+=1<<(k*m+j),val=val*10+a[k][j];
            f(score+val,state+add);
        }
        add=0,val=0;
        for(int k=j;k<m;k++){
            if(state>>(i*m+k)&1)break;
            add+=1<<(i*m+k),val=val*10+a[i][k];
            f(score+val,state+add);
        }
    }
}

int main(){
    memset(mx,-1,sizeof(mx));
    scanf("%d%d",&n,&m);
    END=(1<<(n*m))-1;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%1d",&a[i][j]);
    f(0,0);
    printf("%d",mx[END]);
    return 0;
}
