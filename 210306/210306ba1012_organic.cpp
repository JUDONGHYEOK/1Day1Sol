#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main(){

    int number;
    cin>>number;
    vector<int> answer;
    for(int p=0;p<number;p++){
        int row,column,time;
        cin>>row;
        cin>>column;
        cin>>time;
        vector<int>fields[column+1];
        vector<bool>visited[column+1];
        for(int t=0;t<column+1;t++){
            fields[t].clear();
            visited[t].clear();
        }
        for(int i=0;i<column+1;i++){
            for(int j=0;j<row+1;j++){
                fields[i].push_back(0);
                visited[i].push_back(false);
            }
        }

        int k=0;
        do{
            int x,y;
            cin>>x;
            cin>>y;
            fields[y][x]=1;
            k++;
        }while(k!=time);

        int count=0;
        for(int i=0;i<column+1;i++){
            for(int j=0;j<row+1 ;j++){
                stack<pair<int,int>> st;
                if(fields[i][j]==1&&visited[i][j]==false){
                    count++;
                    st.push({i,j});
                    visited[i][j]=true;
                    while(!st.empty()){
                        int x=st.top().first;
                        int y=st.top().second;
                        visited[x][y]=true;
                        st.pop();
                        if(fields[x+1][y]==1&&visited[x+1][y]==false){
                            st.push({x+1,y});
                        }
                        if(fields[x][y+1]==1&&visited[x][y+1]==false){
                            st.push({x,y+1});
                        }
                        if(x>=1){
                            if(fields[x-1][y]==1&&visited[x-1][y]==false){
                                st.push({x-1,y});
                            }
                        }
                        if(y>=1){
                            if(fields[x][y-1]==1&&visited[x][y-1]==false){
                                st.push({x,y-1});
                            }
                        }
                    }
                }
            }
        }
        answer.push_back(count);
    }
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<endl;
    }
    return 0;

}