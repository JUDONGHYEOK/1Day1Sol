#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int number=priorities.size();
    queue<pair<int,int>> printer;
    multiset<int,greater<int>> order;
    
    for(int i=0;i<number;i++){
        printer.push({i,priorities[i]});
        order.insert(priorities[i]);
    }
    while(1){
        while(printer.front().second!=*order.begin()){
            printer.push(printer.front());
            printer.pop();
        }
        int currentLocation=printer.front().first;
        printer.pop();
        order.erase(order.begin());
        answer++;
        if(currentLocation==location)
            break;
    }
    
    
    return answer;
}