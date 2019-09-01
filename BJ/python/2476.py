import sys
n = int(input())
l=[]
for i in range(n):
    a,b,c = sorted(map(int, sys.stdin.readline().split()))
    l.append([c, 10+b, 100+10*b][[a, b, c].count(b)-1]*100)
print(max(l))