#include <bits/stdc++.h>
using namespace std;
#define num(x) (isalpha(x)?x-'A'+10:x-'0')
#define alp(x) (x<10?x+'0':x-10+'A')

void update(vector<int> &v){//00000..00GOOD
    for(int i=59;i>0;i--)
        v[i-1]+=v[i]/36,v[i]%=36;
}

vector<int> operator+(vector<int> a,vector<int> b){//GOOD+LUCK
    reverse(a.begin(),a.end());
    a.resize(60);
    reverse(b.begin(),b.end());
    b.resize(60);
    vector<int> c(60);
    for(int i=0;i<60;i++)c[i]=a[i]+b[i];
    reverse(c.begin(),c.end());
    update(c);
    return c;
}

int main(){
    int n;scanf("%d",&n);
    vector<vector<int>> s;

    for(int i=0;i<n;i++){
        string st;cin>>st;
        vector<int> tmp;
        for(auto j:st)tmp.push_back(num(j));
        s.push_back(tmp);
    }

    int k;scanf("%d",&k);
    vector<int> tmp(60,0);
    vector<pair<vector<int>,int>> v;
    for(int i=0;i<36;i++)v.push_back({tmp,i});
    for(auto st:s)
        for(int i=0;i<st.size();i++)
            //'X'->'Z' 보다 '0'->'Z'가 더 유리함.
            v[st[i]].first[60-(st.size()-i)]+=35-st[i];
    for(int i=0;i<v.size();i++)update(v[i].first);
    sort(v.begin(),v.end(),greater<pair<vector<int>,int>>());

    //Z(35)로 바꾸기
    map<int,int> ma;
    for(int i=0;i<k;i++)ma[v[i].second]=1;
    for(auto &i:s)for(auto &j:i)if(ma[j])j=35;

    vector<int> ans(60,0);
    for(auto st:s)ans=ans+st;

    int idx=0;
    //leading zero 떼기
    while(idx<60&&!ans[idx])idx++;
    if(idx==60)printf("0");
    else for(int i=idx;i<ans.size();i++)printf("%c",alp(ans[i]));
    return 0;
}