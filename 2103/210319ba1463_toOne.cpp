#include<iostream>
#include<vector>

using namespace std;

int main(){
    int number;
    cin>>number;

    int arr[1000001]={0,};
    arr[1]=0;
    arr[2]=1;
    arr[3]=1;
    for(int i=4;i<number+1;i++){
        int min=arr[i-1]+1;
        if(i%2==0){
            if(min>arr[i/2]+1){
                min=arr[i/2]+1;
            }
        }
        if(i%3==0){
            if(min>arr[i/3]+1){
                min=arr[i/3]+1;
            }
        }
        arr[i]=min;
    }

    cout<<arr[number];
    return 0;

}