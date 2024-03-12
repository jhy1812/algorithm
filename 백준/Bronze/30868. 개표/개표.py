T = int(input())

for tc in range(T):
    st = ""
    n = int(input())
    for i in range(0, n//5):
        st += "++++ "
    for i in range(0, n%5):
        st += "|"
    print(st)