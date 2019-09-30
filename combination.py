###조합구현
n=6
c=[0]*n

def comb(cnt, cnt_size):
    if cnt_size==n//2:
        print(c)
        return
    for i in range(cnt, n):
        c[i]=1
        comb(i+1, cnt_size+1)
        c[i]=0
        
comb(0, 0)