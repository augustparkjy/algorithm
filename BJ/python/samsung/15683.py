import sys, copy
input = sys.stdin. readline
N, M = map(int, input().strip().split())
arr = [list(map(int, input().strip().split())) for _ in range(N)]
cctv = []
answer=N*M
nocnt=0
for i in range(N):
    for j in range(M):
        if arr[i][j]!=0:
            nocnt+=1
            if arr[i][j]!=6:
                cctv.append((arr[i][j], i, j))
answer-=nocnt

def detect(dir, y, x, visit):
    tmp=0
    #east
    if dir==0:
        for i in range(x+1, M):
            if arr[y][i]!=6:
                if arr[y][i]==0 and visit[y][i]==0:
                    tmp+=1
                    visit[y][i]=1
            else:
                return tmp
        return tmp
    #south
    elif dir==1:
        for i in range(y+1, N):
            if arr[i][x]!=6:
                if arr[i][x]==0 and visit[i][x]==0:
                    tmp+=1
                    visit[i][x]=1
            else:
                return tmp
        return tmp
    #west
    elif dir==2:
        for i in range(x-1, -1, -1):
            if arr[y][i]!=6:
                if arr[y][i]==0 and visit[y][i]==0:
                    tmp+=1
                    visit[y][i]=1
            else:
                return tmp
        return tmp
    #north
    else:
        for i in range(y-1, -1, -1):
            if arr[i][x]!=6:
                if arr[i][x]==0 and visit[i][x]==0:
                    tmp+=1
                    visit[i][x]=1
            else:
                return tmp
        return tmp
				
def rotate(count, res, visit):
    global answer
    if answer==0:
        return
    if count == len(cctv):
        if res < answer:
            answer=res
        return
    type, y, x = cctv[count][0], cctv[count][1], cctv[count][2]
    
    if type==1:
        for i in range(4):
            visit2=copy.deepcopy(visit)
            tmp=detect(i, y, x, visit2)
            rotate(count+1, res-tmp, visit2)
    elif type==2:
        for i in range(2):
            visit2=copy.deepcopy(visit)
            tmp=detect(i, y, x, visit2)+detect(i+2, y, x, visit2)
            rotate(count+1, res-tmp, visit2)
    elif type==3:
        for i in range(4):
            visit2=copy.deepcopy(visit)
            tmp=detect(i, y, x, visit2)+detect((i+1)%4, y, x, visit2)
            rotate(count+1, res-tmp, visit2)
    elif type==4:
        for i in range(4):
            visit2=copy.deepcopy(visit)
            tmp=detect(i, y, x, visit2)+detect((i+1)%4, y, x, visit2)+detect((i+2)%4, y, x, visit2)
            rotate(count+1, res-tmp, visit2)
    else:
        visit2=copy.deepcopy(visit)
        tmp=detect(0, y, x, visit2)+detect(1, y, x, visit2)+detect(2, y, x, visit2)+detect(3, y, x, visit2)
        rotate(count+1, res-tmp, visit2)
        
rotate(0, answer, [[0]*M for _ in range(N)])
print(answer) 