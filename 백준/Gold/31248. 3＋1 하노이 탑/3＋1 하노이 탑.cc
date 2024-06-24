#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii> ans;

void hanoi(int n,int from,int tmp,int to){
    if(n==1){ans.push_back({from,to});return;}
    hanoi(n-1,from,to,tmp);
    ans.push_back({from,to});
    hanoi(n-1,tmp,from,to);
}
void hanoi_3(int n,int from=0,int tmp=1,int to=2){
    if(n==1){ans.push_back({from,3});return;}
    if(n==2){
        ans.push_back({from,tmp}),ans.push_back({from,3}),ans.push_back({tmp,3});
        return;
    }
    hanoi(n-2,from,tmp,to);
    ans.push_back({from,tmp}),ans.push_back({from,3}),ans.push_back({tmp,3});
    hanoi_3(n-2,to,tmp,from);
}

int main(){
    int n;scanf("%d",&n);
    hanoi_3(n);
    printf("%d\n",ans.size());
    for(auto [a,b]:ans)printf("%c %c\n",a+'A',b+'A');
}