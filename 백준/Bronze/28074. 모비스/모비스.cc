#include<bits/stdc++.h>
using namespace std;
int a[300];
int main(){
    a['M']=a['O']=a['B']=a['I']=a['S']=-1;
    string s;cin>>s;
    for(auto i:s)a[i]++;
    return !printf(*min_element(a,a+300)<0?"NO":"YES");
}
