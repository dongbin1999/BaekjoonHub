#include <bits/stdc++.h>
using namespace std;

char s[1010][1010];

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]+1);

    deque<int> dq;
    for(int i=1;i<=n;i++){
        if(dq.empty())dq.push_back(i);
        else if(s[i][dq.front()]!='-')dq.push_front(i);
        else if(s[i][dq.back()]!='+')dq.push_back(i);
        else{
            int add=-1;
            for(int j=0;j<dq.size();j++)
                if(s[i][dq[j]]!='-'){add=j;break;}
            deque<int> dq2;
            for(int j=0;j<dq.size();j++){
                if(j==add)dq2.push_back(i);
                dq2.push_back(dq[j]);
            }
            dq=dq2;
        }
    }
    assert(dq.size()==n);
    for(auto i:dq)printf("%d ",i);
    return 0;
}