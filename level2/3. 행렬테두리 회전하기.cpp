/*
   작성자 : 정택구
   파일 내용 : 프로그래머스 래밸 2 행렬 테두리 회전하기
   문제 : https://programmers.co.kr/learn/courses/30/lessons/77485
   문제 풀이 :
	1. 입력값 rows, columns에 대한 행렬 만들기
    2. 첫 번째 queries 인자에 대해서 변수 설정
    3. 회전 시켜야 할 테두리에서 맨 우측 상단 숫자 설정 및 priority_queue 생성
    4. 테두리 윗변 숫자 이동 및 모든숫자 priority_queue에 저장
    5. 테두리 오른쪽변 숫자 이동 및 모든숫자 priority_queue에 저장
    6. 테두리 아랫변 숫자 이동 및 모든숫자 priority_queue에 저장
    7. 테두리 왼쪽변 숫자 이동 및 모든숫자 priority_queue에 저장
    8. 제일 앞의 숫자(제일 작은값) answer에 push
    9. 2~8 반복
*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> base;
    int num = 1;
    //과정 1 시작
    for (int i = 0; i < rows; i++) {
        base.push_back({});
        for (int j = 0; j < columns; j++) {
            base[i].push_back(num);
            num++;
        }
    }
    //과정 1 끝

    for (int i = 0; i < queries.size(); i++) {
        //과정 2 시작
        int y1 = queries[i][0] - 1;
        int x1 = queries[i][1] - 1;
        int y2 = queries[i][2] - 1;
        int x2 = queries[i][3] - 1;
        //과정 2 끝

        //과정 3
        int index1 = base[y1][x1], index2;
        priority_queue<int, vector<int>, greater<int>> nums;

        //과정 4 시작
        for (int i = x1; i < x2; i++) {
            nums.push(index1);
            index2 = base[y1][i + 1];
            base[y1][i + 1] = index1;
            index1 = index2;
        }
        //과정 4 끝
        
        //과정 5 시작
        for (int i = y1; i < y2; i++) {
            nums.push(index1);
            index2 = base[i + 1][x2];
            base[i + 1][x2] = index1;
            index1 = index2;
        }
        //과정 5 끝
        
        //과정 6 시작
        for (int i = x2; i > x1; i--) {
            nums.push(index1);
            index2 = base[y2][i - 1];
            base[y2][i - 1] = index1;
            index1 = index2;
        }
        //과정 6 끝
        
        //과정 7 시작
        for (int i = y2; i > y1; i--) {
            nums.push(index1);
            index2 = base[i - 1][x1];
            base[i - 1][x1] = index1;
            index1 = index2;
        }
        //과정 7 끝

        //과정 8
        answer.push_back(nums.top());
    }

    return answer;
}
