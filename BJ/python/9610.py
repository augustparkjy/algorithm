import sys
n=int(input())
Q=['Q1', 'Q2', 'Q3', 'Q4', 'AXIS']
for _ in range(n):
	a,b = map(int, sys.stdin.readline().split())
	if a==0 or b==0:
		Q.append('AXIS')
	elif a>0 and b>0:
		Q.append('Q1')
	elif a>0 and b<0:
		Q.append('Q4')
	elif a<0 and b<0:
		Q.append('Q3')
	else:
		Q.append('Q2')
for i in range(5):
	print(Q[i]+':', Q.count(Q[i])-1)