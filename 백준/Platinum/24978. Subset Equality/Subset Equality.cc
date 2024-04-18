#include<bits/stdc++.h>
using namespace std;
char a[100002],b[100002];int an,bn;

string s[2][18][18];
bool ok[18][18];

int main(){
    scanf("%s",a);an=strlen(a);
    scanf("%s",b);bn=strlen(b);
    for(int x=0;x<an;x++)for(char i='a';i<='r';i++)for(char j=i;j<='r';j++)
        if(a[x]==i||a[x]==j)s[0][i-'a'][j-'a']+=a[x];
    for(int x=0;x<bn;x++)for(char i='a';i<='r';i++)for(char j=i;j<='r';j++)
        if(b[x]==i||b[x]==j)s[1][i-'a'][j-'a']+=b[x];
    for(int i=0;i<18;i++)for(int j=i;j<18;j++)if(s[0][i][j]==s[1][i][j])ok[i][j]=1;
    int q;scanf("%d",&q);
    while(q--){
        scanf("%s",a);int n=strlen(a);
        bool ans=1;
        for(int i=0;i<n;i++)for(int j=i;j<n;j++)
            ans&=ok[a[i]-'a'][a[j]-'a'];
        printf(ans?"Y":"N");
    }
}