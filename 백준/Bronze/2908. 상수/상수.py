A, B = input().split()
flag = 0
for i in range(2, -1, -1):
    if int(A[i]) > int(B[i]):
        print(A[-1::-1])
        flag += 1
        break
    elif int(A[i]) < int(B[i]):
        print(B[-1::-1])
        flag += 1
        break
if flag == 0:
    print(A[-1::-1])
