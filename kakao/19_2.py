def one(p):
    if len(p)==0:
        return ''
    else:
        return two(p)
def two(p):
    l=r=0
    tmp=''
    for i in p:
        if i=='(':
            l+=1
        else:
            r+=1
        tmp+=i
        if l==r:
            return three(p[:(len(tmp))], p[(len(tmp)):])
def three(u, v):
    s=""
    tmp=u
    print(tmp)
    while ('()' in tmp):
        tmp=tmp.replace('()', '')
    if len(tmp)==0:
        return u+one(v)
    else:
        s='('+one(v)+')'
        u = u[1:len(u)-1]
        for i in range(len(u)):
            if u[i] == '(':
                s+=')'
            else:
                s+='('
        return s
    
def solution(p):
    answer = one(p)
    return answer