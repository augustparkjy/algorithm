import sys
while True:
	a, b = map(int, sys.stdin.readline().split())
	if( a==b and a==0):
		break
	if a>b:
		print("Yes")
	else:
		print("No")
        
# import sys
# while 1:
    # a,b=map(int,sys.stdin.readline().split())
    # if a+b:print(["No","Yes"][a>b])
    # else:break