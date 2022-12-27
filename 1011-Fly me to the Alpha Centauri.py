
import sys
#sys.stdin = open("input.txt", 'r')
def solution(n,m):
    answer = 0

    canMove = 1;
    left_dist = m-n
    while(left_dist > 0):
        answer += 1
        left_dist -= canMove
        if answer % 2 == 0 :
            canMove += 1



    return answer

if __name__ == "__main__":
    loop = int(input())
    for i in range(loop) :
        a, b = map(int, input().split())
        print(solution(a,b))