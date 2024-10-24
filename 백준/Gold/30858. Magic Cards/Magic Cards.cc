#include<bits/stdc++.h>
using namespace std;
char s[102];
__int128 h[500001],two[100]={1};

int main(){
    int n,k,m,f;scanf("%d%d%d%d",&n,&k,&m,&f);
    for(int i=1;i<100;i++)two[i]=two[i-1]*2;
    for(int i=0;i<k;i++){
        unordered_set<int> se;
        for(int j=0;j<m;j++){
            int x;scanf("%d",&x);
            se.insert(x);
        }
        for(auto x:se)h[x]+=two[i];
    }
    unordered_map<__int128,vector<int>> ma;
    for(int i=1;i<=n;i++)ma[h[i]].push_back(i);
    while(f--){
        scanf("%s",s);
        __int128 h2=0;
        for(int i=0;i<k;i++)if(s[i]=='Y')h2+=two[i];
        if(ma[h2].size()==1)printf("%d\n",ma[h2][0]);
        else printf("0\n");
    }
}