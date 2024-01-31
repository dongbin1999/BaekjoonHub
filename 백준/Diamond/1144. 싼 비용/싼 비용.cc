#include <bits/stdc++.h>
using namespace std;
//참고: https://jh05013.github.io/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98/Connection%20profile%20DP
const int mx=21147;//9번째 bell number
#define update(x,y) x=min(x,y)
int a[81],dp[81][mx],numbering;
map<deque<int>,int> state;
vector<deque<int>> denormalize;

//경우의 수 줄이기 위한 정규화.
int normalize(deque<int> dq){
    deque<int> ndq;
    unordered_map<int,int> ma;int x=0;
    for(auto i:dq){
        if(i&&!ma.count(i))ma[i]=++x;
        ndq.push_back(ma[i]);
    }
    if(!state.count(ndq))state[ndq]=numbering++,denormalize.push_back(ndq);
    return state[ndq];
}

int main() {
    int n,m;scanf("%d%d",&n,&m);
    memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<n*m;i++)scanf("%d",&a[i]);
    deque<int> cur(m);
    update(dp[0][normalize(cur)],0);
    cur.back()=1,update(dp[0][normalize(cur)],a[0]);
    int ans=min(0,a[0]);
    for(int i=0;i<n*m-1;i++)for(int st=0;st<numbering;st++){
        if(dp[i][st]>1e9)continue;
        deque<int> dq=denormalize[st],ndq;

        //Case #2-(2)-1: 다음 칸을 선택할건데, 오른쪽 칸이 선택된 칸이면 그 숫자를 그대로 따라가고, 아니라면 새로운 연결 상태를 만든다.
        int nx=(i+1)%m&&dq.back()?dq.back():*max_element(dq.begin(),dq.end())+1;
        ndq=dq,ndq.push_back(nx);
        if(ndq.front()){
            int num=ndq.front();
            for(auto &x:ndq)
                if(x==num)x=ndq.back();
        }
        ndq.pop_front();
        int nst=normalize(ndq);
        update(dp[i+1][nst],dp[i][st]+a[i+1]);
        ndq=denormalize[nst];
        if(*max_element(ndq.begin(),ndq.end())==1)update(ans,dp[i+1][nst]);//연결 상태가 1가지인 경우만 답의 후보가 된다.

        //Case #1: 위쪽 칸이 선택되어있고, 다른 칸들과 연결되어있지 않음 -> 다음 칸을 선택할 수 없다.
        //why? 다음 상태에서 위쪽 칸은 더 이상 고려 대상이 아닌 회색 칸이 되기 때문에, 그 연결 상태를 알고있는 다른 누군가가 필요하다.
        if(dq.front()){
            bool connedted=0;
            for(int x=1;x<dq.size();x++)connedted|=dq[x]==dq.front();
            if(!connedted)continue;
        }

        //Case #2-(1): 다음 칸을 선택하지 않는다.
        ndq=dq,ndq.push_back(0),ndq.pop_front();
        nst=normalize(ndq);
        update(dp[i+1][nst],dp[i][st]);
        ndq=denormalize[nst];
        if(*max_element(ndq.begin(),ndq.end())==1)update(ans,dp[i+1][nst]);//연결 상태가 1가지인 경우만 답의 후보가 된다.
    }

    printf("%d",ans);
}