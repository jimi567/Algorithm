"""
내가 푼 방식
시간초과로 x 더 나은 방향 찾아야됨
import sys
import math
#sys.stdin = open("input.txt", 'r') #제출할땐 지워야됨
def isPrime(n): # 소수판별 함수 시간복잡도 O(sqrt(n))
    answer = True
    for i in range(2, int(math.sqrt(n))+1):
        if (n % i == 0):
            answer = False
    if (n == 1):
        answer = False
    return answer
def solution(n):
    answer = {}
    ans_min = n
    for i in range(2, n):
        if ( isPrime(i) & isPrime(n-i)): # 2~n 까지 i가 소수일떄, n-i도 소수일 경우 
            if(ans_min > abs(n - i - i)): # 두 소수의 차가 최솟값일때, answer[두 소수의 차] = [두소 수의 리스트] 딕셔너리에 저장함
                ans_min = abs(n - i - i)
                answer[ans_min] = [i , n-i]

    return answer[ans_min][0] , answer[ans_min][1]  //loop문을 다돌면 ans_min는 두 소수의 차들중 최솟값이므로 그 두 소수를 리턴

if __name__ == "__main__":
    loop = int(sys.stdin.readline())
    for i in range(loop) :
       # a, b = map(int, input().split())
        a = int(sys.stdin.readline())
        r1 ,r2 =solution(a)
        print(r1,r2)
"""
#정답 코드 
import sys
import math
#sys.stdin = open("input.txt", 'r') #제출할땐 지워야됨
def isPrime(n): #소수판별하는 함수
    answer = True
    if (n == 1):
        answer = False
    else:
        for i in range(2, int(math.sqrt(n))+1):
            if (n % i == 0):
                answer = False

    return answer
def solution(n):
    a, b = n // 2, n // 2
    while a > 0:
        if isPrime(a) and isPrime(b): # n의 절반을 기준으로 +1 -1해가며 그 두 수가 소수일때 리턴, 절반을 기준으로 하니깐 처음 리턴하는값이 무조건 최소
            return a, b
        else:
            a -= 1
            b += 1

if __name__ == "__main__":
    loop = int(sys.stdin.readline())
    for i in range(loop) :
       # a, b = map(int, input().split())
        a = int(sys.stdin.readline())
        r1 ,r2 =solution(a)
        print(r1,r2)
 
