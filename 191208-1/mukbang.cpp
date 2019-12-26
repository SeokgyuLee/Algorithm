//
// Created by 이석규 on 2019/12/26.
//
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    int foodCnt = 0;
    int clock = 0;

    while(clock<10){
        if(foodCnt+1>food_times.size()) {
            foodCnt = 1;
        }else{
            foodCnt++;
        }
        clock++;
        if(clock == k )
        {
            foodCnt--;
            break;
        }

        if(food_times[foodCnt]==0)
        {
            clock--;
            continue;
        }
        else if(food_times[foodCnt] > 0)
            food_times[foodCnt]--;
    }
    cout<<foodCnt;
    return answer;
}

int main(){
    vector<int> food_times = {3, 1, 2};
    int k = 5;
    solution(food_times,k);
    return 0;

}