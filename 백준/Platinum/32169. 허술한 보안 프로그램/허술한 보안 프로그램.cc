#include<bits/stdc++.h>
using namespace std;

vector<int> query(vector<int> v){
    printf("? ");
    for(auto i:v)printf("%d ",i);
    printf("\n");
    fflush(stdout);
    vector<int> r(v.size());
    for(auto &i:r)scanf("%d",&i);
    return r;
}

int main(){
    int n;scanf("%d",&n);
    vector<int> a(n),b(n),ans(n);
    if(n==1){printf("! 0");fflush(stdout);return 0;}
    int x=1;while(n>x)x<<=1;x--;
    set<int> se;
    for(int i=n-1;i>=0;i--){
        a[i]=i,b[i]=x^i;
        while(b[i]>=n||se.count(b[i]))b[i]^=1<<(31-__builtin_clz(b[i]));
        se.insert(b[i]);
        assert(b[i]>=0);
    }
    for(int i=0;i<n;i++)assert((a[i]&b[i])==0);
    a=query(a),b=query(b);
    printf("! ");
    for(int i=0;i<n;i++)printf("%d ",a[i]&b[i]);
    fflush(stdout);
}