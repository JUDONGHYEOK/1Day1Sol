#include <string>
#include <vector>
#include <algorithm>
#include <set>  
#include <cmath>

using namespace std;

set<int> pick;

void powerSet(vector<int> arr,vector<int> arr2,int index,int number){
    if(index==number){
        string s;
        for(int i=0;i<arr2.size();i++){
            char a=arr2[i]+'0';
            s+=a;
        }
        pick.insert(atoi(s.c_str()));
    }
    else{
        vector<int> newVector=arr2;
        newVector.push_back(arr[index]);
        powerSet(arr,arr2,index+1,number);
        powerSet(arr,newVector,index+1,number);  
    }
}

bool isPrimary(int num){
    if(num<2){
        return false;
    }
    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0)
            return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    string p="";
    vector<int> v,v1;
    for(int i=0;i<numbers.length();i++){
        int a=numbers[i]-'0';
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    do{
        powerSet(v, v1, 0, numbers.length());
    }while(next_permutation(v.begin(),v.end()));

    for(auto j=pick.begin();j!=pick.end();j++){
        if(isPrimary(*j)){
            answer++;
        }
    }
    
    return answer;
}