check_list = ['ZRO', 'ONE', 'TWO', 'THR', 'FOR', 'FIV', 'SIX', 'SVN', 'EGT', 'NIN']

T = int(input())

for tc in range(1, T+1):
    test_case, N = input().split()
    N = int(N)

    number_list = list(input().split())

    print(test_case)

    for i in check_list:
        for j in number_list:
            if i == j:
                print(i, end=' ')
    print()