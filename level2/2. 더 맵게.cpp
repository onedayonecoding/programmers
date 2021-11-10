#include <iostream>
#include <string>
#include <vector>
#include<iterator>
#include<algorithm>
#include<queue>

using namespace std;



int solution_answer(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq (scoville.begin(), scoville.end());   
    //priority_queue<자료형, 복사할 리스트종류,내림차수면 greater 올림차수면 필요없음> 이름 (시작,끝)
    while (pq.size() > 1 && pq.top() < K) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        pq.push(first + 2 * second);
        answer++;
    }
    if (pq.top() < K) return -1;

    return answer;
}


int solution(vector<int> scoville, int K) {
    int answer = 0, point;
    sort(scoville.begin(), scoville.end());

    do {
        if (scoville.size() < 2) {
            answer = -1;
            break;
        }
        answer++;
        point = scoville[0] + 2 * scoville[1];
        scoville.erase(scoville.begin(), scoville.begin() + 2);
        scoville.push_back(point);
        sort(scoville.begin(), scoville.end());
    } while (scoville[0] < K);

    return answer;
}




int main() {

    cout << solution({ 1, 2, 3, 9, 10, 12 }, 7);

}

