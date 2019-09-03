while True:
    n = int(input())
    if n==-1:
        break
    x = int(n**0.5)
    l = [1]
    for i in range(2, x+1):
        if n%i==0:
            l.extend([i, n//i])
    if sum(l)==n:
        print(n, '=', str(sorted(l)).strip('[, ]').replace(', ',' + '))
    else:
        print(n, "is NOT perfect.")