#include <bits/stdc++.h>
using namespace std;

int main() {
	int s,a,b;scanf("%d%d%d",&s,&a,&b);
	printf("%d",max(0,(s-a+b-1))/b*100+250);
	return 0;
}