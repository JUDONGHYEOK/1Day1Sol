#include <iostream>
#include <string>
#include <queue>

using namespace std;
int main() {
	int number;
	string path;
	int caseToFinish=0;
	cin>>number;
	cin>>path;
	queue<int>q;
	q.push(0);
	while(!q.empty()){
		for(int i=0,j=q.size();i<j;i++){
			if(q.front()==number-1){
				caseToFinish++;
				q.pop();
				continue;
			}
			int index=q.front();
            q.pop();
			if(index+1<number&&path[index+1]=='1'){
				q.push(index+1);
			}
			if(index+2<number&&path[index+2]=='1'){
				q.push(index+2);
			}
		}
	}
	cout<<caseToFinish<<endl;
	return 0;
}