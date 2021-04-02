#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    int number;
    cin>>number;

    vector<vector<int>>table(number+1,vector<int>(number+1,0));
    vector<vector<long long>>dp(number+1,vector<long long>(number,0));
    for(int i=0;i<number;i++){
        for(int j=0;j<number;j++){
            cin>>table[i][j];
        }
    }
    dp[0][0]=1;
    for(int i=0;i<number;i++){
        for(int j=0;j<number;j++){
            if(dp[i][j]==0)
                continue;
            if(i==number-1&&j==number-1){
                cout<<dp[i][j]<<endl;
                return 0;
            }
            if(j+table[i][j]<=number-1){
                dp[i][j+table[i][j]]+=dp[i][j];
            }
            if(i+table[i][j]<=number-1){
                dp[i+table[i][j]][j]+=dp[i][j];
            }
        }
    }

    cout<<"0"<<endl;
    return 0;
}
