#include <iostream>
#include <map>
#include<vector>
#include<algorithm>

using namespace std;
class Score{
    public:
    char state;
    double score;
    int x;
    int y;
    Score(char st='0',double sc=0,int indexX=0,int indexY=0):state(st),score(sc),x(indexX),y(indexY){}
    void print(){
        cout<<state<<" "<<score<<" "<<x<<" "<<y<<endl;
    }
};
bool compare(Score a, Score b){
    if(a.score == b.score){   
        if(a.x==b.x){
            return a.y<b.y;
        }else{
            return a.x<b.x;
        }
    }else{                  
        return a.score > b.score;
    }
    
}

int main() {
	map<char,double>mp;
	double d;
	cin>>d;
	mp.insert({'A',d});
    cin>>d;
    mp.insert({'B',d});
	cin>>d;
	mp.insert({'C',d});
    cin>>d;
    mp.insert({'D',d});
    cin>>d;
    mp.insert({'E',d});

    int row,column;
    cin>>row>>column;
    multimap<char,pair<char,pair<int,int>>>multi;
    vector<char>index;
    vector<vector<char>> v(row,vector<char>(column,0));

    for(int i=0;i<row;i++){
        string s;
        cin>>s;
        for(int j=0;j<column;j++){
            v[i][j]=s[j];
        }
    }
    for(int i=0;i<row;i++){
        string s;
        cin>>s;
        for(int j=0;j<column;j++){
            multi.insert({v[i][j],{s[j],{i,j}}});
        }
    }
    
    cout.precision(1);
    cout<<fixed;
    vector<Score>scoreY;
    for(auto i=multi.lower_bound('Y');i!=multi.upper_bound('Y');i++){
        Score sc(i->second.first,mp[i->second.first],i->second.second.first,i->second.second.second);

        scoreY.push_back(sc);
    }
    sort(scoreY.begin(),scoreY.end(),compare);
    for(int i=0;i<scoreY.size();i++){
        scoreY[i].print();
    }
    vector<Score>scoreO;
    for(auto i=multi.lower_bound('O');i!=multi.upper_bound('O');i++){
        Score sc(i->second.first,mp[i->second.first],i->second.second.first,i->second.second.second);
        scoreO.push_back(sc);
    }
    sort(scoreO.begin(),scoreO.end(),compare);
    for(int i=0;i<scoreO.size();i++){
        scoreO[i].print();
    }


	return 0;
}