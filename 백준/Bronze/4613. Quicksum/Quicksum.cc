#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while(1){
        getline(cin,s);
        if(s=="#")break;
        int ans=0;
        for(int i=0;i<s.size();i++)if(isalpha(s[i]))
            ans+=(s[i]-'A'+1)*(i+1);
        printf("%d\n",ans);
    }
}