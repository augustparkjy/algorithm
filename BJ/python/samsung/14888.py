import sys, itertools
input = sys.stdin.readline
n=int(input().strip())
operand = list(map(int, input().strip().split()))
p, m, mul, d = map(int, input().strip().split())
max=-1000000000
min=1000000000
op=['+','-','*','//']
cmd=[]
for _ in range(p):
    cmd.append(0)
for _ in range(m):
    cmd.append(1)
for _ in range(mul):
    cmd.append(2)
for _ in range(d):
    cmd.append(3)
permuted_cmd = list(itertools.permutations(cmd))
permuted_cmd = list(set(permuted_cmd))
for p in permuted_cmd:# TIME COMPLEXITY
    tmp=operand[0]
    for i, j in enumerate(p):
        if j==0:
            tmp+=operand[i+1]
        elif j==1:
            tmp-=operand[i+1]
        elif j==2:
            tmp*=operand[i+1]
        else:
            if tmp<0:
                tmp=-1*(-1*tmp//operand[i+1])
            else:
                tmp//=operand[i+1]
    if tmp > max:
        max=tmp
    if tmp < min:
        min=tmp
        
print(max)
print(min)

# import sys, itertools
# input = sys.stdin.readline
# n=int(input().strip())
# operand = list(input().strip().split())
# p, m, mul, d = map(int, input().strip().split())
# max=-1000000000
# min=1000000000
# op=['+','-','*','//']
# cmd=[]
# for _ in range(p):
    # cmd.append(0)
# for _ in range(m):
    # cmd.append(1)
# for _ in range(mul):
    # cmd.append(2)
# for _ in range(d):
    # cmd.append(3)
# permuted_cmd = list(itertools.permutations(cmd))
# permuted_cmd = list(set(permuted_cmd))
# for p in permuted_cmd:# TIME COMPLEXITY
    # tmp=operand[0]
    # for i, j in enumerate(p):
        # if j<3 or int(tmp)>=0:
            # tmp=str(eval(tmp+op[j]+operand[i+1]))
        # else:
            # tmp=str(eval('-1*((-1*'+tmp+')//'+operand[i+1]+')'))
    # if int(tmp) > int(max):
        # max=tmp
    # if int(tmp) < int(min):
        # min=tmp
        
# print(max)
# print(min)