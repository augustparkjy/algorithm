n = int(input())
mem = [0 for _ in range(1000001)]
mem[1]=0
mem[2]=1
mem[3]=1
for i in range(4,n+1):
    mem[i] = mem[i-1]+1
    if i%3==0 and mem[i//3]+1 < mem[i]:
        mem[i] = mem[i//3]+1
    if i%2==0 and mem[i//2]+1 < mem[i]:
        mem[i] = mem[i//2]+1
    
print(mem[n])