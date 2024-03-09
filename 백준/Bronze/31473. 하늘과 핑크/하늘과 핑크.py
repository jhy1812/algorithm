N = int(input())

lst = [*map(int, input().split())]
arr = [*map(int, input().split())]

summ1 = sum(lst)
summ2 = sum(arr)

print(summ2, end=" ")
print(summ1)