def solution(numbers, direction):
    answer = []
    if direction == 'right':
        tmp = numbers[-1]
        del numbers[-1]
        answer = [tmp] + numbers
    else:
        tmp = numbers[0]
        del numbers[0]
        answer = numbers + [tmp]
    return answer