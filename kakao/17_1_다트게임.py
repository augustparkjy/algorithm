def solution(dartResult):
    op1={'S':'**1', 'D':'**2', 'T':'**3'}
    op2={'*':'*2', '#':'*(-1)'}
    last=-1
    answer=[]
    s=""
    for i in dartResult:
        if i.isdigit():
            s+=i
        elif i.isalpha():
            s+=op1[i]
            answer.append(s)
            s=""
            last+=1
        else:
            answer[last]+=op2[i]
            if last>0 and i=='*':
                answer[last-1]+=op2[i]
    return eval("+".join(answer).strip('[, ]'))