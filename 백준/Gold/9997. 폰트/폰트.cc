#include<bits/stdc++.h>
using namespace std;
int ans,all=(1<<26)-1;
vector<int> v;
void go(int i=0,int bit=0){
    if(i==v.size()){
        ans+=bit==all;
        return;
    }
    go(i+1,bit);
    go(i+1,bit|v[i]);
}

int main(){
    int n;scanf("%d",&n);
    while(n--){
        string s;cin>>s;
        int x=0;
        for(auto i:s)x|=1<<(i-'a');
        v.push_back(x);
    }
    go();
    printf("%d",ans);
}