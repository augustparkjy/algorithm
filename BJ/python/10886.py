n=int(input())
l=[]
for _ in range(n):
	l.extend(input())
print(["Junhee is cute!", "Junhee is not cute!"][l.count('0')>l.count('1')])
# print("Junhee is cute!" if l.count('1')>l.count('0') else "Junhee is not cute!")
# t=n=int(input())
# for _ in range(n):
    # n-=int(input())
# print("Junhee is cute!" if t//2>=n else "Junhee is not cute!")  

# n=int(input());k=0
# for i in'a'*n:k+=int(input())
# print('Junhee is '+'not '*(n//2>=k)+'cute!')