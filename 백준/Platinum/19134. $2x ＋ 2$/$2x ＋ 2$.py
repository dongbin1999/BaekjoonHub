n=int(input())
ans=0
while n>0:
	x=max(1,n//2)
	ans+=n-x+1
	n=(x+1)//2-2
print(ans)