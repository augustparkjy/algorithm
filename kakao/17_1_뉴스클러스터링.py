import collections, string, copy
def solution(str1, str2):
    X=string.ascii_letters
    t=[]
    s1=[]
    s2=[]
    u=0
    n=0
    while len(str1)>1:
        t= str1[:2]
        str1=str1[1:]
        if t[0] not in X or t[1] not in X:
            continue
        s1.append(t.lower())
    while len(str2)>1:
        t= str2[:2]
        str2=str2[1:]
        if t[0] not in X or t[1] not in X:
            continue
        s2.append(t.lower())
    if len(s1)==0 and len(s2)==0:
        return 65536
    
    t1=collections.Counter(s1)
    t2=collections.Counter(s2)
    
    for i in t1.keys():
        if i in t2.keys():
            n+=min(t1[i], t2[i])
            u+=max(t1[i], t2[i])
        if i not in t2.keys():
            u+=t1[i]
            
    for i in t2.keys():
        if i not in t1.keys():
            u+=t2[i]
        
    return int(n/u*65536)