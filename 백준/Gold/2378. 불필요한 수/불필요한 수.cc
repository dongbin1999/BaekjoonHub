#include <bits/stdc++.h>
using namespace std;
const int sz=100000;
int under_prime[sz+1];

void logsieve(){
    under_prime[1]=1;
    for(int i=2;i<=sz;i++)
        if(!under_prime[i])
            for(int j=i;j<=sz;j+=i)
                if(!under_prime[j])
                    under_prime[j]=i;
}


int main(){
    logsieve();
    int n,m;scanf("%d%d",&n,&m);n--;
    map<int,int> ma;
    int mi=0;
    for(int i=2;i*i<=m;i++){
        while(m%i==0)ma[i]--,m/=i;
        mi+=ma[i]<0;
    }
    if(m>1)ma[m]--,mi++;
    vector<int> ans;
    for(int i=1,j=n;i<n;i++,j--){
        int x=j;
        while(x>1){
            int prime=under_prime[x];
            ma[prime]++;
            if(!ma[prime])mi--;
            x/=prime;
        }
        x=i;
        while(x>1){
            int prime=under_prime[x];
            ma[prime]--;
            if(ma[prime]==-1)mi++;
            x/=prime;
        }
        if(!mi)ans.push_back(i+1);
    }
    printf("%d\n",(int)ans.size());
    for(auto i:ans)printf("%d ",i);
    return 0;
}