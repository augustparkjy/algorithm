import sys
n=int(input())
for _ in range(n):
    s=sys.stdin.readline().rstrip()
    v=0
    r=0
    for i in s:
        t=v*int(i=='O')
        v=t+int(i=='O')
        r+=v
    print(r)
    
# from sys import stdin
# for _ in range(int(stdin.readline())):
    # print(sum(sum(range(1,len(i)+1)) for i in stdin.readline().strip().split(sep='X')))
    
# import sys

# n = int(input())
# for i in range(n):
    # ans = sys.stdin.readline().rstrip()
    # res = 0
    # for j in ans.split('X'):
        # k = j.count('O')
        # res += k*(k+1)/2

    # print(int(res))