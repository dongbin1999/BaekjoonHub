#include<bits/stdc++.h>
using namespace std;
typedef array<int,3> arr;
char str[40];
vector<int> g[3001];
int in[3001];
int main(){
    int n;scanf("%d",&n);
    vector<string> name(n+1);
    vector<arr> pas(n+1);
    for(int i=1;i<=n;i++){
        int p,a,s;scanf("%s%d%d%d",str,&p,&a,&s);
        pas[i]={p,a,s},name[i]=str;
        for(int j=1;j<i;j++){
            int score=0;
            for(int x=0;x<3;x++)
                if(pas[j][x]<pas[i][x])score++;
                else if(pas[j][x]>pas[i][x])score--;
            if(score>0)g[i].push_back(j),in[j]++;
            else if(score<0)g[j].push_back(i),in[i]++;
        }
    }
    vector<string> ans;
    queue<int> q;
    for(int i=1;i<=n;i++)if(!in[i])q.push(i),ans.push_back(name[i]);
    while(!q.empty()){
        int cur=q.front();q.pop();
        for(auto nx:g[cur])
            if(--in[nx]==0)q.push(nx);
    }
    for(int i=1;i<=n;i++)if(in[i])return !printf("Paradoxe Absurdo");
    sort(ans.begin(),ans.end());
    for(auto a:ans){
        for(auto c:a)printf("%c",c);
        printf("\n");
    }
}