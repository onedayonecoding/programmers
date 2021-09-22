/*
   작성자 : 정택구 
   파일 내용 : 프로그래머스 래밸 1 체육복
   문제 : https://programmers.co.kr/learn/courses/30/lessons/42862 참조
   문제 풀이 :
   1. 체육복을 잃어버린 사람과 여분의 체육복 있는사람이 일치하면 vector에서 제거

*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    for (int i = lost.size()-1; i >= 0; i--) {           // 문제풀이 1번 시작
        for (int j = reserve.size()-1; j >= 0; j--) {
            if (lost[i] == reserve[j]) {
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
                break;
            }
        }
    }                                                     // 문제풀이 1번 끝
    
    if (lost.size()==0 || reserve.size()==0){
        answer = n - lost.size();
    }
    else{
        for (int i = lost.size()-1; i >= 0; i--) {
            for (int j = reserve.size()-1; j >= 0; j--) {
                if (lost[i] == reserve[j] - 1 || lost[i] == reserve[j] + 1) {
                    lost.erase(lost.begin() + i);
                    reserve.erase(reserve.begin() + j);
                    break;
                }
            }
        }
        answer = n - lost.size();
    }

    return answer;
}
