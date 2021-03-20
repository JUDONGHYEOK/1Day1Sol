#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class Path{
public:
    int count;
    int x;
    int y;
    Path(int count,int x,int y):count(count),x(x),y(y){};
};


int main(){
    int row;
    int column;
    cin>>column>>row;
    vector<vector<char>> v(row,vector<char>(column,0));

    for(int i=0;i<row;i++){
        string s;
        cin>>s;
        for(int j=0;j<column;j++){
            v[j][i]=s[j];
        }
    }
    vector<int>picked;
	int count=0;
    int isConnected=0;
    for(int i=0;i<column;i++){
        if(v[i][0]=='c'){
            count++;
            queue<pair<int,int>>cycle;
            cycle.push({i,0});
            vector<vector<bool>> isVisited(row,vector<bool>(column,0));
            while(!cycle.empty()){
                int x=cycle.front().first;
                int y=cycle.front().second;
                cycle.pop();
                isVisited[x][y]=true;
                if(y!=row-1&&v[x][y+1]=='.'&&!isVisited[x][y+1]){
                    cycle.push({x,y+1});
                    isVisited[x][y+1]=true;
                }
                if(x!=0&&v[x-1][y]=='.'&&!isVisited[x-1][y]){
                    cycle.push({x-1,y});
                    isVisited[x-1][y]=true;
                }
                if(x!=column-1&&v[x+1][y]=='.'&&isVisited[x+1][y]){
                    cycle.push({x+1,y});
                    isVisited[x+1][y]=true;
                }
            }
            bool isClosed=false;
            for(int j=0;j<column;j++){
                if(isVisited[row-1][j]){
                    isClosed=true;
                    break;
                }
            }
            if(!isClosed){
                isConnected++;
                continue;
            }
            isVisited.clear();
            queue<Path> q;
            q.push(Path(0,i,0));
            bool isEnd=false;
            int pick=-1;
            while(!q.empty()){
                for(int i=0,j=q.size();i<j;i++){
                    if(q.front().y==row-1){
                        isEnd=true;
                        pick=q.front().count;
                        break;
                    }
                    Path pa=q.front();
                    q.pop();
                    if(pa.y!=row-1&&v[pa.x][pa.y+1]=='.'){
                        q.push(Path(pa.count,pa.x,pa.y+1));
                    }
                    if(pa.x!=0&&v[pa.x-1][pa.y]=='.'){
                        q.push(Path(pa.count+1,pa.x-1,pa.y));
                    }
                    if(pa.x!=column-1&&v[pa.x+1][pa.y]=='.'){
                        q.push(Path(pa.count+1,pa.x+1,pa.y));
                    }
                }
                if(isEnd)
                    break;
            }
            picked.push_back(pick);
        }
    }
    if(isConnected==count){
        cout<<"-1"<<endl;
    }else{
        sort(picked.begin(),picked.end());
        cout<<picked[0]<<endl;
    }
    return 0;
}
