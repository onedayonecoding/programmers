/*
   파일 내용 : 프로그래머스 래밸 2 최소값 만들기
   문제 : https://programmers.co.kr/learn/courses/30/lessons/12909
   문제 풀이 :
       1. answer 정수형 자료 생성
       2. 문자열 s를 하나하나 체크해서
          -. (이면 +1
          -. )이면 -1
          -. answer가 한번이라도 음수이면 false리턴
       3. answer가 0이면 true 아니면 false리턴
*/

#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int answer = 0;                         //1번과정
  
    for(int i = 0; i<s.length(); i++){      //2번과정 시작
        if(s[i]=='(') answer++;
        else answer--;
        if (answer<0) return false;
    }                                       //2번과정 끝
  
    if(answer==0) return true;              //3번과정
    else return false;              
}
