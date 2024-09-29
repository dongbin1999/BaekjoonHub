#include <bits/stdc++.h>
using namespace std;
int mx=5e6,chk=6e6+1;

int d[10][10];

int main(){
    int a,b;scanf("%d%d",&a,&b);
    vector<int> v(chk,-1);v[a]=0;
    queue<int> q;q.push(a);
    for(int len=1;len<=7;len++){
        int x=1;
        for(int i=len-1;i>=0;i--)d[len][i]=x,x*=10;
    }
    while(!q.empty()){
        a=q.front();q.pop();
        string s=to_string(a); int cost=v[a];
        if(a==b)return !printf("%d",cost);
        for(int i=0;i<s.size();i++){
            if(s[i]>'0'+!i){
                int x=a-d[s.size()][i];
                if(v[x]==-1)v[x]=cost+1,q.push(x);
            }
            if(s[i]<'9'){
                int x=a+d[s.size()][i];
                if(x<chk&&v[x]==-1)v[x]=cost+1,q.push(x);
            }
        }
        if(a+1<chk&&v[a+1]==-1)v[a+1]=cost+1,q.push(a+1);
        if(a>0&&v[a-1]==-1)v[a-1]=cost+1,q.push(a-1);
    }
    return 0;
}