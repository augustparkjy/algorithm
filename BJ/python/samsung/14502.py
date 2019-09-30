import sys, itertools
input=sys.stdin.readline
n, m = map(int, input().strip().split())
mm=[list(map(int, input().strip().split())) for _ in range(n)]
answer=0
zero = []
virus=[]
noz=0

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def f(z):
    NZ=noz-3
    visit=[[0]*m for _ in range(n)]
    visit[z[0][0]][z[0][1]]=1
    visit[z[1][0]][z[1][1]]=1
    visit[z[2][0]][z[2][1]]=1
    
    for v in virus:
        stack=[v]
        if NZ == 0:
            return 0
        while stack:
            v1=stack.pop()
            y=v1[0]
            x=v1[1]
            visit[y][x]=1
            for i in range(4):
                if not (x+dx[i]<0 or x+dx[i]>m-1 or y+dy[i]<0 or y+dy[i]>n-1):
                    if mm[y+dy[i]][x+dx[i]]==0 and visit[y+dy[i]][x+dx[i]]==0:
                        stack.append([y+dy[i],x+dx[i]])
                        visit[y+dy[i]][x+dx[i]]=1
                        NZ-=1
    return NZ
    
    
    
for i in range(n):
    for j in range(m):
        if mm[i][j]==0:
            zero.append([i,j])
        elif mm[i][j]==2:
            virus.append([i,j])
noz=len(zero)
zero = list(itertools.combinations(zero, 3))

for z in zero:
    answer = max(f(z), answer)

print(answer)
