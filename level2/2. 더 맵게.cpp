/*
   ���� ���� : ���α׷��ӽ� ���� 2 �� �ʰ�
   ���� : https://programmers.co.kr/learn/courses/30/lessons/42586
   ���� Ǯ�� :
	1. scoville vector�� priority_queue ������������ ��ȯ 
               (2���������� �ڵ����� ������ ���� ���
                �߰������� ������ �Ѵٸ� stack���ε� ���� Ǯ�� ����)
	2.  pq�� ù��°���� +2*�ι�° ���� ��� �� ù��° �ι�° ��� ����
                ��갪 push, answer���� 1 ���ϱ�
                pq size�� 1���� ũ�� pq �� �� ��Ұ� K���� ������ ���� �ݺ�
            3.  ���� pq �� �� ��Ұ� K���� �۴ٸ� -1 ���� �ƴϸ� answer����
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    //1������
    priority_queue<int, vector<int>, greater<int>> pq (scoville.begin(), scoville.end());

    //2������ ����
    while (pq.size() > 1 && pq.top() < K) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        pq.push(first + 2 * second);
        answer++;
    }
    //2������ ��

    // 3������
    if (pq.top() < K) return -1;

    return answer;
}
