def solution(n, t, m, timetable):
    answer=''
    for i in range(len(timetable)):
        a, b = map(int, timetable[i].split(':'))
        timetable[i] = a*60+b
    timetable.sort()
    if(len(timetable)<m):
        hour=9+(n-1)*t//60%24
        minute=(n-1)*t%60
        answer= str(hour).rjust(2, '0')+':'+str(minute).rjust(2, '0')
        return answer
    for i in range(n-1):
        come=9*60 + t*i
        for p in timetable[:m]:
            if p<=come:
                timetable.remove(p)
    makcha= 9*60 + t*(n-1)
    
    print(makcha)
    if len(timetable)<m:
        x=makcha
    else:
        x=timetable[m-1]
        if x > makcha:
            x=makcha
        else:
            x-=1
        
    answer= str(x//60).rjust(2, '0')+':'+str(x%60).rjust(2, '0')    
    return answer
