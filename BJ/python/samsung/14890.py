import sys
input = sys.stdin.readline
n, l = map(int, input().strip().split())
arr = [list(map(int, input().strip().split())) for _ in range(n)]
def hor():
    answer=0
    visit = [[0]*n for i in range(n)]
    
    for y in range(n):
        for x in range(1, n):
            if arr[y][x-1]==arr[y][x]:
                if x==n-1:
                    answer+=1
                    break
            elif arr[y][x]-arr[y][x-1]==1:
                if x-l<0 or visit[y][x-l]==1:
                    break
                if x==n-1:
                    answer+=1
                    break
                for v in range(x-l, x):
                    visit[y][v]=1
            elif arr[y][x]-arr[y][x-1]==-1:
                if x+l-1>n-1:
                    break
                i=0
                for k in range(x+1, x+l):
                    if arr[y][k]!=arr[y][x]:
                        i=-1
                        break
                if i==-1:
                    break
                for v in range(x, x+l):
                    visit[y][v]=1
                x=x+l-1
                if x==n-1:
                    answer+=1
                    break
            else:
                break
    return answer
    
def ver():
    answer=0
    visit = [[0]*n for i in range(n)]
    
    for x in range(n):
        for y in range(1, n):
            if arr[y-1][x]==arr[y][x]:
                if y==n-1:
                    answer+=1
                    break
            elif arr[y][x]-arr[y-1][x]==1:
                if y-l<0 or visit[y-l][x]==1:
                    break
                if y==n-1:
                    answer+=1
                    break
                for v in range(y-l, y):
                    visit[v][x]=1
            elif arr[y][x]-arr[y-1][x]==-1:
                if y+l-1>n-1:
                    break
                i=0
                for k in range(y+1, y+l):
                    if arr[k][x]!=arr[y][x]:
                        i=-1
                        break
                if i==-1:
                    break
                for v in range(y, y+l):
                    visit[v][x]=1
                y=y+l-1
                if y==n-1:
                    answer+=1
                    break
            else:
                break
    return answer                

print(hor() + ver())