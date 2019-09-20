def solution(record):
    log = {}
    answer =[]
    for r in record:
        tmp = r.split()
        if len(tmp)!=3:
            continue
        log[tmp[1]]=tmp[2]
        
    for r in record:
        tmp=r.split()
        s=log[tmp[1]]
        if tmp[0]=='Enter':
            s+="님이 들어왔습니다."
        elif tmp[0]=='Leave':
            s+="님이 나갔습니다."
        else:
            continue
        answer.append(s)
    
    return answer
    
    
    # def solution(record):
    # answer = []
    # namespace = {}
    # printer = {'Enter':'님이 들어왔습니다.', 'Leave':'님이 나갔습니다.'}
    # for r in record:
        # rr = r.split(' ')
        # if rr[0] in ['Enter', 'Change']:
            # namespace[rr[1]] = rr[2]

    # for r in record:
        # if r.split(' ')[0] != 'Change':
            # answer.append(namespace[r.split(' ')[1]] + printer[r.split(' ')[0]])

    # return answer