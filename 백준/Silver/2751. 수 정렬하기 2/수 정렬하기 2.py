import sys
input=sys.stdin.readline

numList = [int(input()) for _ in range(int(input()))]
sortList = sorted(numList)
for num in sortList:
    print(num)