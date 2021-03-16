#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer=0;
    int sizeOfNumbers=numbers.size();
    queue<int> q;
    q.push(numbers[0]);
    q.push(-numbers[0]);
    int count=1;
    while(!q.empty()){
        if(count==sizeOfNumbers){
            while(!q.empty()){
                int result=q.front();
                q.pop();
                if(result==target){
                    answer++;
                }
            }
            break;
        }
        for(int i=0,j=q.size();i<j;i++){
            int fr=q.front();
            q.pop();
            q.push(fr+numbers[count]);
            q.push(fr-numbers[count]);
        }
        count++;
    }
    
    return answer;
}