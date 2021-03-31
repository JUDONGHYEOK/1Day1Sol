#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int number;
    cin>>number;
    for(int i=0;i<number;i++){
        int size=0;
        cin>>size;
        vector<vector<int>>list(2,vector<int>(size,0));
        for(int j=0;j<2;j++){
            for(int k=0;k<size;k++){
                cin>>list[j][k];
            }
        }
        vector<int> dpUp(size,0);
        vector<int> dpDown(size,0);
        dpUp[0]=list[0][0];
        dpDown[0]=list[1][0];

        dpUp[1]=dpDown[0]+list[0][1];
        dpDown[1]=dpUp[0]+list[1][1];

        for(int j=2;j<size;j++){
            dpUp[j]=max(dpDown[j-1]+list[0][j],dpDown[j-2]+list[0][j]);
            dpDown[j]=max(dpUp[j-1]+list[1][j],dpUp[j-2]+list[1][j]);
        }

        cout<<max(dpUp[size-1],dpDown[size-1])<<endl;
    }



    return 0;
}