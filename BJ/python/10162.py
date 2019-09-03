n=int(input())
l=[300, 60, 10]
for i in range(3):
	l.extend([l[i]]*(n//l[i]))
	n%=l[i]
print(-1) if n>0 else print(l.count(300)-1, l.count(60)-1, l.count(10)-1)