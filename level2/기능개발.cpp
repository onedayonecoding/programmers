#include <iostream>
#include <string>
#include <vector>
#include<iterator>
#include<algorithm>
#include<queue>

using namespace std;




vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int>process;
    for (int i = 0; i < progresses.size(); i++){
        int a = ceil((float)(100 - progresses[i]) / speeds[i]);
        process.push(a);
    }
    while (!process.empty()) {
        cout << process.front() << ", ";
        process.pop();
    }

    for (int i = 0; i < progresses.size(); i++){
        int a = (100 - progresses[i]) / speeds[i];
        process.push(a);
    }
   
    cout << endl;
    int index = process.front(), job=1;
    process.pop();
    for (int j = 0; j < progresses.size()-1;j++){
        if (process.front() <= index) {
            job++;
            process.pop();
        }
        else {
            answer.push_back(job);
            index = process.front();
            process.pop();
            job = 1;
        }
        if (j == progresses.size() - 2) {
            answer.push_back(job);
        }
    }

    return answer;
}



int main() {

    vector <int> a=solution({93, 30,30, 55 }, { 1,30,30,5 });

    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " ")); cout << endl;

    double t = 10.0 / 3;
    cout << t;

	return 0;
}

