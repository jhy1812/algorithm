def solution(numer1, denom1, numer2, denom2):
    nm = denom1*denom2
    ns1 = numer1*denom2
    ns2 = numer2*denom1
    ns = ns1 + ns2
    for i in range(nm, 1, -1):
        if nm%i == 0 and ns%i == 0:
            nm = nm//i
            ns = ns//i
    answer = [ns, nm]
    return answer