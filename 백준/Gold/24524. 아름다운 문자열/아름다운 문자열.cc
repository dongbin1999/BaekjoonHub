#include <bits/stdc++.h>
using namespace std;

char s[1000002],t[27];
int a[27];

int main() {
	scanf("%s %s",s+1,t+1);
	a[0]=1e9;
	int ns=strlen(s+1),nt=strlen(t+1);
	for(int i=1;i<=ns;i++){
		int x=-1;
		for(int j=1;j<=nt;j++)if(s[i]==t[j])x=j;
		if(x<0)continue;
		if(a[x-1])a[x-1]--,a[x]++;
	}
	printf("%d",a[nt]);
	return 0;
}