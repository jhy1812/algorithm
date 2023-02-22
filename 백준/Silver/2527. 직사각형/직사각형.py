import sys
input = sys.stdin.readline

N = 4
for tc in range(1, N+1):
    lx1, ly1, rx1, ry1, lx2, ly2, rx2, ry2 = [*map(int, input().split())]
    if (lx1-lx2)*(ly1-ly2) > 0:
        if lx1 > lx2:
            if rx2 < lx1 or ry2 < ly1:
                print('d')
            elif rx2 == lx1 and ry2 == ly1:
                print('c')
            elif rx2 == lx1 or ry2 == ly1:
                print('b')
            else:
                print('a')
        else:
            if rx1 < lx2 or ry1 < ly2:
                print('d')
            elif rx1 == lx2 and ry1 == ly2:
                print('c')
            elif rx1 == lx2 or ry1 == ly2:
                print('b')
            else:
                print('a')
    elif (lx1-lx2)*(ly1-ly2) < 0:
        if lx1 > lx2:
            if rx2 < lx1 or ry1 < ly2:
                print('d')
            elif rx2 == lx1 and ry1 == ly2:
                print('c')
            elif rx2 == lx1 or ry1 == ly2:
                print('b')
            else:
                print('a')
        else:
            if rx1 < lx2 or ry2 < ly1:
                print('d')
            elif rx1 == lx2 and ry2 == ly1:
                print('c')
            elif rx1 == lx2 or ry2 == ly1:
                print('b')
            else:
                print('a')
    else:
        if lx1 == lx2 and ly1 == ly2:
            print('a')
        elif lx1 == lx2:
            if ly1 > ly2:
                if ry2 == ly1:
                    print('b')
                elif ry2 < ly1:
                    print('d')
                else:
                    print('a')
            else:
                if ry1 == ly2:
                    print('b')
                elif ry1 < ly2:
                    print('d')
                else:
                    print('a')
        else:
            if lx1 > lx2:
                if rx2 == lx1:
                    print('b')
                elif rx2 < lx1:
                    print('d')
                else:
                    print('a')
            else:
                if rx1 == lx2:
                    print('b')
                elif rx1 < lx2:
                    print('d')
                else:
                    print('a')

