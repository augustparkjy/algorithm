import sys
input = sys.stdin.readline
arr = [[0]*101 for _ in range(101)]
dx = [+1, 0, -1, 0]
dy = [0,-1, 0, +1]

for _ in range(int(input().strip())):
    x, y, d, g = map(int, input().strip().split())
    arr[y][x]=1
    y=y+dy[d]
    x=x+dx[d]
    arr[y][x]=1
    l=[d]
    for _ in range(g):
        k=len(l)
        for i in range(k-1,-1, -1):
            v=(l[i]+1)%4
            y=y+dy[v]
            x=x+dx[v]
            arr[y][x]=1
            l.append(v)

answer = 0
for i in range(100):
    for j in range(100):
        if arr[i][j]*arr[i][j+1]*arr[i+1][j]*arr[i+1][j+1]:
            answer+=1

print(answer)