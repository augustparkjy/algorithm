# import sys
# input = sys.stdin.readline
# n=int(input().strip())
# list=[[] for i in range(51)]
# def second(s):
    # hap=0
    # for i in s:
        # if i.isdigit():
            # hap+=int(i)
    # return hap

# def third(s):
    # l=[]
    # l.extend(s)
    # return l
        
# for _ in range(n):
    # s = input().strip()
    # list[len(s)].append(s)

# for l in list:
    # if not l:
        # continue
    # l.sort(key= lambda s: (second(s), third(s)))
    # for i in l:
        # print(i)


import sys

def digit_sum(s):
    return sum(int(i) for i in s if i.isdigit())
    
input = sys.stdin.readline
n=int(input().strip())
l=[]

for _ in range(n):
    l.append(input().strip())
    
l.sort()
l.sort(key=digit_sum)
l.sort(key=len)
for s in l:
    print(s)