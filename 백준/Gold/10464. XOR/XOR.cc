#include <bits/stdc++.h>
using namespace std;

int x(int n)
{
	n++;
	int ret=n%4>1;
	for(int i=2;i<=1e9;i*=2)
		if(n%(i*2)>i && n%(i*2)%2) ret+=i;
	return ret;	
}

int main() {
	int tc;scanf("%d",&tc);
	while(tc--)
	{
		int s,f;scanf("%d %d",&s,&f);
		printf("%d\n",x(f)^x(s-1));
	}
}