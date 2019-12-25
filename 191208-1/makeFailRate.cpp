//
// Created by 이석규 on 2019/12/24.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
bool desc(pair <double, int>  a, pair <double, int>  b)
{
    if(a.first!=b.first) {
        return a > b;
    }
    else{
        return a<b;
    }
}


vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int failCnt[N+1];
    double failRate[N+1];
   vector <pair <double, int>> pairAns;

    for (int j = 0; j < N+1; ++j) {
        failRate[j] = 0;
        failCnt[j]=0;
    }

    sort(stages.begin(),stages.end());

    for (int i = 0; i <stages.size() ; ++i) {
        cout<<stages[i]<<" ";
        failCnt[stages[i]]++;
    }
    cout<<endl;

    for (int i = 0; i <=N; ++i) {
        cout<<failCnt[i]<<" ";
    }
    int totChalenger = stages.size();
    for (int k = 1; k <= N; ++k) {
        if(failCnt[k]!=0)
            failRate[k] = (double)failCnt[k]/(double)totChalenger;

        totChalenger -= failCnt[k]; // 도전자 수 추정

        pairAns.push_back( make_pair(failRate[k],k));
    }

    sort(pairAns.begin(),pairAns.end(),desc);

    cout<<endl;
    for (int i = 0; i <= N; ++i) {
        cout<<failRate[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < pairAns.size(); ++i) {
        cout<<pairAns.at(i).first<<" ";
    }
    cout<<endl;
    for (int i = 0; i < pairAns.size(); ++i) {
        cout<<pairAns.at(i).second<<" ";
    }
    return answer;
}

int main(){
    //int N = 5;
    //vector<int> testCase ={2, 1, 2, 6, 2, 4, 3, 3};

    int N = 4;
    vector<int> testCase ={4,4,4,4,4};
    solution(N, testCase);
}