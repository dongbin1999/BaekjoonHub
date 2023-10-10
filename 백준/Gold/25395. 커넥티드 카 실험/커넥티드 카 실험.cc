#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,s;scanf("%d%d",&n,&s);s--;
    vector<int> x(n),h(n);
    for(int i=0;i<n;i++)scanf("%d",&x[i]);
    for(int i=0;i<n;i++)scanf("%d",&h[i]);
    queue<int> q;q.push(s);
    int l=s,r=s;
    while(!q.empty()){
        int cur=q.front();q.pop();
        int le=lower_bound(x.begin(),x.end(),x[cur]-h[cur])-x.begin();
        while(le<=l-1)q.push(l-1),l--;
        int ri=upper_bound(x.begin(),x.end(),x[cur]+h[cur])-x.begin()-1;
        while(ri>=r+1)q.push(r+1),r++;
    }
    for(int i=l;i<=r;i++)printf("%d ",i+1);
    return 0;
}