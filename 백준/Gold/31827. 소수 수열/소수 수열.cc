#include<bits/stdc++.h>
using namespace std;
const int sz=1000000;
int p[sz+1];

void logsieve(){
    p[1]=1;
    for(int i=2;i<=sz;i++)
        if(!p[i])for(int j=i;j<=sz;j+=i)
                if(!p[j])p[j]=i;
}

int main(){
    logsieve();
    int n,k;scanf("%d%d",&n,&k);
    vector<int> v(k);
    map<int,vector<int>> ma;
    int x=-1;
    for(int i=2;i<=1000000;i++){
        if(p[i]!=i)continue;
        ma[i%k].push_back(i);
        if(ma[i%k].size()==n){
            x=i%k;break;
        }
    }
    for(auto i:ma[x])printf("%d ",i);
}