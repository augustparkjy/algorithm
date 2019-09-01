import sys
h, m = map(int, sys.stdin.readline().split())
l = int(input())
h += l//60
m += l%60
if m>=60:
	h+=1
	m %= 60
if h>=24:
	h %= 24
print(h, m)

# H,M=map(int,input().split())
# C=int(input())
# H=(H+(M+C)//60)%24
# M=(M+C)%60
# print(H,M)