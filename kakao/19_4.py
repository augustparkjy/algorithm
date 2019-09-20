def solution(words, queries):
    answer = []
    for i in queries:
        cnt=0
        size = len(i)
        # pos=i.index('?')
        qnum=i.count('?')
        # tmp = i.replace('?','')
        for j in words:
            if len(j)!=size: #or tmp not in j:
                continue
            if i[0]!='?' and i[:size-qnum]==j[:size-qnum]:
                cnt+=1
            elif i[0]=='?' and i[qnum:]==j[qnum:]:
                cnt+=1
            # cnt+= i[:pos] == j[:pos] or i[qnum:]==j[qnum:]
            # if pos>0:
            #     j=j[:pos]
            # else:
            #     j=j[qnum:]
            # cnt+= int(tmp in j)
        answer.append(cnt)
        
    return answer