import sys
input = sys.stdin.readline
n=int(input().strip())
operand = list(map(int, input().strip().split()))
max=float('-inf')
min=float('inf')
op=[0, 0, 0, 0]
for i, j in enumerate(list(map(int, input().strip().split()))):
    op[i]+=j
def dfs(result, count):
    if count == n-1:
        global max
        global min
        if result>max:
            max=result
        if result<min:
            min=result
        return
    
    for i in range(4):
        if op[i]!=0:
            op[i]-=1
            if i==0:
                dfs(result+operand[count+1], count+1)
            elif i==1:
                dfs(result-operand[count+1], count+1)
            elif i==2:
                dfs(result*operand[count+1], count+1)
            else:
                if result<0:
                    dfs(-1*(-1*result//operand[count+1]), count+1)
                else:
                    dfs(result//operand[count+1], count+1)
            op[i]+=1
        
dfs(operand[0], 0)
print(max)
print(min)