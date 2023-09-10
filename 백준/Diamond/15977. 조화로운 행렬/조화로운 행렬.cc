#include <bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tup;
typedef pair<int,int> pii;
#define a(x) get<0>(x)
#define b(x) get<1>(x)
#define c(x) get<2>(x)
#define x first
#define y second

struct S{
    set<pii> se;
    bool operator<(const pii &p){
        auto it=se.lower_bound(p);
        return it!=se.begin() && prev(it)->y<p.y;
    }
    void add(const pii &p){
        auto it=++se.insert(p).x;
        while(it!=se.end() && p.y<it->y)it=se.erase(it);
    }
};

int main(){
    int m,n;scanf("%d%d",&m,&n);
    vector<tup> v(n);
    for(int i=0;i<3;i++)for(int j=0;j<n;j++)
        if(m==i)c(v[j])=a(v[j]);
        else{
            int x;scanf("%d",&x);
            if(i==0)a(v[j])=x;if(i==1)b(v[j])=x;if(i==2)c(v[j])=x;
        }
    sort(v.begin(),v.end());
    vector<S> LIS;
    for(auto [a,b,c]:v){
        pii bc={b,c};
        if(LIS.empty()||LIS.back()<bc)LIS.push_back({{bc}});
        else lower_bound(LIS.begin(),LIS.end(),bc)->add(bc);
    }
    printf("%d",LIS.size());
    return 0;
}