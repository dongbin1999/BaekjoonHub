#include <bits/stdc++.h>
using namespace std;

vector<int> v;
void del(map<int,set<int>> &ma,set<int> &se,int i){
    auto &s=ma[v[i]];
    s.erase(s.find(i));
    if(s.size()==1)se.insert(*s.begin());
    if(s.empty())ma.erase(ma.find(v[i])),se.erase(se.find(i));
}
void add(map<int,set<int>> &ma,set<int> &se,int i){
    auto &s=ma[v[i]];
    if(s.size()==1)se.erase(se.find(*s.begin()));//추가하면 unique하지 않게됨.
    s.insert(i);
    if(s.size()==1)se.insert(i);//unique한 숫자가 추가됨.
}

void print(int l,int r,map<int,set<int>> &ma,set<int> &se){
    printf("[l : %d r : %d]\n",l,r);
    printf("ma\n");
    for(auto [num,s]:ma){
        printf("%d : ",num);
        for(auto i:s)printf("%d ",i);
        printf("\n");
    }
    printf("se : ");
    for(auto i:se)printf("%d ",i);
    printf("\n\n");
}

bool dnc(int l,int r,map<int,set<int>> &ma,set<int> &se){
    //print(l,r,ma,se);
    if(l>=r)return 1;
    if(se.empty())return 0;
    int mid=*se.begin();
    if(mid-l<r-mid){//왼쪽 구간이 더 작음. 왼쪽에 덜어줌.
        map<int,set<int>> lema;
        set<int> lese;
        for(int i=l;i<mid;i++)
            add(lema,lese,i),del(ma,se,i);
        del(ma,se,mid);
        return dnc(l,mid-1,lema,lese)&&dnc(mid+1,r,ma,se);
    }
    else{
        map<int,set<int>> rima;
        set<int> rise;
        for(int i=mid+1;i<=r;i++)
            add(rima,rise,i),del(ma,se,i);
        del(ma,se,mid);
        return dnc(l,mid-1,ma,se)&&dnc(mid+1,r,rima,rise);
    }
}

void solve(){
    int n;scanf("%d",&n);
    v.resize(n+1);
    map<int,set<int>> ma;//숫자, 인덱스들
    set<int> se;//unique한 숫자들 위치
    for(int i=1;i<=n;i++)scanf("%d",&v[i]),add(ma,se,i);
    printf(dnc(1,n,ma,se)?"non-boring\n":"boring\n");
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
    return 0;
}