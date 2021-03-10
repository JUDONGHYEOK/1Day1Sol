#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<queue>

using namespace std;

void bfs(vector<int> data[],int size,int target){
    queue<int>q;
    bool isVisited[size];
    for(int i=0;i<size;i++){
        isVisited[i]=false;
    }
    q.push(target);
    isVisited[target]=true;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        cout<<x<<" ";
        for(int j=0;j<data[x].size();j++){
            if(!isVisited[data[x][j]]){
                q.push(data[x][j]);
                isVisited[data[x][j]]=true;
            }
        }
    }
    cout<<'\n';
}

void dfs(vector<int>data[],int size,int target){
    stack<int>st;
    bool isVisited[size];
    for(int i=0;i<size;i++){
        isVisited[i]=false;
    }
    st.push(target);
    while(!st.empty()){
        int x=st.top();
        st.pop();
        if(isVisited[x]){
            continue;
        }
        cout<<x<<" ";
        isVisited[x]=true;
        for(int y=data[x].size()-1;y>-1;y--){
            st.push(data[x][y]);
        }
    }
    cout<<'\n';
}

int main(){
    int size,number,target;
    cin>>size>>number>>target;
    vector<int> graph[size+1];

    for(int i=0;i<number;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i=0;i<size+1;i++){
        sort(graph[i].begin(),graph[i].end());
    }
    dfs(graph,size+1,target);
    bfs(graph,size+1,target);

    return 0;
}