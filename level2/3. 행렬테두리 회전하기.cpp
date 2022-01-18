/*
   ���� ���� : ���α׷��ӽ� ���� 2 ��� �׵θ� ȸ���ϱ�
   ���� : https://programmers.co.kr/learn/courses/30/lessons/77485
   ���� Ǯ�� :
	1. �Է°� rows, columns�� ���� ��� �����
    2. ù ��° queries ���ڿ� ���ؼ� ���� ����
    3. ȸ�� ���Ѿ� �� �׵θ����� �� ���� ��� ���� ���� �� priority_queue ����
    4. �׵θ� ���� ���� �̵� �� ������ priority_queue�� ����
    5. �׵θ� �����ʺ� ���� �̵� �� ������ priority_queue�� ����
    6. �׵θ� �Ʒ��� ���� �̵� �� ������ priority_queue�� ����
    7. �׵θ� ���ʺ� ���� �̵� �� ������ priority_queue�� ����
    8. ���� ���� ����(���� ������) answer�� push
    9. 2~8 �ݺ�
*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> base;
    int num = 1;
    //���� 1 ����
    for (int i = 0; i < rows; i++) {
        base.push_back({});
        for (int j = 0; j < columns; j++) {
            base[i].push_back(num);
            num++;
        }
    }
    //���� 1 ��

    for (int i = 0; i < queries.size(); i++) {
        //���� 2 ����
        int y1 = queries[i][0] - 1;
        int x1 = queries[i][1] - 1;
        int y2 = queries[i][2] - 1;
        int x2 = queries[i][3] - 1;
        //���� 2 ��

        //���� 3
        int index1 = base[y1][x1], index2;
        priority_queue<int, vector<int>, greater<int>> nums;

        //���� 4 ����
        for (int i = x1; i < x2; i++) {
            nums.push(index1);
            index2 = base[y1][i + 1];
            base[y1][i + 1] = index1;
            index1 = index2;
        }
        //���� 4 ��
        
        //���� 5 ����
        for (int i = y1; i < y2; i++) {
            nums.push(index1);
            index2 = base[i + 1][x2];
            base[i + 1][x2] = index1;
            index1 = index2;
        }
        //���� 5 ��
        
        //���� 6 ����
        for (int i = x2; i > x1; i--) {
            nums.push(index1);
            index2 = base[y2][i - 1];
            base[y2][i - 1] = index1;
            index1 = index2;
        }
        //���� 6 ��
        
        //���� 7 ����
        for (int i = y2; i > y1; i--) {
            nums.push(index1);
            index2 = base[i - 1][x1];
            base[i - 1][x1] = index1;
            index1 = index2;
        }
        //���� 7 ��

        //���� 8
        answer.push_back(nums.top());
    }

    return answer;
}
