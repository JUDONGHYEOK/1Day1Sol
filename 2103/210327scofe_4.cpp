#include<iostream>
#include<string>
#include<vector>

using namespace std;


int main(){
    int number,qs;
    cin>>number;
    vector<string> list(number,"0");

    for(int i=0;i<number;i++){
        cin>>list[i];
    }
    cin>>qs;
    for(int j=0;j<qs;j++){
        int count=0;
        string s;
        cin>>s;
        for(int k=0;k<number;k++){
            if(list[k].find(s)!=string::npos){
                count++;
            }
        }
        cout<<count<<endl;
    }
}