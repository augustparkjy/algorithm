# t = int(input())
# for i in range(t):
	# print("Case #{}: {}".format(i+1, eval(input().replace(' ', '+'))))
    # print("Case #%d:"%(i+1), eval(input().replace(' ', '+')))
    
import sys
t=int(sys.stdin.readline())
for i in range(t):
    print("Case #%d:"%(i+1), eval(sys.stdin.readline().replace(' ', '+')))