/*
   작성자 : 정택구 
   파일 내용 : 프로그래머스 래밸 1 숫자 문자열과 영단어
   문제 : https://programmers.co.kr/learn/courses/30/lessons/81301 참조
   문제 풀이 :
   1. 숫자 벡터와 문자숫자 백터 생성
   2. 문자 s에서 숫자가 문자로 되어있는경우 숫자로 변환 후 answer에 삽입 ( 문자의 경우 앞의 알파벳 2개가 서로 다름을 이용한다)
      문자 s에서 숫자인 경우 그대로 answer에 삽입
   3. 정답이 정수형으로 리턴해야 함으로 정수형으로 변환 후 리턴
*/

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string answer ;
    vector<char> number = {'0', '1','2','3','4','5','6','7','8','9' };                                   // 문제풀이 1번 과정
    vector<string> snumber = {"zero", "one","two","three","four","five","six","seven","eight","nine" };

    s.push_back(NULL);   //반복문 과정에서 segmentation fault 에러 방지용
    for (int i = 0; i < s.size(); i++) {
        string index;
        index.push_back(s[i]);
        index.push_back(s[i + 1]);
        for (int j = 0; j < snumber.size(); j++) {   //문제풀이 2번과정 시작
            string num;                         //숫자 문자 앞2글자 확인용
            num.push_back(snumber[j][0]);
            num.push_back(snumber[j][1]);
            if (index == num) {                // 숫자 문자 일 경우 숫자로 삽입
                answer.push_back(number[j]);
            }
            else if(s[i]==number[j]) {        // 숫자인 경우 그대로 삽입
                answer.push_back(number[j]);
            }
        }                                           //문제풀이 2번과정 끝
    }

    return stoi(answer);                            //문제풀이 3번과정
}
