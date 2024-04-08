#include<bits/stdc++.h>
using namespace std;
char s[301];
int main(){
    int r,c;scanf("%d%d",&r,&c);
    vector<bitset<300>> a(r),b(r);
    for(int i=0;i<r;i++){
        scanf("%s",s);
        for(int j=0;j<c;j++)b[r-1-i][c-1-j]=a[i][j]=s[j]=='1';
    }
    for(int sz=min(r,c);sz>=2;sz--){
        bitset<300> all;for(int i=0;i<sz;i++)all[i]=1;
        for(int x=0;x+sz<=r;x++)for(int y=0;y+sz<=c;y++){
            bool ok=1;
            for(int i=0;i<sz;i++)
                if(((a[x+i]>>y&all)^(b[r-sz-x+i]>>(c-y-sz)&all)).any()){ok=0;break;}
            if(ok)return !printf("%d",sz);
        }
    }
    printf("-1");
}