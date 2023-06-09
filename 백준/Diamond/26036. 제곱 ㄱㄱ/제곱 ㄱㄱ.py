n=int(input())
l=100**n
x=1
y=6
z=3
w=17
while x*x*8<l:
	t=y*6-x
	x=y
	y=t
	t=w*6-z
	z=w
	w=t
print(x,2)
print(z,1)