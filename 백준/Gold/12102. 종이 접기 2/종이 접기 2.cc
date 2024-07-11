#include<bits/stdc++.h>
using namespace std;
int ans=-2e9;

void go(vector<vector<int>> v){
    int n=v.size(),m=v[0].size();
    if(n==1&&m==1)return;

    for(int k=1;k<n;k++){
        vector<vector<int>> x,y;
        for(int i=0;i<n;i++){
            vector<int> tmp;
            for(int j=0;j<m;j++)tmp.push_back(v[i][j]);
            (i<k?x:y).push_back(tmp);
        }
        if(k+k<n){
            swap(x,y);
            for(int i=0;i+i<x.size();i++)swap(x[i],x[x.size()-1-i]);
            for(int i=0;i+i<y.size();i++)swap(y[i],y[y.size()-1-i]);
        }
        for(int i=0;i<y.size();i++)for(int j=0;j<m;j++)
            x[x.size()-1-i][j]+=y[i][j],ans=max(ans,x[x.size()-1-i][j]);
        go(x);
    }

    vector<vector<int>> vv(m,vector<int>(n));
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)vv[j][i]=v[i][j];
    v=vv;n=v.size(),m=v[0].size();
    for(int k=1;k<n;k++){
        vector<vector<int>> x,y;
        for(int i=0;i<n;i++){
            vector<int> tmp;
            for(int j=0;j<m;j++)tmp.push_back(v[i][j]);
            (i<k?x:y).push_back(tmp);
        }
        if(k+k<n){
            swap(x,y);
            for(int i=0;i+i<x.size();i++)swap(x[i],x[x.size()-1-i]);
            for(int i=0;i+i<y.size();i++)swap(y[i],y[y.size()-1-i]);
        }
        for(int i=0;i<y.size();i++)for(int j=0;j<m;j++)
                x[x.size()-1-i][j]+=y[i][j],ans=max(ans,x[x.size()-1-i][j]);
        go(x);
    }
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    vector<vector<int>> v(n,vector<int>(m));
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&v[i][j]),ans=max(ans,v[i][j]);
    go(v);
    printf("%d",ans);
    return 0;
}