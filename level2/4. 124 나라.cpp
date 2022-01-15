/*
   작성자 : 정택구
   파일 내용 : 프로그래머스 래밸 2 124 나라
   문제 : https://programmers.co.kr/learn/courses/30/lessons/12899
   문제 풀이 :
       1. 입력값n에 -1하기
       2. n을 나머지 3처리한 값을 num이란 변수에 저장
       3. num이 2인 경우 4로 answer에 추가 아니면 num에서 1더한 값으로 추가  
       4. n을 3으로 나누기
       5. n이 0이 될때까지 1 ~ 4과정 반복
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";
    
    while(n>0){
        n--;                      // 1번과정
        int num = n%3;            // 2번과정
        
        if(num==2){               // 3번과정 시작
            answer = "4"+answer;
        }else{
            answer = to_string(num+1)+answer;
        }                         // 3번과정 끝
        
        n/=3;                     // 4번과정
    }
    return answer;
}
