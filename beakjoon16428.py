a,b = map(int,input().split())
mok = a//b
left = a%b
if b<0 and left<0:
	mok+=1
	left = -b+left
print(mok)
print(left)