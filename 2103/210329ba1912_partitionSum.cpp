#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int number;
    cin>>number;
    vector<int> list(number+1,0);
    vector<int> dp(number+1,0);
    for(int i=0;i<number;i++){
        cin>>list[i];
    }
    dp[0]=list[0];
    int maxN=list[0];
    for(int i=1;i<number;i++){
        maxN=max(list[i],maxN+list[i]);
        dp[i]=max(dp[i-1],maxN);
    }
    cout<<dp[number-1];
    return 0;
    
}