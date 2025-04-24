#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
char s[300000];
int main(){
    int n;scanf("%d",&n);
    vector<vector<int>> a(26);
    scanf("%s",s);
    for(int i=0;i<n;i++)a[s[i]-'a'].push_back(i);
    priority_queue<pii> pq;
    for(int i=0;i<26;i++)if(!a[i].empty())pq.push({a[i].size(),i});
    vector<pii> ans;
    while(pq.size()>1){
        auto [c1,a1]=pq.top();pq.pop();
        auto [c2,a2]=pq.top();pq.pop();
        int x=a[a1].back(),y=a[a2].back();
        a[a1].pop_back(),a[a2].pop_back();
        ans.push_back({min(x,y),max(x,y)});
        c1--,c2--;
        if(c1)pq.push({c1,a1});
        if(c2)pq.push({c2,a2});
    }
    if(!pq.empty()){
        auto [c,al]=pq.top();
        if(c>1)return !printf("-1");
        bool ok=0;
        int zi=a[al].back();
        for(auto [xi,yi]:ans)
            if(s[xi]!=s[zi]&&s[yi]!=s[zi]){
                ok=1;ans.push_back({min(xi,zi),max(xi,zi)});
                break;
            }
        if(!ok)return !printf("-1");
    }

    printf("%d\n",ans.size());
    for(auto [x,y]:ans)printf("%d %d\n",x+1,y+1);
    return 0;
}