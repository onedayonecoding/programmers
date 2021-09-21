/*
   작성자 : 정택구 
   파일 내용 : 프로그래머스 래밸 1 모의고사
   문제 : https://programmers.co.kr/learn/courses/30/lessons/42840 참조
   문제 풀이 :
   1. 수포자들의 찍는 답 패턴 설정
   2. 점수계산 함수 생성( 점수계산은 정답과 찍는 패턴 1대1로 비교해서 1점씩 올리는 방식)
   3. 1번 수포자를 answer값 삽입
   4. 만약 그 다음 수포자가 점수가 높으면 answer값 클리어 후 그 점수 높은 수포자 answer 값 삽입
      만약 그 다음 수포자와 점수가 같다면 answer값에 추가
      3번까지 반복
*/

#include <vector>
#include <string>

using namespace std;

int countpoint(int arr[], vector<int> answers,int size){   //점수계산 함수
    int point=0;

    for (int i = 0; i < answers.size(); i++){
        if (arr[i%size] == answers[i])   point += 1;
    }

    return point;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int man1[5]= {1,2,3,4,5 };                    // 문제풀이 1과정
    int man2[8] ={2,1,2,3,2,4,2,5 };
    int man3[10]={3,3,1,1,2,2,4,4,5,5 };

    int point[3];
    point[0] = countpoint(man1, answers,5);
    point[1] = countpoint(man2, answers,8);
    point[2] = countpoint(man3, answers,10);

    int temp = point[0];
    answer.push_back(1);                         // 문제풀이 3번 과정
    for (int i = 1; i < 3; i++){                     // 문제풀이 4번 시작
        if (point[i] > temp){
            temp = point[i];
            answer.clear();
            answer.push_back(i + 1);
        }
        else if (point[i] == temp) answer.push_back(i + 1);
    }                                               // 문제풀이 4번 끝

    return answer;
}
