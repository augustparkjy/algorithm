# import sys
# input = sys.stdin.readline
# x=[0 for i in range(11)]
# x[1]=1
# x[2]=2
# x[3]=4
# def f(n):
    # if n<1:
        # return 0
    # if x[n]==0:
        # x[n] = f(n-1)+f(n-2)+f(n-3)
    # return x[n]
    
# for _ in range(int(input().strip())):
    # s=int(input().strip())
    # print(f(s))

import sys
input = sys.stdin.readline
x=[1,2,4]
for i in range(3, 11):
    x.append(sum(x[-3:]))
for _ in range(int(input().strip())):
    print(x[int(input().strip())-1])