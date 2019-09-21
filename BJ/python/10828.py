import sys
input = sys.stdin.readline
n= int(input().strip())
cmd=[]
stack =[]
for _ in range(n):
    cmd = input().strip().split()
    if len(cmd)>1:
        stack.append(cmd[1])
    elif cmd[0]=='top':
        print(stack[-1]) if stack else print(-1)
    elif cmd[0]=='size':
        print(len(stack))
    elif cmd[0]=='pop':
        print(stack.pop()) if stack else print(-1)
    else:
        print(int(len(stack)==0))