#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tup;
struct x_first{int x,y,num;};
bool operator<(x_first a,x_first b){return a.x==b.x?a.num<b.num:a.x<b.x;}
struct y_first{int x,y,num;};
bool operator<(y_first a,y_first b){return a.y==b.y?a.num<b.num:a.y<b.y;}
struct num_first{int x,y,num;};
bool operator<(num_first a,num_first b){return a.num<b.num;}
typedef tree<x_first,null_type,less<x_first>,rb_tree_tag,tree_order_statistics_node_update> x_ordered_set;
typedef tree<y_first,null_type,less<y_first>,rb_tree_tag,tree_order_statistics_node_update> y_ordered_set;
typedef tree<num_first,null_type,less<num_first>,rb_tree_tag,tree_order_statistics_node_update> num_ordered_set;

int mx=-2e9,mn=2e9;
void dnc(bool color,pii p1,pii p2,x_ordered_set &setx,y_ordered_set &sety,num_ordered_set &setnum){
    auto [x1,y1]=p1;auto [x2,y2]=p2;
    if(setnum.empty()){
        int area=(y2-y1)*(x2-x1);
        mx=max(mx,area),mn=min(mn,area);
        return;
    }

    auto [x,y,num]=*setnum.begin();
    setx.erase(setx.find({x,y,num}));
    sety.erase(sety.find({x,y,num}));
    setnum.erase(setnum.find({x,y,num}));
    x_ordered_set newx; y_ordered_set newy; num_ordered_set newnum;

    //printf("\ncolor : %d\n[%d %d %d]\n (%d %d)~(%d %d) : %d==%d==%d\n\n",color,x,y,num,x1,y1,x2,y2,setx.size(),sety.size(),setnum.size());

    pii sp1,sp2,lp1,lp2;int small,large;
    if(color)sp1=p1,sp2={x,y2},lp1={x,y1},lp2=p2,small=setx.order_of_key({x,y,num});
    else sp1=p1,sp2={x2,y},lp1={x1,y},lp2=p2,small=sety.order_of_key({x,y,num});
    large=((int)setnum.size())-small;

    int l,r;
    if(small<large)l=0,r=small-1;
    else l=small,r=((int)setnum.size())-1;
    vector<tup> cache;
    for(int i=l;i<=r;i++){
        int nx,ny,nnum;
        if(color){auto [t1,t2,t3]=*setx.find_by_order(i);cache.push_back({t1,t2,t3});}
        else{auto [t1,t2,t3]=*sety.find_by_order(i);cache.push_back({t1,t2,t3});}
    }
    for(auto [nx,ny,nnum]:cache){
        newx.insert({nx,ny,nnum});
        newy.insert({nx,ny,nnum});
        newnum.insert({nx,ny,nnum});
        setx.erase(setx.find({nx,ny,nnum}));
        sety.erase(sety.find({nx,ny,nnum}));
        setnum.erase(setnum.find({nx,ny,nnum}));
    }

    //printf("%d %d, %d %d -> %d %d, %d %d / %d %d, %d %d\n",x1,y1,x2,y2,sp1.first,sp1.second,sp2.first,sp2.second,lp1.first,lp1.second,lp2.first,lp2.second);

    if(small<large)dnc(!color,sp1,sp2,newx,newy,newnum),dnc(!color,lp1,lp2,setx,sety,setnum);
    else dnc(!color,sp1,sp2,setx,sety,setnum),dnc(!color,lp1,lp2,newx,newy,newnum);
}

int main(){
    int r,c,n;scanf("%d%d%d",&r,&c,&n);
    x_ordered_set setx;y_ordered_set sety;num_ordered_set setnum;
    for(int i=1;i<=n;i++){
        int x,y;scanf("%d%d",&x,&y);
        setx.insert({x,y,i});
        sety.insert({x,y,i});
        setnum.insert({x,y,i});
    }
    dnc(0,{0,0},{r,c},setx,sety,setnum);
    printf("%d %d",mx,mn);
    return 0;
}