import sys
l=[list(map(int, sys.stdin.readline().split())) for i in range(3)]
x1, x2, x3=sorted([x[0] for x in l])
y1, y2, y3=sorted([y[1] for y in l])
x=[x3, x1][x2>x1]
y=[y3, y1][y2>y1]
print(x, y)

# import sys
# input = sys.stdin.readline

# x = []
# y = []
# for i in range(3):
    # a, b = map(int, input().split())
    # if a in x:
        # x.remove(a)
    # else:
        # x.append(a)
    # if b in y:
        # y.remove(b)
    # else:
        # y.append(b)
    
# print(x[0], y[0])

#bitwise(XOR)
# x=0;y=0
# for _ in range(3):a,b=map(int,input().split());x^=a;y^=b
# print(x,y)