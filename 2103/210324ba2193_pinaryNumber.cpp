#include<iostream>
#include<vector>

using namespace std;

int main(){
    int number;
    cin>>number;
    vector<long long> dp(91,0);

    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    for(int i=4;i<number;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }

    cout<<dp[number-1];

    return 0;


}