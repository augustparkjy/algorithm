n = int(input())
s = input()
a=s.count('A')
b=s.count('B')
if a==b:
    print('Tie')
else:
    print(['A','B'][a<b])
    
# n=int(input())
# t=input().count('A')
# print('B' if n-t>t else ('Tie' if n-t==t else 'A'))
