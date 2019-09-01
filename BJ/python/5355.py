import sys
t = int(input())
for i in range(t):
    l=[*(sys.stdin.readline().split())]
    n=float(l.pop(0))
    for op in l:
        if op=='@':
            n*=3
        elif op=='%':
            n+=5
        else:
            n-=7
    print('%.2f' %n)
    
# for _ in range(int(input())):
# n, *arr = input().split()
# n = float(n)

# for c in arr:
    # if c == '@': n *= 3
    # elif c == '%': n += 5
    # else: n -= 7

# print("%.2f" % n)