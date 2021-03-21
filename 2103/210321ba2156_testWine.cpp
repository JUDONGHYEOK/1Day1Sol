#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    int number;
    cin>>number;
    vector<int> wine(number,0);
    vector<int> dp(number,0);
    for(int i=0;i<number;i++){
        int amountOfWine;
        cin>>amountOfWine;
        wine[i]=amountOfWine;
    }

    dp[0]=wine[0];
    dp[1]=wine[0]+wine[1];
    dp[2]=max(dp[0]+wine[2],dp[1]);
    dp[2]=max(dp[2],wine[1]+wine[2]);
    for(int i=3;i<number;i++){
        dp[i]=max(dp[i-3]+wine[i-1],dp[i-2])+wine[i];
        dp[i]=max(dp[i],dp[i-1]);
    }
    
    cout<<dp[number-1];
    return 0;
}