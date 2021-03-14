#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int y=3,number=1;
    int x=(brown-(2*y))/2;
    int numberOfYellow=x*number;
    while(numberOfYellow!=yellow){
        number++;
        y++;
        x=(brown-(2*y))/2;
        numberOfYellow=x*number;
    }
    answer.push_back(x+2);
    answer.push_back(y);
    return answer;
}