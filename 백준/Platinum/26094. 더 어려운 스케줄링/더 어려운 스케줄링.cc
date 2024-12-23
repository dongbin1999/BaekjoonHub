#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;scanf("%d%d",&n,&q);
    set<int> se,del;
    deque<int> dq;vector<int> v;
    bool rev=0;
    while(q--){
        int c;scanf("%d",&c);
        if(!c){
            int x;scanf("%d",&x);
            rev?dq.push_front(x):dq.push_back(x);
            v.push_back(x);
        }
        if(c==1){
            se.insert(v.begin(),v.end());
            v.clear(),rev=0;
        }
        if(c==2)rev^=1;
        if(c==3){
            if(rev){
                while(del.count(dq.front()))dq.pop_front();
                int x=dq.front();
                if(se.count(x)){
                    auto it=se.end();it=prev(it);
                    while(del.count(*it))it=prev(it),se.erase(next(it));
                    printf("%d\n",*it),del.insert(*it),se.erase(it);
                }
                else printf("%d\n",x),del.insert(x),dq.pop_front();
            }
            else{
                while(del.count(dq.back()))dq.pop_back();
                int x=dq.back();
                if(se.count(x)){
                    auto it=se.begin();
                    while(del.count(*it))it=next(it),se.erase(prev(it));
                    printf("%d\n",*it),del.insert(*it),se.erase(it);
                }
                else printf("%d\n",x),del.insert(x),dq.pop_back();
            }
        }
    }
}