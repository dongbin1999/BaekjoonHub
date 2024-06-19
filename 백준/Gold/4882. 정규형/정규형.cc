#include<bits/stdc++.h>
using namespace std;
char s[50000];

void solve(){
    int lv=0,n=strlen(s);
    string v;
    int mx=0,cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='(')cnt++;
        else if(s[i]==')')cnt--;
        mx=max(mx,cnt);
    }
    for(int i=0;i<n;i++){
        if(s[i]=='(')lv++,v+='(';
        else if(s[i]==')'){
            if((lv+mx)%2==0){
                bool b=1;
                while(v.back()!='(')b&=v.back()=='T',v.pop_back();
                v.pop_back();v+=b?'T':'F';
            }
            else{
                bool b=0;
                while(v.back()!='(')b|=v.back()=='T',v.pop_back();
                v.pop_back();v+=b?'T':'F';
            }
            lv--;
        }
        else{
            v+=s[i];
        }
    }
    printf(v[0]=='T'?"true\n":"false\n");
}

int main(){
    int t=1;
    while(1){
        scanf("%s",s);
        if(s[1]==')')break;
        printf("%d. ",t++);
        solve();
    }
    return 0;
}