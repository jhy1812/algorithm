def solution(sequence, k):
    answer = [0, len(sequence)]
    st = 0
    ed = 1
    summ = sequence[0]
    
    while True:
        if st >= len(sequence) and ed >= len(sequence):
            break;
        if ed >= len(sequence) or summ > k:
            summ -= sequence[st]
            st += 1
        elif summ < k:
            summ += sequence[ed]
            ed += 1
        if summ == k:
            if answer[1] - answer[0] > ed - st - 1:
                answer = [st, ed - 1]
            summ -= sequence[st]
            st += 1
        
    return answer