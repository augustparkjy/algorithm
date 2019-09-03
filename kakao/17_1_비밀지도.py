def solution(n, arr1, arr2):
    answer=[]
    for _ in range(n):
        answer.append("")
    mark=['#',' ']
    x=2**(n-1)
    for i in range(n):
        for j in range(n):
            answer[j]+=mark[arr1[j]-x<0 and arr2[j]-x<0]
            arr1[j]%=x
            arr2[j]%=x
        x//=2
    return answer

# def solution(n, arr1, arr2):
    # answer = []
    # for i,j in zip(arr1,arr2):
        # a12 = str(bin(i|j)[2:])
        # a12=a12.rjust(n,'0')
        # a12=a12.replace('1','#')
        # a12=a12.replace('0',' ')
        # answer.append(a12)
    # return answer