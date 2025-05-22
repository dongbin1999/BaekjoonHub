#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    int len=(n+24)/25+1;
    string ans;
    for(int i=0;i<len;i++)ans+=i%2?'z':'a';
    int remain=(len-1)*25-n;
    while(remain>1){
        ans[1]--;
        remain-=ans.size()==2?1:2;
    }
    if(remain==1){
        if(ans.back()=='a')ans.back()++;
        else ans.back()--;
    }
    for(auto i:ans)printf("%c",i);
    return 0;
}