#include <bits/stdc++.h>
using namespace std;
set<char> mark={'?','!',',','.'};

string result(string s,bool b){
    string x=b?" of Korea":"Korea ";
    if(!b)reverse(s.begin(),s.end()),reverse(x.begin(),x.end());
    int pre=0,pos=s.find(x,pre);
    string ret=s.substr(pre,pos-pre);
    while(pos!=string::npos){
        if(!b){
            if(isalpha(s[pos+x.size()]))ret+=x;
            else ret+='#';
        }
        else if(!mark.count(ret.back())){
            if(isalpha(s[pos+x.size()]))ret+=x;
            else ret+='@';
        }
        else ret+=x;
        pre=pos+x.size(),pos=s.find(x,pre);
        if(pos!=string::npos)ret+=s.substr(pre,pos-pre);
        else ret+=s.substr(pre);
    }
    if(!b)reverse(ret.begin(),ret.end());
    return ret;
}

int main(){
    int n;cin>>n;
    string s;getline(cin,s);
    while(n--){
        getline(cin,s);
        string ans;
        s=result(s,1),s=result(s,0);
        stringstream parse(s);
        while(parse>>s){
            char m=0;if(mark.count(s.back()))m=s.back(),s.pop_back();
            string word;
            bool first=0,up=0;
            while(!s.empty()&&s.back()=='@')up=1,word+="K-",s.pop_back();
            for(auto c:s){
                if(c=='#')up=1,word+="K-";
                else if(up&&!first)first=1,word+=toupper(c);
                else word+=c;
            }
            if(m)word+=m;word+=' ';
            ans+=word;
        }
        ans.pop_back();
        cout<<ans<<endl;
    }
    return 0;
}