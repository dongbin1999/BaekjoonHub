#include<bits/stdc++.h>
using namespace std;
bool b[20000];
char r[4][3][3]={{'F','F','F','F','U','U','F','U','T',},
{'F','U','T','U','U','T','T','T','T',},
{'T','T','T','U','T','T','F','U','T',},
{'T','F','F','F','T','F','F','F','T',}};

unordered_map<string,int> si;
string is[20000];
char ic[3];int ci[300];
int rsi[20000];

int op(int X,int Y,int op){
    string x=is[X],y=is[Y];
    string s;
    for(int i=0;i<9;i++)s+=r[op][ci[x[i]]][ci[y[i]]];
    //cout<<x<<", "<<y<<", "<<op<<": "<<s<<endl;
    return si[s];
}

int main(){
    int mx=3*3*3*3*3*3*3*3*3;
    ci['U']=1,ci['T']=2,ic[0]='F',ic[1]='U',ic[2]='T';
    for(int i=0;i<mx;i++){
        string s;int x=i;
        for(int j=0;j<9;j++)s+=ic[x%3],x/=3;
        is[i]=s,si[s]=i;
    }
    for(int i=0;i<mx;i++){
        string s=is[i],rot=s;
        for(int j=0;j<9;j++)rot[j%3*3+j/3]=s[j];
        rsi[i]=si[rot];
    }

    int init=si["FFFUUUTTT"];
    queue<int> q;q.push(init),b[init]=1;
    while(!q.empty()){
        int cur=q.front();q.pop();
        //cout<<is[cur]<<" "<<cur<<endl;
        for(int i=0;i<mx;i++){
            if(!b[i])continue;
            for(int o=0;o<4;o++){
                int nx=op(cur,i,o);
                if(!b[nx])b[nx]=1,q.push(nx);
                nx=op(cur,rsi[i],o);
                if(!b[nx])b[nx]=1,q.push(nx);
            }
        }
    }

    int n;scanf("%d",&n);
    while(n--){
        string s;
        for(int i=0;i<9;i++){
            char c;scanf(" %c",&c);
            s+=c;
        }
        printf(b[si[s]]?"definable\n":"undefinable\n");
    }
}