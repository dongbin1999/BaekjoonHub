#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;scanf("%d",&n);
	int al[10]={6,2,5,5,4,5,6,3,7,6};
	for(int a=0;a<=9;a++)
		for(int b=0;b<=9;b++)
			for(int c=0;c<=9;c++)
				for(int d=0;d<=9;d++)
					for(int e=0;e<=9;e++)
						for(int f=0;f<=9;f++){
							int x=a*10+b,y=c*10+d,z=e*10+f;
							if(x+y!=z)continue;
							if(al[a]+al[b]+al[c]+al[d]+al[e]+al[f]+4==n){
								printf("%d%d+%d%d=%d%d",a,b,c,d,e,f);
								return 0;
							}
						}
	printf("impossible");					
	return 0;
}