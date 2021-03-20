#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
	int number;
	int total=0;
	cin>>number;
	vector<int> place[number+1];
    vector<int> size;
    size.resize(51);
	for(int i=0;i<number+1;i++){
		place[i].resize(number+1);
	}
    for(int i=0;i<number;i++){
        string s;
        cin>>s;
        for(int j=0;j<number;j++){
            int black=s[j]-'0';
            if(black==1){
                place[i][j]=1;
                total++;
            }
        }
    }
	size[0]=total;
    int count=1;
    while(1){
        for(int i=0;i<number-count;i++){
            for(int j=0;j<number-count;j++){
                if(place[i][j]==0)
                    continue;
                bool isLinked=true;
                for(int p=0;p<count+1;p++){
                    for(int q=0;q<count+1;q++){
                        if(place[i+p][j+q]==0){
                            isLinked=false;
                            break;
                        }
                    }
                    if(!isLinked)
                        break;
                }
                if(isLinked){
                    size[count]++;
                    }
            }
        }
        if(size[count]==0||count+1==number)
            break;
        total+=size[count];
        count++;
    }
    cout<<"total: "<<total<<endl;
    for(int i=0;i<size.size();i++){
        if(size[i]==0)
            break;
        cout<<"size["<<i+1<<"]: "<<size[i]<<endl;
    }
	return 0;
}