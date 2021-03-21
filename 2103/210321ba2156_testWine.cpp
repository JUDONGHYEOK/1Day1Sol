#include<iostream>
#include<vector>

using namespace std;

int main(){

    int number;
    vector<int> wine;
    cin>>number;
    vector<vector<int>> caseBy(3,vector<int>(number,-1));

    for(int i=0;i<number;i++){
        int amountOfWine;
        cin>>amountOfWine;
        wine.push_back(amountOfWine);
    }
    if(number>2){
        caseBy[0][0]=wine[0];
        caseBy[1][0]=wine[0];
        caseBy[1][1]=wine[1];
        caseBy[2][1]=wine[1];
        caseBy[0][2]=wine[2];
        caseBy[2][2]=wine[2];
        for(int i=3;i<number;i++){
            for(int j=0;j<3;j++){
                if(caseBy[j][i-2]!=-1&&caseBy[j][i-2]);
            }
        }

    }else{
        int sum=0;
        for(int i=0;i<number;i++){
            sum+=wine[i];
        }
        cout<<sum;
    }




    return 0;
}