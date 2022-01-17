/*
   작성자 : 정택구
   파일 내용 : 프로그래머스 래밸 2 최소값 만들기
   문제 : https://programmers.co.kr/learn/courses/30/lessons/12941
   문제 풀이 :
       1. 벡터A 오름차순 정렬
       2. 벡터B 내림차순 정렬
       3. 벡터A,B 각각 원소들 곱해서 더하기
*/

#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(),A.end());                         // 1번 과정
    sort(B.begin(),B.end(),greater<int>());          // 2번 과정
    
    for(int i=0; i<A.size();i++){                    
        answer+=A[i]*B[i];                           // 3번과정
    }

    return answer;
}
