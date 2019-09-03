import sys
a=eval(sys.stdin.readline().replace(' ', '*60+'))-45
if a<0:
    a+=1440
print(a//60, a%60)

# a,b=map(int,input().split())
# c=a*60+b-45
# print(c//60%24,c%60)