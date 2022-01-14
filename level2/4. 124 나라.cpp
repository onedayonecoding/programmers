#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";
    
    while(n>0){
        n--;
        int num = n%3;
        n-=num;

        n/=3;
        if(num==2){
            answer = "4"+answer;
        }else{
            answer = to_string(num+1)+answer;
        }
    }
    return answer;
}
