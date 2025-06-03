#include<bits/stdc++.h>
using namespace std;
typedef pair<int,char> pic;
int a[300];
int main(){
    int n;scanf("%d",&n);
    while(n--){
        char c;scanf(" %c",&c);
        a[c]++;
    }
    priority_queue<pic> pq;
    for(int i='A';i<='Z';i++)if(a[i])pq.push({a[i],i});
    vector<char> v;
    while(!pq.empty()){
        auto [x,y]=pq.top();pq.pop();
        if(!v.empty()&&v.back()==y){
            if(pq.empty())return !printf("NE");
            auto [z,w]=pq.top();pq.pop();
            v.push_back(w),z--;
            if(z)pq.push({z,w});
            pq.push({x,y});
        }
        else {
            v.push_back(y),x--;
            if(x)pq.push({x,y});
        }
    }
    for(auto i:v)printf("%c ",i);
}