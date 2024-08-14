#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main(){
    int n;scanf("%d",&n);
    if(n==1)return !printf("권병장님, 중대장님이 찾으십니다");
    vector<pii> v(n);
    for(int i=0;i<n;i++)scanf("%d",&v[i].first);
    for(int i=0;i<n-1;i++)scanf("%d",&v[i].second);
    sort(v.begin()+1,v.end()-1);
    int len=v[0].second,cur=0;
    while(cur<n-1){
        int dist=v[cur+1].first-v[cur].first;
        if(dist>len)return !printf("엄마 나 전역 늦어질 것 같아");
        len=max(len-dist,v[cur+1].second),cur++;
    }
    printf("권병장님, 중대장님이 찾으십니다");
    return 0;
}