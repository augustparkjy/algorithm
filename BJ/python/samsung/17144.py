import sys
input = sys.stdin.readline
air=[]
rl=[0, 1, 0, -1]
ud=[-1, 0, 1, 0]

r, c, t = map(int, input().strip().split())
mm=[[], [[0]*c for i in range(r)]]

def spread(cur):
    next = (cur+1)%2
    for y in range(r):
        for x in range(c):
            if mm[cur][y][x] !=-1 :
                cnt=0
                val=mm[cur][y][x]//5
                for i in range(4):
                    nx = x+rl[i]
                    ny = y+ud[i]
                    if not (nx<0 or nx>=c or ny<0 or ny>=r or mm[next][ny][nx]==-1):
                        cnt+=1
                        mm[next][ny][nx]+=val
                mm[next][y][x] += (mm[cur][y][x]-val*cnt)
            else:
                mm[next][y][x]= -1
            mm[cur][y][x]=0

def move(cur):
    y1=air[0]
    y2=air[1]
    mm[cur][y1-1][0]=0
    for i in range(y1-2, -1, -1):
        mm[cur][i+1][0]=mm[cur][i][0]
    for i in range(1, c):
        mm[cur][0][i-1]=mm[cur][0][i]
    for i in range(1, y1+1):
        mm[cur][i-1][c-1]=mm[cur][i][c-1]
    for i in range(c-2, 0,-1):
        mm[cur][y1][i+1] = mm[cur][y1][i]
    mm[cur][y1][1]=0
    
    mm[cur][y2+1][0]=0
    for i in range(y2+2, r):
        mm[cur][i-1][0]=mm[cur][i][0]
    for i in range(1, c):
        mm[cur][r-1][i-1]=mm[cur][r-1][i]
    for i in range(r-2, y2-1, -1):
        mm[cur][i+1][c-1]=mm[cur][i][c-1]
    for i in range(c-2, 0, -1):
        mm[cur][y2][i+1]=mm[cur][y2][i]
    mm[cur][y2][1]=0
    
for i in range(r):
    mm[0].append(list(map(int, input().strip().split())))
    if -1 in mm[0][i] and not air:
        air.append(i)
        air.append(i+1)

for cur in range(t):
    spread(cur%2)
    move((cur+1)%2)

val=0
for m in mm[t%2]:
    val += sum(m)
print(val+2)
