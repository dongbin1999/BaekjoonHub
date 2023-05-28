#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main(){
    int d,n;scanf("%d%d",&d,&n);
    vector<pii> o(d);
    for(int i=0;i<d;i++)scanf("%d",&o[i].first),o[i].second=i+1;
    o.push_back({2e9,-1e9});
    sort(o.begin(),o.end(),[](pii a,pii b){
        return a.first==b.first?a.second>b.second:a.first<b.first;
    });
    int bottom=d+1,idx=0;
    while(n--){
        int p;scanf("%d",&p);
        while(1){
            if(o[idx].first>=p&&o[idx].second<=bottom)break;
            bottom=min(bottom,o[idx].second);
            idx++;
        }
        bottom--;
        if(bottom<-0)return !printf("0");
    }
    printf("%d",bottom);
    return 0;
}