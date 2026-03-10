#include<bits/stdc++.h>
using namespace std;
typedef pair<int,char> pic;

char a[3000][3000];

int main(){
    int n,m;scanf("%d%d",&n,&m);
    deque<pic> v(3);
    string s="BGR";
    for(auto &[x,y]:v)scanf("%d",&x),y=s.back(),s.pop_back();
    sort(v.begin(),v.end());
    if((n*m+1)/2<v.back().first)return !printf("NO");
    printf("YES\n");
    swap(v[0],v[1]);
    //odd 채우기
    int x=1,y=2;
    while(x+y<=n+m){
        int t=y;
        while(x<=n&&y>=1){
            if(y<=m){
                a[x][y]=v[0].second;
                if(--v[0].first==0)v.pop_front();
            }
            x++,y--;
        }
        x=1,y=t+2;
    }
    //even 채우기.
    x=1,y=1;
    while(x+y<=n+m){
        int t=y;
        while(x<=n&&y>=1){
            if(y<=m){
                a[x][y]=v[0].second;
                if(--v[0].first==0)v.pop_front();
            }
            x++,y--;
        }
        x=1,y=t+2;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)printf("%c",a[i][j]);
        printf("\n");
    }
}