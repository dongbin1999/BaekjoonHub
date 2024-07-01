#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

char s[52][52],id[1002];
map<char,int> ma,ma2;
vector<pii> v[300];

int main(){
    int n,m,sz;scanf("%d%d%d",&n,&m,&sz);
    for(int i=0;i<n;i++){
        scanf("%s",s[i]);
        for(int j=0;j<m;j++)ma[s[i][j]]++,v[s[i][j]].push_back({i,j});
    }
    scanf("%s",id);
    for(int i=0;i<sz;i++)ma2[id[i]]++;
    int a=1e9;
    for(auto [c,x]:ma2)a=min(a,ma[c]/x);
    printf("%d ",a);
    string S,ans;
    while(a--)for(int i=0;i<sz;i++)S+=id[i];
    int x=0,y=0;
    for(auto i:S){
        auto [nx,ny]=v[i].back();v[i].pop_back();
        while(x<nx)ans+='D',x++;
        while(x>nx)ans+='U',x--;
        while(y<ny)ans+='R',y++;
        while(y>ny)ans+='L',y--;
        ans+='P';
    }
    while(x<n-1)ans+='D',x++;
    while(y<m-1)ans+='R',y++;
    printf("%d\n",ans.size());
    for(auto i:ans)printf("%c",i);
}