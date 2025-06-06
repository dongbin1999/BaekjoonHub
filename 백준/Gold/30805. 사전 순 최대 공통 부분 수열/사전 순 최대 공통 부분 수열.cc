#include<bits/stdc++.h>
using namespace std;
typedef array<int,3> arr;
typedef pair<int,int> pii;
int main(){
    int n;scanf("%d",&n);
    deque<int> a(n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    int m;scanf("%d",&m);
    deque<int> b(m);
    for(int i=0;i<m;i++)scanf("%d",&b[i]);
    vector<int> ans;
    while(1){
        arr x={-1,-1,-1};
        for(int i=0;i<a.size();i++)for(int j=0;j<b.size();j++)
            if(a[i]==b[j])x=max(x,{a[i],-i-1,-j-1});
        if(x[0]==-1)break;
        auto [v,nn,mm]=x;nn*=-1,mm*=-1;
        while(nn--)a.pop_front();
        while(mm--)b.pop_front();
        ans.push_back(v);
    }
    printf("%d\n",ans.size());
    for(auto i:ans)printf("%d ",i);
}