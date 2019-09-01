n=0
for i in range(5):
    x=int(input())
    if x<40:
        n+=40
    else:
        n+=x
print(n//5)

# print(eval("("+"+max(int(input()),40)"*5+")//5"))