#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    string s1,s2;
    cin>>s1>>s2;
    vector<int>dp(s1.length()+1,0);
    dp[0]=0;
    int answer=0;
    for(int i=0;i<min(s1.length(),s2.length());i++){
        int check=0;
        for(int j=0;j<i;j++){
            if(s2[j]==s1[i]){
                check=max(dp[j],check);
            }
        }
        check+=1;
        dp[i]=check;
        answer=max(check,answer);
    }
    cout<<answer;
    return 0;
}