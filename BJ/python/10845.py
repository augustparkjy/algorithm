import sys
# from collections import deque
input = sys.stdin.readline
n=int(input().strip())
# q = deque()
q=[]
cmd=[]
# for _ in range(n):
    # cmd = input().strip().split()
    # if len(cmd)>1:
        # q.insert(0, cmd[1])
    # elif cmd[0]=='pop':
        # print(q.pop()) if q else print(-1)
    # elif cmd[0]=='size':
        # print(len(q))
    # elif cmd[0]=='empty':
        # print(int(len(q)==0))
    # elif cmd[0]=='front':
        # print(q[-1]) if q else print(-1)
    # else:
        # print(q[0]) if q else print(-1)
        
        
for _ in range(n):
    cmd = input().strip().split()
    if len(cmd)>1:
        q.append(cmd[1]) #insert보다 낫다!?
    elif cmd[0]=='pop':
        print(q.pop(0)) if q else print(-1)
    elif cmd[0]=='size':
        print(len(q))
    elif cmd[0]=='empty':
        print(int(len(q)==0))
    elif cmd[0]=='front':
        print(q[0]) if q else print(-1)
    else:
        print(q[-1]) if q else print(-1)

# for _ in range(n):
    # cmd = input().strip().split()
    # if len(cmd)>1:
        # q.append(cmd[1]) #insert보다 낫다!?
    # elif cmd[0]=='pop':
        # print(q.popleft()) if q else print(-1)
    # elif cmd[0]=='size':
        # print(len(q))
    # elif cmd[0]=='empty':
        # print(int(len(q)==0))
    # elif cmd[0]=='front':
        # print(q[0]) if q else print(-1)
    # else:
        # print(q[-1]) if q else print(-1)