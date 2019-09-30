import sys
edge = [[] for _ range(101)]
visit = [0 for _ range(101)]
input = sys.stdin.readline
for _ in range(int(input().strip())):
	x, y = map(int, input().strip().split())
    edge[x].append(y)
    edge[y].append(x)

def dfs(v):
    stack=[v]
    s=''
    while stack:
        v1 = stack.pop()
        if not visit[v1]:
            visit[v1]=1
            s+=str(v1)+' '
            stack+=edge[v1]
    return s
    
    
def bfs(v):
    queue=[v]
    s=''
    visit[v]=1
    while queue:
        v1=queue.pop()
        s=s+v1+' '
        for i in edge[v1]:
            if not visit[i]:
                visit[i]=1
                queue = [i]+queue
    
    return s
    
component=0
           
for i in range(1, 101):
    if edge[i] and check[i]==0:
        component+=1
        dfs(i)

print(component)
        