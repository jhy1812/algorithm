def solution(phone_number):
    
    answer = ''
    
    for i in range(0, len(phone_number), 1):
        if i < len(phone_number) - 4:
            answer += '*'
        else:
            answer += phone_number[i]
    
    return answer