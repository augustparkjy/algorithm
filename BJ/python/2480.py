import sys
a, b, c = map(int, sys.stdin.readline().split())
m= int(a==b)*10 + int(b==c)
if m==11:
	print(10000+a*1000)
elif m==1:
	print(1000+b*100)
elif m>=10:
	print(1000+b*100)
else:
	print(max(a,b,c)*100)
    
# a,b,c=sorted(map(int,input().split()))
# print([c,b+10,b*10+100][[a,b,c].count(b)-1]*100)