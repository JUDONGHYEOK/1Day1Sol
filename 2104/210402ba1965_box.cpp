#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    int number;
    cin>>number;
    vector<int>boxes(number+1,0);
    vector<int>dp(number+1,0);
    for(int i=0;i<number;i++){
        cin>>boxes[i];
    }

    dp[0]=1;
    int answer=dp[0];
    
    for(int i=1;i<number;i++){
        int check=0;
        for(int j=0;j<i;j++){
            if(boxes[j]<boxes[i]){
                check=max(dp[j],check);
            }
        }
        check+=1;
        dp[i]=check;
        answer=max(answer,dp[i]);
    }
    cout<<answer;

    return 0;
}