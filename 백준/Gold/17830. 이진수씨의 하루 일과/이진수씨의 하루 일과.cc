#include <bits/stdc++.h>
using namespace std;
char s[2000000];
int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d %s",&n,s);
        int x=n,ones=0;
        for(int i=0;i<n;i++)
            if(s[i]=='1'||s[i]=='?')ones++,x=min(x,i);
        if(!ones)printf("1 ");
        else printf("%d ",ones==1?n+n-x-1:n+n-x);
        x=n,ones=0;
        for(int i=0;i<n;i++)
            if(s[i]=='1')ones++,x=min(x,i);
        if(!ones)printf("1\n");
        else printf("%d\n",ones==1?n+n-x-1:n+n-x);
    }
    return 0;
}