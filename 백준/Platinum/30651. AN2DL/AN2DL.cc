#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef pair<int,int> pii;

int a[4000][4000],b[4000][4000],c[4000][4000];

int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&a[i][j]);
    int r,s;scanf("%d%d",&r,&s);
    for(int i=0;i<n;i++){
        deque<pii> dq;
        for(int j=0;j<m;j++){
            pii p={a[i][j],j};
            while(!dq.empty()&&p.x>=dq.back().x)dq.pop_back();
            dq.push_back(p);
            while(dq.front().y<=j-s)dq.pop_front();
            if(j>=s-1)b[i][j-s+1]=dq.front().x;
        }
    }
    for(int j=0;j<m-s+1;j++){
        deque<pii> dq;
        for(int i=0;i<n;i++){
            pii p={b[i][j],i};
            while(!dq.empty()&&p.x>=dq.back().x)dq.pop_back();
            dq.push_back(p);
            while(dq.front().y<=i-r)dq.pop_front();
            if(i>=r-1)c[i-r+1][j]=dq.front().x;
        }
    }

    for(int i=0;i<n-r+1;i++){
        for(int j=0;j<m-s+1;j++)printf("%d ",c[i][j]);
        printf("\n");
    }
}