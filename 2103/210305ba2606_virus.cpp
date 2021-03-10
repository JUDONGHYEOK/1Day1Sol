#include<vector>
#include<iostream>
#include<queue>

using namespace std;

int main(){

    int size,number;
    cin>>size;
    cin>>number;

    vector<int> graph[size+1];
    vector<bool> visit;
    for(int i=0;i<size;i++){
        visit.push_back(false);
    }
    queue<int> q;
    vector<int> virus;

    for(int i=0;i<number;i++){
        int v1,v2;
        cin>>v1;
        cin>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    int count=0;
    q.push(1);
    visit[1]=true;
    while(!q.empty()){

        int x=q.front();
        q.pop();
        for(int i=0;i<graph[x].size();i++){
            int y=graph[x][i];
            if(!visit[y]){
                q.push(y);
                visit[y]=true;
                virus.push_back(y);
            }
        }
    }

    cout<<virus.size()<<'\n';

    return 0;

}