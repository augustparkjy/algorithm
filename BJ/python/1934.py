import sys
t = int(input())
def gcd(a,b):
    while b != 0:
        r=a%b
        a=b
        b=r
    return a
def lcm(a,b):
    G = gcd(a,b)
    return a*b//G
for _ in range(t):
    a,b = map(int, sys.stdin.readline().split())
    print(lcm(a,b))
