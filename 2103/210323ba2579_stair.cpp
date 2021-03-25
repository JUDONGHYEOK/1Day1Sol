#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int number;
    cin>>number;
    vector<int>score(number+2,0);
    for(int i=0;i<number;i++){
        cin>>score[i];
    }
    vector<int>dp(number+2,0);
    dp[0]=score[0];
    dp[1]=score[1]+dp[0];
    dp[2]=max(dp[0]+score[2],score[1]+score[2]);
    for(int i=3;i<number;i++){
        dp[i]=max(dp[i-3]+score[i-1]+score[i],dp[i-2]+score[i]);
    }

    cout<<dp[number-1]<<endl;

    return 0;

}