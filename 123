/*
   작성자 : 정택구 
   파일 내용 : 프로그래머스 래밸 1 로또의 최고 순위와 최저 순위
   문제 : https://programmers.co.kr/learn/courses/30/lessons/77484 참조
   문제 풀이 :
   1. lottos와 win_nums 벡터의 요소가 몇개 일치하는지 확인
   2. win_nums의 일치하는 요소 제거
   3. lottos의 0의 갯수 확인
   4. 최고 등수 : 1 + win_nums의 남은 요소 갯수 - lottos의 0의 갯수
      최저 등수 : 1 + win_nums의 남은 요소 갯수 ( 단 최저등수가 7일때 6으로 바꿀 것)
*/

#include <string>
#include <vector>
#include <iterator>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zeroC=0;            // lottos의 0의 갯수
    for(int i=0;i<6;i++){
        if(lottos[i]==0) zeroC++;       //문제풀이 3번 과정
        for(int j=0;j<6;j++){
            if(lottos[i]==win_nums[j]){           //문제풀이 1번 및 2번 과정 시작
                for(int k=j;k<5;k++){
                    win_nums[k]=win_nums[k+1];
                }
                lottos.pop_back();
                win_nums.pop_back();
                break;                            // 문제풀이 1번 및 2번 과정 끝
            }
        }
    }
    
    int best, worst;
    
    best=1+win_nums.size()-zeroC;      //최고 등수
    worst=1+win_nums.size();           //최저 등수
    
    if(best>6) best=6;                // 문제풀이 4번 과정
    if(worst>6) worst=6;
    
    answer.push_back(best);
    answer.push_back(worst);
    
    return answer;
}
