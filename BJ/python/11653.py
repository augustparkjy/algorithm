n=int(input())
q=2
l=[]
while n>1:
    if n%q==0:
        l.append(q)
        n//=q
        print(q)
    else:
        q+=1
        
# import sys
# N = int(sys.stdin.readline().rstrip())

# for i in range(2, int(N ** 0.5) + 1):
    # while N % i == 0:
        # print(i)
        # N //= i

# if N > 1:
    # print(N)
