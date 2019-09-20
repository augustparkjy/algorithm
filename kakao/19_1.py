def solution(s):
    answer = len(s)
    for i in range(1, len(s)+1):
        tmp = s
        c=''
        for _ in range(len(tmp)):
            l=0
            comp = tmp[:i]
            for __ in range(len(tmp)):
                t=tmp[:i]
                if t==comp:
                    l+=1
                    tmp=tmp[i:]
                else:
                    break
            if l<=1:
                c+=comp
            else:
                c+=str(l)+comp
        if len(c)<answer:
            answer = len(c)
        
    return answer