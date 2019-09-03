import sys
for _ in range(int(input())):
	l=[]
	for _ in range(int(input())):
		s, c = sys.stdin.readline().split()
		l.extend([s, int(c)])
	t=l[1::2]
	print(l[l.index(max(t))-1])	