import sys
input = sys.stdin.readline
l=[]
for _ in range(int(input().strip())):
    x = input().strip()
    digit=None
    for i in x:
        if i.isdigit():
            if digit==None:
                digit=0
            digit=digit*10+int(i)
        elif digit != None:
            l.append(digit)
            digit=None
    if digit != None:
        l.append(digit)
        
for i in sorted(l):
    print(i)