//#include<bits/stdc++.h>
//using namespace std;
//int no[500][500],n;
//vector<int> a;
//
//void go(int cur){
//    if(cur==n){
//        for(int i=0;i<n;i++)printf("%d %d\n",i+1,a[i]+1);
//        printf("\n");
//        exit(0);
//        return;
//    }
//    for(int i=0;i<n;i++){
//        if(no[cur][i])continue;
//        a.push_back(i);
//        for(int d=0;d<n;d++){
//            int nx=cur+d,ny=i+d;
//            no[nx%n][ny%n]++;
//            nx=cur+d,ny=i;
//            no[nx%n][ny%n]++;
//            nx=cur+d,ny=i-d+n;
//            no[nx%n][ny%n]++;
//        }
//        go(cur+1);
//        for(int d=0;d<n;d++){
//            int nx=cur+d,ny=i+d;
//            no[nx%n][ny%n]--;
//            nx=cur+d,ny=i;
//            no[nx%n][ny%n]--;
//            nx=cur+d,ny=i-d+n;
//            no[nx%n][ny%n]--;
//        }
//        a.pop_back();
//    }
//    return;
//}
//
//int main(){
//    scanf("%d",&n);
//    go(0);
//    return 0;
//}
#include<bits/stdc++.h>
using namespace std;

int main(){
    while(1){
        int n;scanf("%d",&n);
        if(!n)break;
        if(n%6!=1&&n%6!=5)printf("Kralovny se nevejdou.\n");
        else printf("Kralovny lze umistit.\n");
    }
    return 0;
}