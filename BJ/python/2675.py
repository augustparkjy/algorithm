import sys
for _ in range(int(input())):
    n, l = sys.stdin.readline().split()
    answer=[]
    n=int(n)
    for i in range(len(l)):
        answer.extend(l[i]*n)
    print("".join(answer))
    
# t=int(input())
# for i in range(t):
 # a,b=input().split()
 # for j in b:
  # print(int(a)*j, end='')
 # print()