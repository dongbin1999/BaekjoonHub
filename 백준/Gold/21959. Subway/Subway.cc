#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<int> a[100000];
int main(){
    int n;scanf("%d",&n);
    a[0].push_back(0);
    int x=1;
    while(n>=x){
        a[x].push_back(x);
        n-=x,x++;
    }
    if(n)a[n].push_back(x);
    vector<pii> ans;
    for(int i=1;i<100000;i++)for(auto j:a[i])ans.push_back({j,a[i-1].back()});
    ans.push_back({0,-1});
    printf("%d\n",ans.size());
    for(auto [xx,yy]:ans)printf("%d %d\n",xx,yy);
}