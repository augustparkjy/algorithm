import sys
n, m, v = map(int, sys.stdin.readline().split())
edge = [[] for _ in range(n+1)]

for _ in range(m):
    n1, n2 = map(int, sys.stdin.readline().split())
    edge[n1].append(n2)
    edge[n2].append(n1)
    
for e in edge:
    e.sort(reverse=True)
   
def dfs():
    Dvisit = []
    stack = [v]
    Dcheck = [0 for _ in range(n+1)]
    while stack:
        v1 = stack.pop()
        if not Dcheck[v1]:
            Dcheck[v1]=1
            Dvisit.append(v1)
            stack += edge[v1]
    return Dvisit

def bfs():
    Bvisit = []
    queue = [v]
    Bcheck = [0 for _ in range(n+1)]
    Bcheck[v] = 1
    while queue:
        v2 = queue.pop()
        Bvisit.append(v2)
        for i in reversed(edge[v2]):
            if not Bcheck[i]:
                Bcheck[i]=1
                queue = [i] + queue
    return Bvisit
    
print(' '.join(map(str, dfs())))
print(' '.join(map(str, bfs())))