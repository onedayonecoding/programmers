/*
   작성자 : 정택구
   파일 내용 : 프로그래머스 래밸 2 더 맵게
   문제 : https://programmers.co.kr/learn/courses/30/lessons/42586
   문제 풀이 :
	1. scoville vector를 priority_queue 오름차순으로 변환 
               (2번과정에서 자동으로 정렬을 위해 사용
                추가적으로 정렬을 한다면 stack으로도 문제 풀이 가능)
	2.  pq의 첫번째인자 +2*두번째 인자 계산 후 첫번째 두번째 요소 삭제
                계산값 push, answer값에 1 더하기
                pq size가 1보다 크고 pq 맨 앞 요소가 K보다 작을때 까지 반복
            3.  만약 pq 맨 앞 요소가 K보다 작다면 -1 리턴 아니면 answer리턴
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    //1번과정
    priority_queue<int, vector<int>, greater<int>> pq (scoville.begin(), scoville.end());

    //2번과정 시작
    while (pq.size() > 1 && pq.top() < K) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        pq.push(first + 2 * second);
        answer++;
    }
    //2번과정 끝

    // 3번과정
    if (pq.top() < K) return -1;

    return answer;
}
