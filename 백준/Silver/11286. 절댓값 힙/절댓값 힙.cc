#include <bits/stdc++.h>
using namespace std;

struct cmp{
    bool operator()(int a,int b){
        //> : 오름차순
        if(abs(a)==abs(b))return a>b;
        return abs(a)>abs(b);
    }
};

int main(){

    priority_queue<int,vector<int>,cmp> pq;

    int n;scanf("%d",&n);
    while(n--){
        int x;scanf("%d",&x);
        if(x)pq.push(x);
        else{
            if(pq.empty())printf("0\n");
            else printf("%d\n",pq.top()),pq.pop();
        }
    }
}