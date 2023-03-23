def solution(num_list, n):
    answer = [[0]*n for _ in range(len(num_list)//n)]
    for i in range(len(num_list)):
        answer[i//n][i%n] = num_list[i]
    return answer