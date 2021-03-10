#include<iostream>
#include<queue>

using namespace std;

int main(){

    int start,target;
    cin>>start>>target;

    queue<int>graph;
    bool isVisited[100001]={0,};
    bool isCorrect=false;
    graph.push(start);
    int count=0;
    while(1){
        if(isCorrect)
        {
            break;
        }
        for(int i=0,j=graph.size();i<j;i++){
            int number=graph.front();
        
            if(number==target){
                break;
            }

            if(number-1==target||number+1==target||2*number==target){
                count++;
                break;
            }
            isVisited[number]=1;
            graph.pop();
            if(number-1>=0&&!isVisited[number-1]){
                graph.push(number-1);
            }
            if(number+1<=100000&&!isVisited[number+1]){
                graph.push(number+1);
            }
            if(2*number<=100000&&!isVisited[2*number]){
                graph.push(2*number);
            }
        }
        
    }
    
    cout<<count<<'\n';

    return 0;
}