#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    int number;
    cin>>number;
    string time;
    cin>>time;
    vector<int> limitTime;
    int limit=0;
    for(int i=0;i<time.length();i+=3){
        int tens=time[i]-'0';
        int units=time[i+1]-'0';
        limitTime.push_back(tens*10+units);
    }
    limit+=limitTime[0]*3600+limitTime[1]*60+limitTime[2];
    vector<int>playlist;
    for(int i=0;i<number;i++){
        string s;
        cin>>s;
        int tens_min_list=s[0]-'0';
        int units_min_list=s[1]-'0';
        int tens_sec_list=s[3]-'0';
        int units_sec_list=s[4]-'0';
        int min=tens_min_list*10+units_min_list;
        int sec=tens_sec_list*10+units_sec_list;
        playlist.push_back(min*60+sec);
    }
    int index=0;
    int count=0;
    for(int j=0;j<number;j++){
        int max=0;
        int pos=j;
        while(max<limit){
            max+=playlist[pos];
            pos++;
            if(pos==number){
                break;
            }
        }
        if(pos-j>count){
            count=pos-j;
            index=j;
        }
    }
    cout<<count<<" "<<index+1;
    return 0;
}