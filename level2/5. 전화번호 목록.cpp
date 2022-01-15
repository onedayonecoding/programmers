/*
   작성자 : 정택구
   파일 내용 : 프로그래머스 래밸 2 전화번호 목록
   문제 : https://programmers.co.kr/learn/courses/30/lessons/42577
   문제 풀이 :
       1. phone_book 정렬
       2. phone_book 안의 원소가 뒷 원소의 앞부분과 같으면 answer을 false로 변경
       3. 2번 과정 phone_book의 길이 만큼 반복
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());                              //1번과정

    for (int i = 0; i < phone_book.size()-1; i++){
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size())){   //2번과정
            answer=false;
        }
    }
    return answer;
}
