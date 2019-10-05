def transpose():
    global mat
    mat = list(map(list, zip(*mat)))

def c_cal():
    transpose()
    r_cal()
    transpose()

def r_cal():
    global mat
    max_row = 0
    for i in range(len(mat)):
        cnt_dic = {}
        row = mat[i]
        for j in row:
            if j !=0:
                cnt_dic[j] = cnt_dic.get(j, 0) + 1
        sorted_cnt = sorted(cnt_dic.items(), key=lambda t: (t[1], t[0]))
        sorted_row = [sc[idx] for sc in sorted_cnt for idx in range(2)][:100]  # 100미만으로 자른다.
        mat[i] = sorted_row
        max_row=max(max_row,len(mat[i]))
    mat = [list(mat[_] + [0] * (max_row - len(mat[_]))) for _ in range(len(mat))]

r, c, k = map(int, input().split())
mat = [list(map(int, input().split())) for _ in range(3)]
time = 0
while time<=100:
    if len(mat) >= r and len(mat[0]) >= c:
        if mat[r - 1][c - 1] == k:
            break
    r_cal() if len(mat) >= len(mat[0]) else c_cal()
    time += 1
print(-1) if time ==101 else print(time)