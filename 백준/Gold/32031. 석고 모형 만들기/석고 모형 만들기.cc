#include<bits/stdc++.h>
using namespace std;

int u[320000],r,c,rr,cc;
int find(int x){return u[x]<0?x:u[x]=find(u[x]);}
bool merge(int a,int b){
    a=find(a),b=find(b);
    if(a==b)return false;
    u[a]+=u[b],u[b]=a;
    return true;
}
char s[200][201];

void f(int i,int j,char x){
    int ii=i+i,jj=j+j;
    int a[8]={ii*cc+jj,ii*cc+jj+1,(ii+1)*cc+jj,(ii+1)*cc+jj+1};
    for(int k=4;k<8;k++)a[k]=a[k-4]+rr*cc;
    if(x=='O')merge(a[0],a[4]),merge(a[1],a[5]),merge(a[2],a[6]),merge(a[3],a[7]);
    if(x=='I')merge(a[0],a[2]),merge(a[1],a[3]),merge(a[4],a[6]),merge(a[5],a[7]);
    if(x=='H')merge(a[0],a[1]),merge(a[2],a[3]),merge(a[4],a[5]),merge(a[6],a[7]);
}
void f2(int i,int j){
    int ii=i+i,jj=j+j;
    int a[8]={ii*cc+jj+1,(ii+1)*cc+jj+1,(ii+1)*cc+jj,(ii+1)*cc+jj+1};
    for(int k=4;k<8;k++)a[k]=a[k-4]+rr*cc;
    for(int k=0;k<8;k++){
        if(k%4<2&&j+1<c)merge(a[k],a[k]+1);
        if(k%4>=2&&i+1<r)merge(a[k],a[k]+cc);
    }
}

int main(){
    memset(u,-1,sizeof(u));
    scanf("%d%d",&r,&c);
    rr=r+r,cc=c+c;
    for(int i=0;i<r;i++){
        scanf("%s",s[i]);
        for(int j=0;j<c;j++)f(i,j,s[i][j]),f2(i,j);
    }
    int ans=0;
    for(int i=0;i<r*c*8;i++)ans+=u[i]<0;
    printf("%d",ans);
}