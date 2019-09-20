import sys
edge = [[] for _ in range(10001)]
Dvisit = [0 for _ in range(10001)]
Bvisit = [0 for _ in range(10001)]

n = int(input())

for _ in range(n):
    x, y = map(int, sys.stdin.readline().strip().split())
    edge[x].append(y)
    edge[y].append(x)

for e in edge:
    e.sort()
    
def dfs(v):
    s=''
    stack=[v]
    while stack:
        v1 = stack.pop()
        if not Dvisit[v1]:
            Dvisit[v1]=1
            s+= str(v1)+ ' '
            stack += edge[v1]
    return s

def bfs(v):
    s=''
    queue=[v]
    Bvisit[v]=1
    while queue:
        v1=queue.pop()
        s+=str(v1)+' '
        for i in edge[v1]:
            if not Bvisit[i]:
                Bvisit[i]=1
                queue = [i] + queue
    return s
    
# for i in range(10001):
    
print(dfs(1))
print(bfs(1))
        
            