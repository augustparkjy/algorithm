import sys
for _ in range(int(input().strip())):
    y=k=0
    for _ in range(9):
        a, b = map(int, sys.stdin.readline().strip().split())
        y+=a
        k+=b
    print("Yonsei" if y>k else ("Korea" if k>y else "Draw"))