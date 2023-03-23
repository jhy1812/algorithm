def solution(num_list):
    odd = 0
    even = 0
    for i in num_list:
        if i%2 == 1:
            odd += 1
        else:
            even += 1
    answer = [even, odd]
    return answer