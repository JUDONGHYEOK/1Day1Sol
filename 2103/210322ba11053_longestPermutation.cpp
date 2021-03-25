#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int number;
    cin>>number;
    vector<int> permutation(number+1,0);
    vector<int> dp(number+1,0);

    for(int i=0;i<number;i++){
        cin>>permutation[i];
    }
    int answer=1;
    dp[0]=1;
    for(int i=1;i<number;i++){
        int check=0;
        for(int j=0;j<i;j++){
            if(permutation[i]>permutation[j]){
                check=max(dp[j],check);
            }
        }
        dp[i]=check+1;

        answer=max(answer,dp[i]);
    }
    cout<<answer;

    return 0;

}