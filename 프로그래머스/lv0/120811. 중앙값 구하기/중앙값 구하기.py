def solution(array):
    array = sorted(array, key=lambda x:x)
    answer = array[len(array)//2]
    return answer