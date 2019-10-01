import sys
input = sys.stdin.readline
arr=[[],[],[],[]]
for i in range(4):
    s=input().strip()
    for j in range(len(s)):
        arr[i].append(int(s[j]))
t = int(input().strip())
def rotate(l, r, d):
    if(l<r):
        if r>3:
            return
        if d>0 and arr[l][3]!=arr[r][-2]:
            arr[r] = arr[r][1:8]+[arr[r][0]]
        elif d<0 and arr[l][1]!=arr[r][-2]:
            arr[r] = [arr[r][7]]+arr[r][0:7]
        else:
            return
        rotate(l+1, r+1, d*-1)
    else:
        if r<0:
            return
        if d>0 and arr[l][-1]!=arr[r][2]:
            arr[r] = arr[r][1:8]+[arr[r][0]]
        elif d<0 and arr[l][-3]!=arr[r][2]:
            arr[r] = [arr[r][7]]+arr[r][0:7]
        else:
            return
        rotate(l-1, r-1, d*-1)

for _ in range(t):
    opt, dir = map(int, input().strip().split())
    opt-=1
    if dir>0:
        arr[opt] = [arr[opt][7]]+arr[opt][0:7]
    else:
        arr[opt] = arr[opt][1:8]+[arr[opt][0]]
    rotate(opt, opt-1, dir)
    rotate(opt, opt+1, dir)

answer = 0
for i in range(4):
    answer+=arr[i][0]*(2**i)

print(answer)