#include<bits/stdc++.h>
using namespace std;
char s[3000];

int main(){
    int n;scanf("%d %s",&n,s+1);
    int x=1e9;
    for(int i=1;i<n;i++){
        map<int,int> ma;
        for(int j=1;j<=n;j++){
            if(s[j]!='#')continue;
            if(ma[j-i])ma[j-i]--;
            ma[j]++;
        }
        int sum=0;
        for(auto [a,b]:ma)sum+=b;
        x=min(x,sum);
    }
    printf("%d",x);
}