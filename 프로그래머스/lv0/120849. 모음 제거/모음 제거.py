def solution(my_string):
    answer = ''
    mo = ['a', 'e', 'i', 'o', 'u']
    for i in my_string:
        if i in mo:
            continue
        answer += i
    return answer