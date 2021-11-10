#include<iostream>
#include <vector>
#include<algorithm>
#include <iterator>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	sort(participant.begin(),participant.end());
	sort(completion.begin(), completion.end());
	copy(participant.begin(), participant.end(), ostream_iterator<string>(cout, " ")); cout << endl;
	copy(completion.begin(), completion.end(), ostream_iterator<string>(cout, " ")); cout << endl;

	for (int i = 0; i < completion.size(); i++)
	{
		if (participant[i] != completion[i])
		{
			answer = participant[i];
			break;
		}
		else if (i == completion.size() - 1)  answer = participant[i + 1];
	}

	return answer;
}

int main(void)
{
	cout << solution({ "marina", "josipa", "nikola", "vinko", "filipa" }, { "josipa", "filipa", "marina", "nikola" });
}
