#include<bits/stdc++.h>
using namespace std;
char s[501];

void solve(){
    int n,p;scanf("%d%d",&n,&p);
    scanf("%s",s);
    string ans=s;
    for(int it=1;it<=50;it++){
        int cnt=0,idx=-1;
        for(int i=0;i<ans.size();i++){
            if(ans[i]=='*')cnt++;
            if(cnt==it){idx=i;break;}
        }
        if(idx==-1)break;
        //it번째 *좌우의 항을 ()로 묶는다.
        int pre=idx-1,nx=idx+1;
        if(ans[pre]==')'){
            int c=0;
            while(c!=1||ans[pre]!='('){
                if(ans[pre]==')')c++;else if(ans[pre]=='(')c--;
                pre--;
            }
        }
        else {
            while(pre>=0&&('0'<=ans[pre]&&ans[pre]<='9'))pre--;
            pre++;
        }
        if(ans[nx]=='('){
            int c=0;
            while(c!=1||ans[nx]!=')'){
                if(ans[nx]=='(')c++;else if(ans[nx]==')')c--;
                nx++;
            }
        }
        else {
            while(nx<ans.size()&&('0'<=ans[nx]&&ans[nx]<='9'))nx++;
            nx--;
        }
        string nans;
        for(int i=0;i<ans.size();i++){
            if(i==pre)nans+='(';
            nans+=ans[i];
            if(i==nx)nans+=')';
        }
        ans=nans;
    }
    printf("%d\n",ans.size());
    cout<<ans<<endl;
}

int main(){
    solve();
    return 0;
}