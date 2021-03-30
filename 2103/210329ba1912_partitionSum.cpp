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
    for(int i=1;i<number;i++){
        int check=dp[i-1];
        int sum=0;
        for(int j=i;j!=-1;j--){
            sum+=list[j];
            dp[i]=max(check,sum);
        }
    }

    for(int i=0;i<number;i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    cout<<dp[number-1];
    return 0;
    
}