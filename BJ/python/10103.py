import sys
l=[100, 100]
x=[]
for _ in range(int(input())):
    x = list(map(int, sys.stdin.readline().split()))
    if x[0]==x[1]:
        continue
    l[x[0]>x[1]] -= x[x[0]<x[1]]
print(str(l[0])+'\n'+str(l[1]))

# A=100
# B=A
# for n in range(int(input())):
    # a,b=map(int,input().split())
    # A-=max(a,b)*(a<b)
    # B-=max(a,b)*(a>b)
# print(A)
# print(B)