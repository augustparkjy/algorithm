import collections

def solution(cacheSize, cities):
    answer=0
    q=collections.deque(maxlen=cacheSize)
    for i in cities:
        if i.lower() not in q:
            q.append(i.lower())
            answer+=5
        else:
            q.remove((i.lower()))
            q.append(i.lower())
            answer+=1
    return answer