import sys, itertools
input = sys.stdin.readline
n = int(input().strip())
arr = [list(map(int, input().strip().split())) for _ in range(n)]
comb = list(itertools.combinations(range(n), n//2))
dp={}
answer = float('inf')
for i in range(n-1):
    for j in range(i+1, n):
        dp[(i,j)] = arr[i][j]+arr[j][i]

for i in range(len(comb)//2):
    tmp1 = comb[i]
    tmp2 = comb[-(1+i)]
    a=0
    b=0
    for t1, t2 in zip(list(itertools.combinations(tmp1, 2)), list(itertools.combinations(tmp2, 2))):
        a+=dp[t1]
        b+=dp[t2]
    answer = min(answer, abs(a-b))

print(answer)