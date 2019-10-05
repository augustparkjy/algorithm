import sys, collections, copy
input = sys.stdin.readline
r, c, k = map(int, input().strip().split())
A=[]

def R():
    global row
    global col
    
    for i, a in enumerate(A):
        tmp=collections.Counter(a)
        tmp2=[]
        for k, v in tmp.items():
            if k==0:
                continue
            tmp2.append((k,v))
        tmp2.sort(key=lambda elem:(elem[1], elem[0]))
        tmp3=[]
        for t in tmp2:
            tmp3.append(t[0])
            tmp3.append(t[1])
            if len(tmp3)>100:
                break
        A[i]=tmp3
    
    l=0
    for a in A:
        if len(a) > l:
            l=len(a)
    
    for a in A:
        if len(a)<l:
            for _ in range(l-len(a)):
                a.append(0)
    col = l
    row=len(A)
def C():
    global col
    global row
    global A
    T=[[] for i in range(len(A[0]))]
    for i in range(len(A[0])):
        for j in range(len(A)):
            T[i].append(A[j][i])
    A=copy.deepcopy(T)
    row, col = col, row
    R()
    
    T=[[] for i in range(col)]
    for i in range(col):
        for j in range(row):
            T[i].append(A[j][i])
    A=copy.deepcopy(T)
    row, col = col, row
    
for _ in range(3):
	A.append(list(map(int, input().strip().split())))
cnt=0
row=col=3

while True:
    if cnt>100:
        cnt=-1
        break
    if r-1<row and c-1<col and A[r-1][c-1]==k:
            break
            
    if row>=col:
        R()
    else:
        C()
    cnt+=1
    
print(cnt)