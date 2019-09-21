import sys
input = sys.stdin.readline
n = int(input().strip())
d = []
cmd = []
for _ in range(n):
    cmd = input().strip().split()
    if len(cmd)>1:
        if len(cmd[0])==9:
            d.append(cmd[1])
        else:
            d.insert(0, cmd[1])
    elif cmd[0]=='pop_front':
        print(d.pop(0)) if d else print(-1)
    elif cmd[0]=='pop_back':
        print(d.pop()) if d else print(-1)
    elif cmd[0]=='size':
        print(len(d))
    elif cmd[0]=='empty':
        print(int(len(d)==0))
    elif cmd[0]=='front':
        print(d[0]) if d else print(-1)
    else:
        print(d[-1]) if d else print(-1)
        
# import sys
# from collections import deque
# input = sys.stdin.readline
# n = int(sys.stdin.readline().strip())
# d = deque()
# cmd = []
# for _ in range(n):
    # cmd = sys.stdin.readline().strip().split()
    # if len(cmd)>1:
        # if len(cmd[0])==9:
            # d.append(cmd[1])
        # else:
            # d.appendleft(cmd[1])
    # elif cmd[0]=='pop_front':
        # print(d.popleft()) if d else print(-1)
    # elif cmd[0]=='pop_back':
        # print(d.pop()) if d else print(-1)
    # elif cmd[0]=='size':
        # print(len(d))
    # elif cmd[0]=='empty':
        # print(int(len(d)==0))
    # elif cmd[0]=='front':
        # print(d[0]) if d else print(-1)
    # else:
        # print(d[-1]) if d else print(-1)