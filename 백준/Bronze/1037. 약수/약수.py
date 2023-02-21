N = int(input())
arr = [*map(int, input().split())]
arr.sort()

result = arr[0]*arr[-1]
print(result)