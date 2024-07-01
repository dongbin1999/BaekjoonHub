#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
map<char,int> ma[500][500];

char s[502][502];

int main(){
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    int ans=0;
    for(int i=0;i<n;i++){
        scanf("%s",s[i]);
        for(int j=0;j<m;j++)ma[i%k][j%k][s[i][j]]++;
    }
    for(int x=0;x<k;x++)for(int y=0;y<k;y++){
        pii p={-1,-1};
        for(auto [a,b]:ma[x][y])p=max(p,{b,a});
        for(int i=x;i<n;i+=k)for(int j=y;j<m;j+=k)
            if(s[i][j]!=p.second)ans++,s[i][j]=p.second;
    }
    printf("%d\n",ans);
    for(int i=0;i<n;i++)printf("%s\n",s[i]);
}