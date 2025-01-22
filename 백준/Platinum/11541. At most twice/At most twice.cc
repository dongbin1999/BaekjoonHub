#include<bits/stdc++.h>
using namespace std;

int main(){
    string s,ans;cin>>s;
    if(s.size()>18)return !printf("998877665544332211");
    for(int i=0;i<s.size();i++){
        vector<int> cnt(300);
        string tmp=s;
        bool ok=1;
        for(int j=0;j<=i;j++){
            cnt[s[j]]++;
            if(cnt[s[j]]>2){ok=0;break;}
        }
        vector<int> cnt2=cnt;
        int num='0';
        for(int j=i+1;j<s.size();j++){
            while(cnt[num]>=2)num++;
            tmp[j]=num,cnt[num]++;
        }
        if(tmp>s)ok=0;
        if(ok){
            //printf("%d %lld %lld\n",i,stoll(tmp),stoll(s));
            bool free=0;int idx=i+1;
            while(idx<s.size()){
                if(free){
                    num='9';while(cnt2[num]>=2)num--;
                    tmp[idx++]=num,cnt2[num]++;
                }
                else{
                    num=s[idx]-1;while(num>='0'&&cnt2[num]>=2)num--;
                    if(num<'0'){cnt2[s[idx++]]++;continue;}
                    free=1,tmp[idx++]=num,cnt2[num]++;
                    //printf("%d %d\n",num,s[idx]);
                }
            }
            //cout<<i<<' '<<tmp<<endl;
            if(ans.empty())ans=tmp;
            else ans=max(ans,tmp);
        }
        else break;
    }
    if(ans.empty()){
        for(int i=0,num=9,b=0;i<(int)s.size()-1;i++,b^=1)
            printf("%d",num),num-=b;
    }
    else cout<<ans;
}