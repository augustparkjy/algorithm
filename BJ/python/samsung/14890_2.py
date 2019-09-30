import sys
input = sys.stdin.readline
n, l = map(int, input().strip().split())
arr = [list(map(int, input().strip().split())) for _ in range(n)]
for y in range(n):
    tmp=[]
    for x in range(n):
        tmp.append(arr[x][y])
    arr.append(tmp)

answer=0
for y in range(n*2):
    valid=1
    for x in range(n-1):
        if arr[y][x]==arr[y][x+1]:
            valid+=1
        elif arr[y][x]+1 == arr[y][x+1] and valid>=l: #오르막
            valid=1
        elif arr[y][x]-1 == arr[y][x+1] and valid>=0: #내리막
            valid=1-l
        else:
            valid=-1
            break
    if valid>=0:
        answer+=1

print(answer)