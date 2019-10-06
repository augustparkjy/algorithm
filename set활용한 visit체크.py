n,m = map(int, input().split())

a = [list(map(int, input().split())) for _ in range(n)]
dr = [-1,1,0,0]
dc = [0,0,-1,1]
U, D, L, R = 0,1,2,3
blank = 0
cctvs = []

def oob(a,b):
    if a<0 or b<0 or a>=n or b>=m: return True
    else: return False

def dfs(c,s):
    global cnt_max
    if c == len(cctvs):
        if len(s) > cnt_max:
            cnt_max = len(s)
        return
    for cctv in cctvs[c]:
        dfs(c+1,s|cctv) # 집합 OR연산

def fill(sr,sc,direction):
    s = set()
    for d in direction:
        nr,nc = sr,sc
        while True:
            nr += dr[d]
            nc += dc[d]
            if oob(nr,nc): break
            if a[nr][nc] == 6: break
            if a[nr][nc] == 0: s.add((nr,nc))
    return s

for r in range(n):
    for c in range(m):
        if a[r][c] == 1:
            cctvs.append([fill(r,c,[R]),fill(r,c,[L]),fill(r,c,[D]),fill(r,c,[U])])
        elif a[r][c] == 2:
            cctvs.append([fill(r, c, [U, D]), fill(r, c, [R, L])])
        elif a[r][c] == 3:
            cctvs.append([fill(r, c, [U, R]), fill(r, c, [R, D]), fill(r, c, [D, L]), fill(r, c, [L, U])])
        elif a[r][c] == 4:
            cctvs.append([fill(r, c, [U, R, D]), fill(r, c, [R, D, L]), fill(r, c, [D, L, U]), fill(r, c, [L, U, R])])
        elif a[r][c] == 5:
            cctvs.append([fill(r, c, [U, D, R, L])])
        elif a[r][c] == 0:
            blank += 1

cnt_max = 0
dfs(0,set())
print(blank - cnt_max)