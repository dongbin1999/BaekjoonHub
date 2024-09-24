#include<bits/stdc++.h>
using namespace std;
int a[500][500];

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)a[i][i]=1;a[n][1]=a[1][n]=1;
    int cur=1;
    vector<int> ans;
    while(1){
        ans.push_back(cur);
        int nx=-1;
        for(int i=1;i<=n;i++)
            if(!a[cur][i]){nx=i;break;}
        if(nx<0)break;
        a[cur][nx]=a[nx][cur]=1,cur=nx;
    }
    ans.push_back(1);
    for(auto i:ans)printf("a%d ",i);
}