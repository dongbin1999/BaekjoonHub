#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main(){
    int n;scanf("%d",&n);
    vector<int> v(n);
    vector<pii> ans;
    for(int i=0;i<n;i++)scanf("%d",&v[i]);
    if(v.back()>2)return !printf("-1");
    vector<int> a;
    for(int i=1;i<=v.back();i++)a.push_back(i);
    if(v.back()==2)ans.push_back({1,2});
    if(n>1&&v[n-2]==1)return !printf("-1");
    int cnt=v.back();
    v.pop_back();
    while(!v.empty()){
        int x=v.back();v.pop_back();
        if(a.size()>x)return !printf("-1");
        vector<int> na;
        for(auto i:a){
            ans.push_back({i,++cnt});
            na.push_back(cnt),x--;
        }
        while(x--)ans.push_back({a.back(),++cnt}),na.push_back(cnt);
        a=na;
    }
    printf("%d\n",ans.size()+1);
    for(auto [x,y]:ans)printf("%d %d\n",x,y);
}