import sys
a, b, c = map(int, sys.stdin.readline().split())
s = int(input())
print((a+(b+(c+s)//60)//60)%24,(b+(c+s)//60)%60,(c+s)%60)