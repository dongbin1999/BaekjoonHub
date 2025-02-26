#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int x[1501][1501];

int main(){
    int a,b,c;scanf("%d%d%d",&a,&b,&c);
    int sum=a+b+c;
    if(sum%3)return !printf("0");
    x[a][b]=1;
    queue<pii> q;
    q.push({a,b});
    while(!q.empty()){
        auto [aa,bb]=q.front();q.pop();
        //printf("%d %d\n",aa,bb);
        vector<int> v={aa,bb,sum-aa-bb};
        sort(v.begin(),v.end());
        for(int i=0;i<2;i++)for(int j=i+1;j<3;j++)
            if(v[i]<v[j]){
                int na=v[i]+v[i],nb=v[j]-v[i];
                if(!x[na][nb])x[na][nb]=1,q.push({na,nb});
            }
    }
    for(int i=0;i<=1500;i++)for(int j=0;j<=1500;j++)
        if(i==j&&i==sum-i-j&&x[i][j])return !printf("1");
        printf("0");
}