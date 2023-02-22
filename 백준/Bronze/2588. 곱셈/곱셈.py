A = int(input())
B = list(input())
sum = 0
j = 0
for i in range(2, -1, -1):
    sum += A*int(B[i])*(10**j)
    print(A*int(B[i]))
    j += 1
print(sum)