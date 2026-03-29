#include<bits/stdc++.h>
using namespace std;
int c[26][300000],x[3];
char s[3][300000],ans[300000];

int main(){
    int n;scanf("%d",&n);
    scanf("%s %s %s",s[0],s[1],s[2]);
    for(int i=0;i<n;i++){
        c[s[0][i]-'a'][i]|=1;
        c[s[1][i]-'a'][i]|=2;
        c[s[2][i]-'a'][i]|=4;
    }

    //1,3,7은 무조건 선택, 4,6은 무조건 버림
    for(int i=0;i<n;i++)
        for(int a=0;a<26;a++)
            if(c[a][i]==4||c[a][i]==6||c[a][i]==0)continue;
            else if(c[a][i]==1||c[a][i]==3||c[a][i]==7){
                ans[i]=a+'a';
                x[0]+=c[a][i]>>0&1;
                x[1]+=c[a][i]>>1&1;
                x[2]+=c[a][i]>>2&1;
                break;
            }

    //2,5를 합치는건 의미가 없으므로, 2만 고르거나 5만골라야 함. 그 개수는 모자란 만큼만.
    if(x[0]<=x[1]){
        for(int i=0;i<n&&x[0]<=x[1];i++){
            if(ans[i])continue;
            for(int a=0;a<26;a++)if(c[a][i]==5){
                ans[i]=a+'a';
                x[0]++,x[2]++;
                break;
            }
        }
    }
    else if(x[1]<=x[2]){
        for(int i=0;i<n&&x[1]<=x[2];i++){
            if(ans[i])continue;
            for(int a=0;a<26;a++)if(c[a][i]==2){
                ans[i]=a+'a';
                x[1]++;
                break;
            }
        }
        // 1에서 끌어다 쓰기.
        if(x[1]<=x[2])
        for(int i=0;i<n&&x[1]<=x[2];i++){
            int t=0;
            for(int a=0;a<26;a++)
            if(c[a][i]==1)t=1;
            else if(c[a][i]==2&&t){
                ans[i]=a+'a';
                x[1]++,x[0]--;
                break;
            }
        }    
    }

    if(x[0]<=x[1]||x[1]<=x[2])return !printf("-1");
    
    //나머지는 0인거 아무거나 고르기.
    for(int i=0;i<n;i++){
        if(ans[i])continue;
        for(int a=0;a<26;a++)if(!c[a][i]){
            ans[i]=a+'a';break;
        }
    }
    printf("%s",ans);
}