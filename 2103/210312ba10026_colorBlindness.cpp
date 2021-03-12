#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

int bfs(vector<char> gr[],int size){
    int number=0;
    vector<bool>isVisited[size];
    for(int i=0;i<size;i++){
        isVisited[i].resize(size);
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(!isVisited[i][j]){
                number++;
                queue<pair<int,int>> q;
                q.push({i,j});
                isVisited[i][j]=true;
                while(!q.empty()){
                    int x=q.front().first;
                    int y=q.front().second;
                    char c=gr[x][y];
                    q.pop();
                    if(x>=1&&gr[x-1][y]==c&&!isVisited[x-1][y]){
                        q.push({x-1,y});
                        isVisited[x-1][y]=true;
                    }
                    if(y>=1&&gr[x][y-1]==c&&!isVisited[x][y-1]){
                        q.push({x,y-1});
                        isVisited[x][y-1]=true;
                    }
                    if(x<size-1&&gr[x+1][y]==c&&!isVisited[x+1][y]){
                        q.push({x+1,y});
                        isVisited[x+1][y]=true;
                    }
                    if(y<size-1&&gr[x][y+1]==c&&!isVisited[x][y+1]){
                        q.push({x,y+1});
                        isVisited[x][y+1]=true;
                    }
                    
                }
            }
        }
    }
    return number;
}
int bfsBlindness(vector<char> gr[],int size){
    int number=0;
    vector<bool>isVisited[size];
    unordered_map<char, int> m;
    m.insert({'R',1});
    m.insert({'G',1});
    m.insert({'B',2});
    for(int i=0;i<size;i++){
        isVisited[i].resize(size);
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(!isVisited[i][j]){
                number++;
                queue<pair<int,int>> q;
                q.push({i,j});
                isVisited[i][j]=true;
                while(!q.empty()){
                    int x=q.front().first;
                    int y=q.front().second;
                    char c=gr[x][y];
                    q.pop();
                    if(x>=1&&m[gr[x-1][y]]==m[c]&&!isVisited[x-1][y]){
                        q.push({x-1,y});
                        isVisited[x-1][y]=true;
                    }
                    if(y>=1&&m[gr[x][y-1]]==m[c]&&!isVisited[x][y-1]){
                        q.push({x,y-1});
                        isVisited[x][y-1]=true;
                    }
                    if(x<size-1&&m[gr[x+1][y]]==m[c]&&!isVisited[x+1][y]){
                        q.push({x+1,y});
                        isVisited[x+1][y]=true;
                    }
                    if(y<size-1&&m[gr[x][y+1]]==m[c]&&!isVisited[x][y+1]){
                        q.push({x,y+1});
                        isVisited[x][y+1]=true;
                    }
                    
                }
            }
        }
    }
    return number;
}

int main(){
    int number;
    cin>>number;
    vector<char>graph[number];
    for(int i=0;i<number;i++){
        for(int j=0;j<number;j++){
            char c;
            cin>>c;
            graph[i].push_back(c);
        }
    }
    cout<<bfs(graph,number)<<endl;
    cout<<bfsBlindness(graph, number);
    return 0;
}