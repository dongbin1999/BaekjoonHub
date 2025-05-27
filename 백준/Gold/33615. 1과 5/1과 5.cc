#include<bits/stdc++.h>
using namespace std;
char s[500005];
void solve(){
    scanf("%s",s);
    int n=strlen(s);
    int x=0,f=-1,o=-1;
    for(int i=0;i<n;i++){
        x+=s[i]-'0';
        if(s[i]=='5')f=i;
        if(s[i]=='1')o=i;
    }
    if(x%3==0)printf("0 3\n");
    else if(f==n-1)printf("0 5\n");
    else if(x%3==2&&f!=-1)printf("%d 3\n",f+1);
    else if(x%3==1&&o!=-1)printf("%d 3\n",o+1);
    else{
        if(n%2)printf("1 11\n");
        else printf("0 11\n");
    }
}
int main(){
    int t;scanf("%d",&t);
    while(t--)solve();
}