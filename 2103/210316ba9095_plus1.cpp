#include<iostream>
#include<vector>

using namespace std;
long long visited[1000001];

int main(){
    int time;
    cin>>time;
    visited[0]=0;
    visited[1]=1;
    visited[2]=2;
    visited[3]=4;
    for(int j=4;j<=1000000;j++){
        visited[j]+=visited[j-1]%1000000009;
        visited[j]+=visited[j-2]%1000000009;
        visited[j]+=visited[j-3]%1000000009;
    }
    for(int i=0;i<time;i++){
        int number;
        cin>>number;
        cout<<visited[number]%1000000009<<endl;
    }
    return 0;
    

}