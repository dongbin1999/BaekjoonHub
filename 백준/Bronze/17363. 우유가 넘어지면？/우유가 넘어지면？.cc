#include<bits/stdc++.h>
using namespace std;

char s[102][102],ans[102][102];

map<char,char> ma;

int main(){
    int n,m;scanf("%d%d",&n,&m);
    ma['.']='.';ma['O']='O';
    ma['-']='|';
    ma['|']='-';
    ma['/']='\\';
    ma['\\']='/';
    ma['^']='<';
    ma['<']='v';
    ma['v']='>';
    ma['>']='^';
    for(int i=0;i<n;i++){
        scanf("%s",s[i]);
        for(int j=0;j<m;j++)ans[j][i]=ma[s[i][m-1-j]];
    }
    for(int i=0;i<m;i++)printf("%s\n",ans[i]);
}