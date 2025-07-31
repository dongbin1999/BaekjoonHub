#include<bits/stdc++.h>
using namespace std;
int a[1000][1000];
int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            if(!j||(j==1&&i==2)){
                for(int x=i*n;x<(i+1)*n;x++)for(int y=j*n;y<(j+1)*n;y++)
                    a[x][y]=1;
            }
            else if(j-abs(2-i)==2){
                    for(int x=i*n;x<(i+1)*n;x++)for(int y=j*n;y<(j+1)*n;y++)
                            a[x][y]=1;
            }
            else if(j-abs(2-i)>2){
                for(int x=i*n;x<(i+1)*n;x++)for(int y=j*n;y<(j+1)*n;y++)
                        a[x][y]=2;
            }
    for(int x=0;x<n*5;x++){
        for(int y=0;y<n*5;y++)if(a[x][y]==2)break;
        else printf(a[x][y]?"@":" ");
        printf("\n");
    }
}