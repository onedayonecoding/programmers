/*
   작성자 : 정택구
   파일 내용 : 프로그래머스 래밸 2 기능개발
   문제 : https://programmers.co.kr/learn/courses/30/lessons/42586
   문제 풀이 :
   1. 각 작업이 몇일 만에 끝나는지 확인하고 일짜 queue에 저장
   2. 첫 번째 작업 끝나는 일짜 확인하고 제거, 리턴값 job 1로 설정
   3. 반복 작업
      3-1. 만일 이전작업보다 걸리는 시간이 작다면 job 1더하기
      3-2. 만일 이전작업보다 걸리는 시간이 크다면 job answer벡터에 저장, process queue 요소 1개 제거, job 1로 리셋
      3-3. process가 남은 것이 1개라면(progresses 크기-1) job 리턴 (사실상 break)
*/

#include <string>
#include <vector>
#include <cmath>
#include<queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int>process;

    // 1번과정 시작
    for (int i = 0; i < progresses.size(); i++){
        int a = ceil((float)(100 - progresses[i]) / speeds[i]);
        process.push(a);
    }
    // 1번과정 끝

    // 2번과정 시작
    int index = process.front(), job=1;
    process.pop();
    // 2번과정 끝

    // 3번과정 시작
    for (int j = 0; j < progresses.size()-1;j++){
        // 3-1과정 시작
        if (process.front() <= index) {
            job++;
            process.pop();
        }
        // 3-1과정 끝

        // 3-2과정 시작
        else {
            answer.push_back(job);
            index = process.front();
            process.pop();
            job = 1;
        }
        // 3-2과정 끝

        // 3-3과정 시작
        if (j == progresses.size() - 2) {
            answer.push_back(job);
        }
        // 3-3과정 끝
    }
    // 3번과정 끝

    return answer;
}



