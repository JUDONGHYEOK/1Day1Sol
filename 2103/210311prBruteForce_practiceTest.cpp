#include <string>
#include <vector>
#define SIZE_OF_CASE1 5
#define SIZE_OF_CASE2 8
#define SIZE_OF_CASE3 10

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int case1[SIZE_OF_CASE1]={1,2,3,4,5};
    int case2[SIZE_OF_CASE2]={2,1,2,3,2,4,2,5};
    int case3[SIZE_OF_CASE3]={3,3,1,1,2,2,4,4,5,5};
    int score1=0,score2=0,score3=0;
    for(int i=0,j=answers.size();i<j;i++){
        if(answers[i]==case1[i%SIZE_OF_CASE1])
            score1++;
        if(answers[i]==case2[i%SIZE_OF_CASE2])
            score2++;
        if(answers[i]==case3[i%SIZE_OF_CASE3])
            score3++;
    }
    int cmp=score1;
    if(cmp<score2)
        cmp=score2;
    if(cmp<score3)
        cmp=score3;
    if(cmp==score1)
        answer.push_back(1);
    if(cmp==score2)
        answer.push_back(2);
    if(cmp==score3)
        answer.push_back(3);
    return answer;
}