import sys
s = list(map(int, sys.stdin.readline().split()))
s.pop(s.index(max(s)))
print(max(s))
# import sys
# print(sorted(sys.stdin.readline().split(), key=int)[1])
