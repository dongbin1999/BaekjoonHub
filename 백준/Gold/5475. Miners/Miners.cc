#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    vector<vector<int>> v(28,vector<int>(28,-1e9));
    vector<int> val(27);
    for(int i=0;i<27;i++){
        set<int> se;
        int x=i;for(int j=0;j<3;j++)se.insert(x%3),x/=3;
        val[i]=se.size();
    }
    v[27][27]=0;
    while(n--){
        char c;scanf(" %c",&c);
        int x;if(c=='M')x=0;else if(c=='B')x=1;else x=2;
        auto nv=v;
        for(int i=0;i<28;i++)for(int j=0;j<28;j++){
            if(i==27)nv[x*13][j]=max(nv[x*13][j],v[i][j]+1);
            else{
                int y=(i*3+x)%27;
                nv[y][j]=max(nv[y][j],v[i][j]+val[y]);
            }
            if(j==27)nv[i][x*13]=max(nv[i][x*13],v[i][j]+1);
            else{
                int y=(j*3+x)%27;
                nv[i][y]=max(nv[i][y],v[i][j]+val[y]);
            }
        }
        v=nv;
    }
    int ans=0;
    for(int i=0;i<28;i++)for(int j=0;j<28;j++)ans=max(ans,v[i][j]);
    printf("%d",ans);
    return 0;
}