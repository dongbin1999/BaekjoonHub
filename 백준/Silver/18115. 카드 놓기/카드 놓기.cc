#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    vector<int> v(n);
    for(int i=0;i<n;i++)scanf("%d",&v[i]);
    reverse(v.begin(),v.end());
    deque<int> dq;
    int num=1;
    for(auto i:v){
        if(i==1)dq.push_front(num);
        else if(i==2){
            int x=dq.front();dq.pop_front();
            dq.push_front(num);dq.push_front(x);
        }
        else dq.push_back(num);
        num++;
    }
    for(auto i:dq)printf("%d ",i);
}
