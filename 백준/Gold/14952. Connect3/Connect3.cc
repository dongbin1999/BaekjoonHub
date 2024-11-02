#include<bits/stdc++.h>
using namespace std;

vector<int> v(16);
int x,y,s;
unordered_set<int> se;
bool check(){
    for(int i=0;i<2;i++)for(int j=0;j<4;j++){
        if(v[i+j*4]&v[i+j*4+1]&v[i+j*4+2])return 1;
        if(v[j+i*4]&v[j+i*4+4]&v[j+i*4+8])return 1;
    }
    for(int i=0;i<2;i++)for(int j=0;j<2;j++){
        if(v[i+j*4]&v[i+j*4+5]&v[i+j*4+10])return 1;
        if(v[i+j*4+2]&v[i+j*4+5]&v[i+j*4+8])return 1;
    }
    return 0;
}
void go(int pre,int c){
    if(check()){
        if(pre==x&&c==1){
            int z=0;
            for(auto i:v)z=z*3+i;
            se.insert(z);
        }
        return;
    }

    for(int i=0;i<16;i++)
        if(!v[i]&&(i<4||v[i-4])){
            v[i]=c;
            go(i,3-c);
            v[i]=0;
        }
}
int main(){
    scanf("%d%d%d",&s,&x,&y);s--;x--,y--;
    x=x*4+y,v[s]=1,go(s,2);
    printf("%d",se.size());
    return 0;
}