#include<bits/stdc++.h>
using namespace std;
int a[26];
char s[54],ans[54];
int main(){
    scanf("%s",s);
    int n=strlen(s);
    int mx=0;
    for(int i=0;i<n;i++){
        a[s[i]-'a']++;
        mx=max(mx,a[s[i]-'a']);
    }
    if(mx>(n+1)/2)return !printf("-1");
    sort(s,s+n);
    for(int i=0;i<(n+1)/2;i++)a[s[i]-'a']--,ans[i]=s[i];
    for(int i=(n+1)/2;i<n;i++){
        int x=s[n-1-i]-'a';
        for(int j=0;j<26;j++)
            if(a[j]&&j!=x){
                a[j]--,ans[i]=j+'a';
                break;
            }
    }
    printf("%s",ans);
}