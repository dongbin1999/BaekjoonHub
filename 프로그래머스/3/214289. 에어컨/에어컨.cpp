#include<bits/stdc++.h>
using namespace std;

int dp[51][1001];

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    int n=onboard.size();
    t1+=10,t2+=10,temperature+=10;
    memset(dp,0x3f,sizeof(dp));
    dp[temperature][0]=0;
    for(int i=0;i<n-1;i++){//현재 i분, i+1분으로 넘어감.
        for(int t=0;t<=50;t++){//현재 t도,nt도로 넘어감.
            int nt=t;
            //에어컨 껐음(0원 소모)
            if(temperature<t)nt--;else if(temperature>t)nt++;
            if(!(onboard[i+1]&&(nt<t1||t2<nt)))//이상한 경우가 아니라면,
                dp[nt][i+1]=min(dp[nt][i+1],dp[t][i]);
            //희망온도 설정했음(a or b원 소모)
            for(int d=-1;d<=1;d++){
                nt=t+d;if(nt<0||nt>50)continue;
                int add=!d?b:a;
                if(!(onboard[i+1]&&(nt<t1||t2<nt)))//이상한 경우가 아니라면,
                    dp[nt][i+1]=min(dp[nt][i+1],dp[t][i]+add);
            }
        }
    }
    int answer = 1e9;
    for(int t=0;t<=50;t++)answer=min(answer,dp[t][n-1]);
    return answer;
}