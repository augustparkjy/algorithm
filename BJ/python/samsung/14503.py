import sys
input = sys.stdin.readline
n, m = map(int, input().strip().split())
y, x, d = map(int, input().strip().split())
arr=[list(map(int, input().strip().split())) for _ in range(n)]
dx=[0, 1, 0, -1]
dy=[-1, 0, 1, 0]
visit=[[0]*m for _ in range(n)]
answer=0
check=0
while True:
    if visit[y][x]==0:
        visit[y][x]=1
        answer+=1
    nd=(d+3)%4
    ny, nx = y+dy[nd], x+dx[nd]

    if arr[ny][nx]==0 and visit[ny][nx]==0:
        y, x, d = ny, nx, nd
        continue
    td=(d+6)%4
    
    for _ in range(3):
        ty, tx = y+dy[td],x+dx[td]
        if arr[ty][tx]==0 and visit[ty][tx]==0:
            check=1
            break
        td=(td+3)%4
        
    if check==1:
        y, x, d = ty, tx, td
        check=0
        continue
    if arr[y+dy[(d+6)%4]][x+dx[(d+6)%4]]==0:
        y, x = y+dy[(d+6)%4], x+dx[(d+6)%4]
        continue
    else:
        break
print(answer)