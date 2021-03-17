#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int count=0;
    for(int i=0,k=lost.size();i<k;i++){
        for(int j=0;j<reserve.size();j++){
            if(reserve[j]==lost[i-count]){
                lost.erase(lost.begin()+i-count);
                reserve.erase(reserve.begin()+j);
                count++;
                break;
            }
        }   
    }
    count=0;
    for(int i=0,k=lost.size();i<k;i++){
        for(int j=0;j<reserve.size();j++){
            if(reserve[j]-1==lost[i-count]){
                lost.erase(lost.begin()+i-count);
                reserve.erase(reserve.begin()+j);
                count++;
                break;
            }else if(reserve[j]+1==lost[i-count]){   
                lost.erase(lost.begin()+i-count);
                reserve.erase(reserve.begin()+j);
                count++;
                break;
            }
        }
    }
    answer=n-lost.size();
    return answer;
}