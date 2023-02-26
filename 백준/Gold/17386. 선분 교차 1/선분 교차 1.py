import sys
input = sys.stdin.readline

x1, y1, x2, y2 = [*map(int, input().split())]
x3, y3, x4, y4 = [*map(int, input().split())]


if ((x2-x1)*y3-(y2-y1)*(x3-x1)-y1*(x2-x1))*((x2-x1)*y4-(y2-y1)*(x4-x1)-y1*(x2-x1)) < 0:
    if ((x3-x4)*y1-(y3-y4)*(x1-x3)-y3*(x3-x4))*((x3-x4)*y2-(y3-y4)*(x2-x3)-y3*(x3-x4)) < 0:
        print(1)
    else:
        print(0)
else:
    print(0)