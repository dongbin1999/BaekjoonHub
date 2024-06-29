#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    vector<int> v[3];
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        v[x%3].push_back(x);
    }
    deque<int> ans;
    if(v[0].empty()&&!v[1].empty()&&!v[2].empty())return !printf("-1");
    while(1){
        if(!v[0].empty()&&(ans.empty()||ans.back()%3||ans.front()%3)){
            if(ans.empty()||ans.back()%3)ans.push_back(v[0].back()),v[0].pop_back();
            else if(ans.front()%3)ans.push_front(v[0].back()),v[0].pop_back();
            else break;
        }
        else if(!v[1].empty()){
            ans.push_back(v[1].back()),v[1].pop_back();
        }
        else if(!v[2].empty()){
            ans.push_front(v[2].back()),v[2].pop_back();
        }
        else break;
    }
    if(ans.size()<n)return !printf("-1");
    for(auto i:ans)printf("%d ",i);
}