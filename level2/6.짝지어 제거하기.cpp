/*
   파일 내용 : 프로그래머스 래밸 2 짝지어 제거하기
   문제 : https://programmers.co.kr/learn/courses/30/lessons/12973
   문제 풀이 :
       1. 문자를 받을 스텍 생성
       2. 0부터 s의 길이 만큼 반복문
       2-1. 스택이 비었거나 s[i]와 스텍의 문자가 같지 않으면 스텍에 s[i] 스텍에 추가
       2-2. 아니면 스택 pop
*/

#include <string>
#include <stack>
using namespace std;


int solution(string s){
    int answer = 0;
    stack <char> stack_s;                           // 1번 과정
    
    for(int i=0; i<s.length(); i++){                // 2번 과정 시작
        if(stack_s.empty() || s[i]!=stack_s.top()){
            stack_s.push(s[i]);                     // 2-1 과정
        }else{
            stack_s.pop();                          // 2-2 과정
        }
    }                                               // 2번과정 끝
    
    if(stack_s.empty()) answer=1;
    
    return answer;
}
