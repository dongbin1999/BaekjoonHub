#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int main(){
    int n;scanf("%d",&n);
    deque<pii> v(n);
    int cnt=0,star=0;
    for(int i=0;i<n;i++)scanf("%d%d",&v[i].second,&v[i].first);
    while(!v.empty()){
        sort(v.begin(),v.end());
        if(v[0].first<=star)star+=1+(v[0].second!=1e9),cnt++,v.pop_front();
        else{
            int idx=v.size()-1;
            while(idx>=0&&v[idx].second>star)idx--;
            if(idx<0)return !printf("Too Bad");
            cnt++,star++,v[idx].second=1e9;
        }
    }
    printf("%d",cnt);
    return 0;
}