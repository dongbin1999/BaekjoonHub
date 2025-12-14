#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while(getline(cin,s)){
        for(auto i:s){
            if(i=='e')i='i';
            else if(i=='i')i='e';
            else if(i=='E')i='I';
            else if(i=='I')i='E';
            cout<<i;
        }
        cout<<endl;
    }
    return 0;
}