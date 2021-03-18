#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    int i=1;
    while(1){
        int l,p,v;
        cin>>l>>p>>v;
        if(l==0){
            break;
        }
        int mod=v%p;
        int qu=v/p;
        int answer=qu*l;
        if(mod>=l){
            answer+=l;
        }else{
            answer+=mod;
        }
        cout<<"Case "<<i<<": "<<answer<<endl;
        i++;
    }
    return 0;

}