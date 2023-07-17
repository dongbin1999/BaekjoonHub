#include <bits/stdc++.h>
using namespace std;

char q(int x){
    printf("%d\n",x);
    fflush(stdout);
    char c;scanf(" %c",&c);
    return c;
}

int main(){
    int n,l=1,r,k,mid,test,len,tmp;scanf("%d%d",&n,&k);
    char c;
    for(int i=0;i<n;i++){
        r=k,len=r-l+1,test=min(r,l+len/(n-i)),tmp=max(l,r-len/(n-i));
        c=q(test);
        if(c=='='){l=test+1;continue;}
        else if(c=='<')r=test-1;
        else l=test+1;
        if(l<tmp&&tmp<r){
            c=q(tmp);
            if(c=='='){l=tmp+1;continue;}
            else if(c=='<')r=tmp-1;
            else l=tmp+1;
        }
        while(l<=r){
            mid=(l+r)/2;
            c=q(mid);
            if(c=='='){l=mid+1;break;}
            else if(c=='<')r=mid-1;
            else l=mid+1;
        }
    }
    return 0;
}