/*
   파일 내용 : 프로그래머스 래밸 2 최소값 만들기
   문제 : https://programmers.co.kr/learn/courses/30/lessons/12913
   문제 풀이 :
       1. i-1 인덱스에 최대값 인덱스값 저장
       2. i인덱스 벡터 반복
          -. j와 index값이 같으면 land[i][j]값에 land[i-1]에서 두번째로 큰값 더하기
          -. 아니면 land[i-1]에서 제일 큰값 더하기
       3. 1,2번 과정 반복
       4. land의 마지막 원소에서 제일 큰값 리턴
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land)
{
    for (int i = 1; i < land.size(); i++) {                                                      // 3번과정 시작
        int index = max_element(land[i - 1].begin(), land[i - 1].end()) - land[i - 1].begin();   // 1번과정

        for (int j = 0; j < 4; j++) {                                                            // 2번과정 시작
            if (j == index) {
                int max = *max_element(land[i - 1].begin(), land[i - 1].end());
                land[i - 1][index] = 0;
                land[i][j] += *max_element(land[i - 1].begin(), land[i - 1].end());
                land[i - 1][index] = max;
            }
            else {
                land[i][j] += land[i - 1][index];
            }                                                                                    // 2번과정 끝
        }
    }                                                                                            // 3번과정 끝

    return *max_element(land.back().begin(), land.back().end());                                 // 4번과정
}
