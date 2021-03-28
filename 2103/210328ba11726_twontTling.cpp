#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<long long>dp(1001,0);
    int number;
    cin>>number;

    dp[0]=1;
    dp[1]=2;
    dp[2]=3;

    for(int i=3;i<number;i++){
        dp[i]=(dp[i-1]+dp[i-2])%10007;
    }

    cout<<dp[number-1];
    return 0;
}