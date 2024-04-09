#include<bits/stdc++.h>
using namespace std;
typedef array<int,3> tup;
int v[3][3][100001];//0:empty 1:empty<x<full 2:full
int s(int x,int y){
    if(!x)return 0;
    else if(x<y)return 1;
    else return 2;
}

int main(){
    int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
    memset(v,0x3f,sizeof(v));
    queue<tup> q;q.push({0,0,0});v[0][0][0]=0;
    int nx,ny,ls,rs,val;
    while(!q.empty()){
        auto[l,r,dist]=q.front();q.pop();
        if(l==c&&r==d)return !printf("%d",dist);

        nx=a,ny=r,ls=s(nx,a),rs=s(ny,b);//fill x
        val=0;if(ls==1)val=nx;else if(rs==1)val=ny;
        if(v[ls][rs][val]>1e9)v[ls][rs][val]=dist+1,q.push({nx,ny,dist+1});
        nx=0,ny=r,ls=s(nx,a),rs=s(ny,b);//empty x
        val=0;if(ls==1)val=nx;else if(rs==1)val=ny;
        if(v[ls][rs][val]>1e9)v[ls][rs][val]=dist+1,q.push({nx,ny,dist+1});

        nx=l,ny=b,ls=s(nx,a),rs=s(ny,b);//fill y
        val=0;if(ls==1)val=nx;else if(rs==1)val=ny;
        if(v[ls][rs][val]>1e9)v[ls][rs][val]=dist+1,q.push({nx,ny,dist+1});
        nx=l,ny=0,ls=s(nx,a),rs=s(ny,b);//empty y
        val=0;if(ls==1)val=nx;else if(rs==1)val=ny;
        if(v[ls][rs][val]>1e9)v[ls][rs][val]=dist+1,q.push({nx,ny,dist+1});

        int z=b-r,move=min(l,z);
        nx=l-move,ny=r+move,ls=s(nx,a),rs=s(ny,b);//move x to y
        val=0;if(ls==1)val=nx;else if(rs==1)val=ny;
        if(v[ls][rs][val]>1e9)v[ls][rs][val]=dist+1,q.push({nx,ny,dist+1});

        z=a-l,move=min(r,z);
        nx=l+move,ny=r-move,ls=s(nx,a),rs=s(ny,b);//move y to x
        val=0;if(ls==1)val=nx;else if(rs==1)val=ny;
        if(v[ls][rs][val]>1e9)v[ls][rs][val]=dist+1,q.push({nx,ny,dist+1});
    }
    printf("-1");
}