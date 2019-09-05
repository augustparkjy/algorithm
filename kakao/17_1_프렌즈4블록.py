def func(mtx, a, b, c, visit):
    if mtx[a][b]=='0' or visit[a][b]==1:
        return
    visit[a][b]=1
    l=[mtx[a][b], mtx[a][b+1], mtx[a+1][b], mtx[a+1][b+1]]
    for _ in l:
        if _ not in ['*', c]:
            return
    mtx[a]=mtx[a][:b]+'**'+mtx[a][b+2:]
    mtx[a+1]=mtx[a+1][:b]+'**'+mtx[a+1][b+2:]
    al=[-1,-1,-1,0,1,1,1,0]
    bl=[-1,0,1,1,1,0,-1,-1]
    for i, j in zip(al, bl):
        func(mtx, a+i, b+j, c, visit)
    
def solution(m, n, board):
    mtx = ["0"*(m+2)]
    answer=0
    for i in range(n):
        t="0"
        for j in range(m-1, -1, -1):
            t+=board[j][i]
        t+="0"
        mtx.append(t)
    mtx.append("0"*(m+2))
    run=1
    while run==1:
        run=0
        for p in range(1,n+1):
            for q in range(1,m+1):
                if mtx[p][q]=='0':
                    break
                if mtx[p][q]==mtx[p][q+1] and mtx[p][q]==mtx[p+1][q] and mtx[p][q+1]==mtx[p+1][q+1]:
                    visit = [[0 for i in range(m+2)] for j in range(n+2)]
                    c=mtx[p][q]
                    func(mtx, p, q, c, visit)
                    for i in range(len(mtx)):
                        mtx[i]=mtx[i].replace('*', '').ljust(m+2, '0')
                    run=1
                    
    answer = (m+2)*(n+2)
    for i in mtx:
        answer -= i.count('0')
    answer = (m*n) - answer
    return answer