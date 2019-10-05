import sys
input = sys.stdin.readline
N, M, y, x, k = map(int, input().strip().split())
arr = []
#전, 후, 좌, 위, 우, 아래
dice=[0, 0, 0, 0, 0, 0]
dx=[1, -1, 0, 0]
dy=[0, 0, -1, 1]
def roll(dir):
    if dir == 1:
        # 좌 위 우 아래 << 아래 좌 위 우
        dice[2], dice[3], dice[4], dice[5] = dice[5], dice[2], dice[3], dice[4]
        return
    elif dir == 2:
        #좌 위 우 아래 << 아래 좌 위 우
        dice[2], dice[3], dice[4], dice[5] = dice[3], dice[4], dice[5], dice[2]
        return
    elif dir == 3:
        #전, 후, 위, 아래 << 아래 위 전 후
        dice[0], dice[1], dice[3], dice[5] = dice[5], dice[3], dice[0], dice[1]
        return
    else:
        #전, 후, 위, 아래 << 위 아래 후 전
        dice[0], dice[1], dice[3], dice[5] = dice[3], dice[5], dice[1], dice[0]
        
for i in range(N):
	arr.append(list(map(int, input().strip().split())))

cmd_list = map(int, input().strip().split())

for cmd in cmd_list:
    ny = y +dy[cmd-1]
    nx = x +dx[cmd-1]
    if ny < 0 or ny>N-1 or nx<0 or nx>M-1:
        continue
    if arr[y][x]==0:
        arr[y][x] = dice[5]
    else:
        arr[y][x], dice[5] = 0, arr[y][x]
    roll(cmd)
    print(dice[3])
    y=ny
    x=nx


# from sys import stdin

input
# input = stdin.readline
# N, M, x, y, K = list(map(int, input().split()))
# maparr = [list(map(int, input().split())) for _ in range(N)]
# dirarr = list(map(int, input().split()))

# direction = [
    # (2, 1, 5, 0, 4, 3), # east
    # (3, 1, 0, 5, 4, 2), # west
    # (4, 0, 2, 3, 5, 1), # north
    # (1, 5, 2, 3, 0, 4) # south
# ]

동 서 북 남
# dx = [0, 0, -1, 1]
# dy = [1, -1, 0, 0]

# dice = [0]*6

# for dir in dirarr:
    # dir -= 1
    # if not 0 <= x + dx[dir] < N or not 0 <= y + dy[dir] < M:
        # continue
    # x, y = x + dx[dir], y + dy[dir]
    # temp = dice[:]

    # for idx in range(6):
        # dice[idx] = temp[direction[dir][idx]]

    # if maparr[x][y] == 0:
        # maparr[x][y] = dice[5]
    # else:
        # dice[5] = maparr[x][y]
        # maparr[x][y] = 0

    # print(dice[0])