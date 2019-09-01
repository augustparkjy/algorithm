import sys
a, b, c = map(int, sys.stdin.readline().split())
print([0, a*b-c][a*b>=c])

# k,n,m=map(int,input().split())
# print(max(0,k*n-m))