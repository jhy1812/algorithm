N = int(input())
pack = [3, 5]
sum = 0
flag = 0
for i in range(N//5, -1, -1):
    if (N - i*5)%3 == 0:
        flag += 1
        sum = i + (N-i*5)//3
        break
if flag == 0:
    print(-1)
else:
    print(sum)