#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define U 0
#define L 1
#define D 2
#define R 3
#define in(x,y) (1<=x&&x<=r&&1<=y&&y<=c)
string s="ULDR";
vector<pii> go={{-1,0},{0,-1},{1,0},{0,1}};//uldr

bool vis[101][101];
int r,c,x,y;
array<int,5> rotate(int &rot){//시계방향 회전
    return {c,r,y,(r+1-x),(rot+3)%4};
}
vector<int> ans;
void print(int rot){
    for(auto i:ans)printf("%c",s[(i+rot)%4]);
    printf("\n");
}
bool move(int dir){
    auto [dx,dy]=go[dir];
    if(!in(x+dx,y+dy)||vis[x+dx][y+dy])return 0;
    ans.push_back(dir),x+=dx,y+=dy,vis[x][y]=1;
    return 1;
}

void solve(){
    memset(vis,0,sizeof(vis)),ans.clear();
    int rot=0;scanf("%d%d%d%d",&r,&c,&x,&y);
    vis[x][y]=1;
    if(r==1||c==1){
        for(int i=0;i<4;i++){
            auto [dx,dy]=go[i];
            while(move(i));
        }
        if(ans.size()!=r*c-1)printf("IMPOSSIBLE\n");
        else print(rot);
        return;
    }
    for(int i=0;i<4;i++){
        //rotate
        auto [aa,bb,cc,dd,ee]=rotate(rot);
        r=aa,c=bb,x=cc,y=dd,rot=ee;
        int le=y-1,ri=c-y,up=x-1,down=r-x;
        if(!up)continue;
        int flip=0;
        if(le%2==0&&ri%2)flip=2,swap(le,ri);
        if(le%2&&ri%2==0){
            while(move((R+flip)%4));
            for(int j=0;j<ri+1;j++){
                while(move(j%2?D:U));
                move((L+flip)%4);
            }
            for(int j=0;j<le;j++){
                int it=up;while(it--)move(j%2?U:D);
                move((L+flip)%4);
            }
            for(int j=0;j<down;j++){
                move(D);
                while(move(j%2?(L+flip)%4:(R+flip)%4));
            }
            print(rot);return;
        }
    }
    //홀홀홀,짝짝짝 확인
    for(int i=0;i<4;i++){
        //rotate
        auto [aa,bb,cc,dd,ee]=rotate(rot);
        r=aa,c=bb,x=cc,y=dd,rot=ee;
        int le=y-1,ri=c-y,up=x-1,down=r-x;
        if(!up)continue;
        int flip=0;
        if(le>ri)flip=2,swap(le,ri);
        //le<=ri. le부터 가자.
        if(le%2==0&&ri%2==0&&up%2==0){
            while(move((L+flip)%4));
            for(int j=0;j<le+1;j++){
                while(move(j%2?D:U));
                move((R+flip)%4);
            }
            for(int j=0;j<up+1;j++){
                while(move(j%2?(L+flip)%4:(R+flip)%4));
                move(D);
            }
            for(int j=0;j<down;j++){
                while(move(j%2?(R+flip)%4:(L+flip)%4));
                move(D);
            }
            print(rot);return;
        }
        if(le%2&&ri%2&&up%2){
            while(move((L+flip)%4));
            for(int j=0;j<le+1;j++){
                while(move(j%2?D:U));
                move((R+flip)%4);
            }
            for(int j=0;j<up;j++){
                move(U);
                int it=le;while(it--)move(j%2?(L+flip)%4:(R+flip)%4);
            }
            for(int j=0;j<ri;j++){
                move((R+flip)%4);
                int it=up;while(it--)move(j%2?U:D);
            }
            for(int j=0;j<down;j++){
                move(D);
                while(move(j%2?(R+flip)%4:(L+flip)%4));
            }
            print(rot);return;
        }
    }
    printf("IMPOSSIBLE\n");
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
    return 0;
}