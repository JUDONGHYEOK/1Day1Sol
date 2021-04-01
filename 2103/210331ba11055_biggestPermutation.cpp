#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int number;
    cin>>number;
    vector<int> list(number+1,0);
    vector<int>dp(number+1,0);
    for(int i=0;i<number;i++){
        cin>>list[i];
    }
    dp[0]=list[0];
    int answer=0;
    for(int i=0;i<number;i++){
        int checkSum=0;
        for(int j=0;j<i;j++){
            if(list[i]>list[j]){
                checkSum=max(dp[j],checkSum);
            }
        }
        checkSum+=list[i];
        dp[i]=checkSum;
        answer=max(answer,dp[i]);
    }
    cout<<answer;
    return 0;
}