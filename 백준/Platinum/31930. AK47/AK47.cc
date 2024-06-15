#include<bits/stdc++.h>
using namespace std;

bool b(int l,int r){
    printf("AK %d %d\n",l,r);fflush(stdout);
    char c;scanf(" %c",&c);
    return c=='O';
}

void solve(){
    int n;scanf("%d",&n);
    vector<int> ans;
    if(n<=47){
        for(int i=1;i<=n;i++)if(b(i,i))ans.push_back(i);
        printf("! %d %d\n",ans[0],ans[1]);fflush(stdout);return;
    }
    int l=1,r=n/2;
    if(b(l,r)){//[1~n/2]에 하나, [n/2+1~n]에 하나.
        int L=l,R=r,mid,x=R;
        while(L<=R){
            mid=(L+R)/2;
            if(b(l,mid))x=min(x,mid),R=mid-1;
            else L=mid+1;
        }
        ans.push_back(x);
        L=r+1,R=n,x=R;
        while(L<=R){
            mid=(L+R)/2;
            if(b(r+1,mid))x=min(x,mid),R=mid-1;
            else L=mid+1;
        }
        ans.push_back(x);
        printf("! %d %d\n",ans[0],ans[1]);fflush(stdout);return;
    }
    while(1){
        l++,r++;
        if(b(l,r)){//보물이 l-1또는 r에 있다.
            if(b(l-1,l-1)){//l-1에 있다. -> 다른 보물은 [l~n/2]에 있다.
                ans.push_back(l-1);
                while(l<n/2){
                    if(b(l,l)){ans.push_back(l);break;}
                    l++;
                }
                if(ans.size()==1)ans.push_back(l);
            }
            else{//r에 있다. -> 다른 보물은 [r+1~n]에 있다.
                ans.push_back(r);
                ++r;
                while(r<n){
                    if(b(r,r)){ans.push_back(r);break;}
                    r++;
                }
                if(ans.size()==1)ans.push_back(r);
            }
            break;
        }
    }
    printf("! %d %d\n",ans[0],ans[1]);fflush(stdout);return;
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
}