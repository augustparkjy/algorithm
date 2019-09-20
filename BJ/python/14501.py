import sys
n = int(sys.stdin.readline().strip())
t= [0]
p= [0]
dp = [0 for i in range(n+2)]
answer = 0
for i in range(n):
    a, b = map(int, sys.stdin.readline().strip().split())
    t.append(a)
    p.append(b)
    
for i in range(1, n+2):
    for j in range(1, i):
        # dp[i] = max(dp[i], dp[j])
        if j+t[j]!=i:
            dp[i] = max(dp[i], dp[j])
        else:
            dp[i]=max(dp[j]+p[j],dp[i])
    
    answer = max(answer, dp[i])
print(answer)

# import sys
# input= sys.stdin.readline

# n = int(input().strip())
# dp = [0 for _ in range(n+2)]
# tp = [list(map(int,input().strip().split())) for _ in range(n)]
# for i,v in enumerate(tp):
    # i = i+1
    # time,pay = v
    # dp[i] = max(max(dp[:i]),dp[i])
    # if i+time < n+2:
        # dp[i+time] = max(dp[i+time],dp[i]+pay)
# print(max(dp[n],dp[n+1]))