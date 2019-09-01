a=int(input())
b=input()
for n in b[::-1]:
	print(a*int(n))
print(a*int(b))

# a,b=int(input()),input()
# print(*[a*int(p) for p in b][::-1],a*int(b))