#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<queue>
#define INF 1e9

using namespace std;

int main(){
    unordered_map<string,int>up;
    int number;
    cin>>number;
    int unique=0;
    vector<pair<int,int>>v;
    vector<int>distance(number,0);
    for(int i=0;i<number;i++)
    {
        string from,to;
        cin>>from>>to;
        if(up.find(from)==up.end()){
            up[from]=unique;
            unique++;
        }
        if(up.find(to)==up.end()){
            up[to]=unique;
            unique++;
        }
        cin>>distance[i];
        v.push_back({up[from],up[to]});
    }
    vector<pair<int,int>>arr[up.size()+1];
    for(int i=0;i<v.size();i++){
        arr[v[i].first].push_back({v[i].second,distance[i]});
        arr[v[i].second].push_back({v[i].first,distance[i]});
    }
    int dist[up.size()+1];
    fill(dist,dist+up.size()+1,INF);
    priority_queue<pair<int,int>>qu;

    int start=3;
    qu.push({0,start});
    dist[start]=0;

    while(!qu.empty()){
        int cost=-qu.top().first;
        int here=qu.top().second;
        qu.pop();

        for(int i=0;i<arr[here].size();i++){
            int next=arr[here][i].first;
            int nextcost=arr[here][i].second;

            if(dist[next]>dist[here]+nextcost){
                dist[next]=dist[here]+nextcost;
                qu.push({-dist[next],next});
            }
        }
    }
    for(int i=0;i<=up.size()-1;i++){
        if(i!=start)
            cout<<dist[i]<<" ";
    }
    return 0;
}