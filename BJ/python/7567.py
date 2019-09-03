s=input()
a=0
for i in range(len(s)-1):
    if s[i+1]==s[i]:
        a+=5
    else:
        a+=10
print(a+10)

# d=r=0
# for _ in input():r+=[5,10][_!=d];d=_
# print(r)