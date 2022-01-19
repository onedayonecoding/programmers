/* 
   파일 내용 : 프로그래머스 래밸1 완주하지 못한 선수 
   문제 : https://programmers.co.kr/learn/courses/30/lessons/42576 참조
   문제 풀이 :
   1. 참가자, 완주자 벡터 문자순으로 정렬
   2. 참가자, 완주자 벡터 순서대로 비교, 서로 다를 때 참가자 요소를 정답으로 리턴
*/

#include <string>
#include <vector>
#include<algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

	sort(participant.begin(),participant.end());                  // 문제풀이 1번 과정
	sort(completion.begin(), completion.end());

    for (int i = 0; i < completion.size(); i++){                // 문제풀이 2번 과정
        if (participant[i] != completion[i]){
            answer = participant[i];
            break;
        }
        else if(i== completion.size()-1)  answer = participant[i+1];   //반복문 과정에서 segmentation fault 에러 방지용
    }

    return answer;
}
