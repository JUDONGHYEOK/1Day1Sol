#include <iostream>
#include <string>

using namespace std;
void printHourAndMin(int number){
    if(number>9){
        cout<<number;
    }else{
        cout<<"0"<<number;
    }
}
void printTime(int hour,int min){
    printHourAndMin(hour);
    cout<<":";
    printHourAndMin(min);
}
int main() {
	int number;
	cin>>number;
	int minTimeHour=0,minTimeMin=0;
	int maxTimeHour=24,maxTimeMin=0;
	for(int i=0;i<number;i++){
		string startTime,endTime;
		char wave;
		cin>>startTime>>wave>>endTime;
		int startTimeHour=(startTime[0]-'0')*10+startTime[1]-'0';
		int startTimeMin=(startTime[3]-'0')*10+startTime[4]-'0';
		if(minTimeHour*60+minTimeMin<startTimeHour*60+startTimeMin){
			minTimeHour=startTimeHour;
			minTimeMin=startTimeMin;
		}
		int endTimeHour=(endTime[0]-'0')*10+endTime[1]-'0';
		int endTimeMin=(endTime[3]-'0')*10+endTime[4]-'0';
		if(maxTimeHour*60+maxTimeMin>endTimeHour*60+endTimeMin){
			maxTimeHour=endTimeHour;
			maxTimeMin=endTimeMin;
		}
	}
	if(minTimeHour*60+minTimeMin>maxTimeHour*60+maxTimeMin){
		cout<<-1;
	}else{
        printTime(minTimeHour,minTimeMin);
        cout<<" ~ ";
        printTime(maxTimeHour,maxTimeMin);
	}
	
	return 0;
}