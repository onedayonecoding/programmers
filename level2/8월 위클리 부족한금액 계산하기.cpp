#include <iostream>
#include <cstring>
#include <string>

using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1,index=0;

    for (int i = 1; i <= count; i++)  index += i;

    answer = index * price - money;

    cout << index<<endl;

    return answer > 0 ? answer:0;
}

int main(void)
{
    

    cout << solution(3, 29, 4);

    return 0;
}
