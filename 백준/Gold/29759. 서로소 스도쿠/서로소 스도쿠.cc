#include<bits/stdc++.h>
using namespace std;
const int sz=1000000;
int under_prime[sz+1];//under_prime[i] : i을 나누는 가장 작은 소수.

void logsieve(){
    under_prime[1]=1;
    for(int i=2;i<=sz;i++)
        if(!under_prime[i])
            for(int j=i;j<=sz;j+=i)
                if(!under_prime[j])
                    under_prime[j]=i;
}

int a[101][101];

int main(){
    logsieve();
    vector<int> p;
    for(int i=500001;i<=sz;i++)if(under_prime[i]==i)p.push_back(i);
    int n;cin>>n;
    for(int i=0;i<n*n;i++)for(int j=0;j<n*n;j++)cin>>a[i][j];
    for(int i=0;i<n*n;i++)for(int j=0;j<n*n;j++){
        if(a[i][j])continue;
        unordered_set<int> se;
        for(int l1=i/n*n,r1=l1+n,x=l1;x<r1;x++)for(int l2=j/n*n,r2=l2+n,y=l2;y<r2;y++)
            se.insert(a[x][y]);
        for(int k=0;k<n*n;k++)se.insert(a[k][j]),se.insert(a[i][k]);
        int ok=-1;
        for(auto k:p)if(!se.count(k)){ok=k;break;}
        a[i][j]=ok;
    }
    for(int i=0;i<n*n;i++){
        for(int j=0;j<n*n;j++)cout<<a[i][j]<<' ';
        cout<<'\n';
    }
}