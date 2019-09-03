import sys
for i in range(int(input())):
	a, b, c = map(int, sys.stdin.readline().split())
	if a > b-c :
		print("do not advertise")
	elif a==b-c:
		print("does not matter")
	else:
		print("advertise")