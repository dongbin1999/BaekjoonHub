#include <bits/stdc++.h>
using namespace std;
#define cal(v,l,r) (v[r]-v[l-1])

int v[50002],lmn[50002],lmx[50002];

void solve(){
    int n;scanf("%d",&n);
    int mn=2e9,mx=-2e9;
    for(int i=1;i<=n;i++){
        scanf("%d",&v[i]);
        mn=min(mn,v[i]),mx=max(mx,v[i]);
    }
    if(mx==mn){printf("0\n");fflush(stdout);return;}
    int midl=1e9,midr=-1e9;
    for(int i=1;i<=n;i++){
        lmn[i]=lmn[i-1]+(v[i]==mn);
        lmx[i]=lmx[i-1]+(v[i]==mx);
        if(v[i]!=mx&&v[i]!=mn)midl=min(midl,i),midr=max(midr,i);
    }
    if(lmn[n]+lmx[n]==n&&lmn[n]>=n/2&&lmx[n]>=n/2){printf("0\n");fflush(stdout);return;}

    int l=0,r=max(0,midr);
    while(l<n){
        l++;if(l>midl)break;
        while(r<=n&&cal(lmn,l,r)<1)r++;
        while(r<=n&&(r-l+1)+cal(lmn,r+1,n)+cal(lmn,1,l-1)<n/2)r++;
        if(r>n)break;
        int mns=(r-l+1)+cal(lmn,r+1,n)+cal(lmn,1,l-1);
        if(mns>=n/2&&n-mns>=n/2){
            printf("1\n");
            printf("1 %d %d\n",l,r);fflush(stdout);return;
        }
    }
    l=0,r=max(0,midr);
    while(l<n){
        l++;if(l>midl)break;
        while(r<=n&&cal(lmx,l,r)<1)r++;
        while(r<=n&&(r-l+1)+cal(lmx,r+1,n)+cal(lmx,1,l-1)<n/2)r++;
        if(r>n)break;
        int mxs=(r-l+1)+cal(lmx,r+1,n)+cal(lmx,1,l-1);
        if(mxs>=n/2&&n-mxs>=n/2){
            printf("1\n");
            printf("2 %d %d\n",l,r);fflush(stdout);return;
        }
    }


    //이젠 1번으로는 안된다.
    printf("2\n");
    int mxidx=-1,mnidx=-1;
    for(int i=1;i<=n;i++){
        if(v[i]==mx)mxidx=i;
        if(v[i]==mn)mnidx=i;
    }
    if(mnidx<mxidx){//..1..9.
        int mnlen=mxidx-1,mxlen=n-mnlen;//..1../..9.
        if(mnlen>mxlen){
            printf("1 %d %d\n",1,1+mnlen-1);
            printf("2 %d %d\n",n-n/2+1,n);
        }
        else{
            printf("2 %d %d\n",n-mxlen+1,n);
            printf("1 %d %d\n",1,n/2);
        }
    }
    else{//.9..1..
        int mxlen=mnidx-1,mnlen=n-mxlen;//..9../..1.
        if(mxlen>mnlen){
            printf("2 %d %d\n",1,1+mxlen-1);
            printf("1 %d %d\n",n-n/2+1,n);
        }
        else{
            printf("1 %d %d\n",n-mnlen+1,n);
            printf("2 %d %d\n",1,n/2);
        }
    }
    fflush(stdout);return;
}

int main(){
    int tc;scanf("%d",&tc);
    for(int i=1;i<=tc;i++){
        printf("Case #%d\n",i);
        solve();
    }
    return 0;
}

/*
 *
9
5
3 3 2 1 1
5
1 1 1 2 2
4
1 1 2 2
5
3 1 4 3 3
11
3 1 3 1 3 1 3 1 3 1 3
5
1 3 3 3 3
17
3 1 3 3 3 3 3 1 2 1 3 3 3 3 3 1 3
11
3 1 3 3 2 3 2 3 3 1 3
11
3 3 3 1 2 3 2 3 3 1 3

답
1
0
0
2
0
1
1
2
1*/