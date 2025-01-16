#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii> v[800001];

int main(){
    int w,n;scanf("%d%d",&w,&n);
    vector<int> a(n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        for(int j=0;j<i;j++)
            if(v[a[j]+a[i]].size()<3)v[a[j]+a[i]].push_back({j,i});
    }
    if(w%2==0&&v[w/2].size()>1)return !printf("YES");
    for(int i=0;i+i<w;i++){
        int j=w-i;
        if(v[i].empty()||v[j].empty())continue;
        for(auto [x,y]:v[i])for(auto [xx,yy]:v[j]){
            unordered_set<int> se={x,y,xx,yy};
            if(se.size()==4)return !printf("YES");
        }
    }
    printf("NO");
}