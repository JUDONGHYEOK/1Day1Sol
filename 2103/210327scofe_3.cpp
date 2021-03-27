#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){

    int number,size;
    cin>>number>>size;
    vector<int>tree[number+1];

    for(int i=0;i<number-1;i++){
        int start,end;
        cin>>start>>end;
        tree[start].push_back(end);
    }
    for(int i=0;i<size;i++){
        int top,down;
        cin>>top>>down;
        queue<int>q;
        bool isConnected=false;
        if(!tree[top].empty()){
            q.push(top);
            while(!q.empty()){
                int front=q.front();
                q.pop();
                for(int j=0;j<tree[front].size();j++){
                    q.push(tree[front][j]);
                    if(tree[front][j]==down){
                        isConnected=true;
                    }
                }
            }
        }
        if(isConnected){
            cout<<"yes"<<endl;
        }else{
            cout<<"no"<<endl;
        }
    }


}