#include<bits/stdc++.h>
using namespace std;

int main(){
    int x;string s;cin>>x>>s;
    printf(*max_element(s.begin(),s.end())==*min_element(s.begin(),s.end())?"Yes":"No");
    return 0;
}