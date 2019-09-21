import sys
input = sys.stdin.readline
s = input().strip()
stack=[]
op = {'+':2, '-':2, '*':1, '/':1, '(':3, ')':4}
answer=''
for w in s:
    if not w in op:
        answer+=w
    elif w=='(':
        stack.append(w)
    elif w==')':
        while True:
            l=stack.pop()
            if l=='(':
                break
            answer+=l
    elif not stack:
        stack.append(w)
    else:
        if op[w] < op[stack[-1]]:
            stack.append(w)
        else:
            while True and stack:
                l=stack[-1]
                if op[l]<=op[w]:
                    answer+=stack.pop()
                else:
                    break
            stack.append(w)
while len(stack)>0:
    answer+=stack.pop()
print(answer)