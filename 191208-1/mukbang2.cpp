//
// Created by 이석규 on 2019/12/26.
//

//
// Created by 이석규 on 2019/12/26.
//
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    long long foodCnt = 0;
    long long clock = 0;
    bool flag = true;

    while(1)
    {
        //cout<<clock<<endl;
        if(foodCnt>=food_times.size()) {
            foodCnt = 0;
        }
        if(clock >= k )
        {
            for (int i = 0; i < food_times.size(); ++i) {
                if(food_times.at(i)!=0)
                    flag = false;
            }
            if(flag == true )
                foodCnt = -2;
            break;
        }

        if(food_times[foodCnt]==0)
        {
            foodCnt++;
            continue;
        }
        else if(food_times[foodCnt] > 0) {
            food_times[foodCnt]--;
            clock++;
        }
        foodCnt++;
    }
    if(flag == false&&food_times[foodCnt]==0)
        while(1)
        {
            foodCnt++;
            if(foodCnt>=food_times.size()) {
                foodCnt = 0;
            }
            if(food_times[foodCnt]!=0)
            {
                break;
            }
        }
    answer = foodCnt+1;
    // cout<<answer;
    return answer;
}

int main(){
    vector<int> food_times = {4,1,1,5};
    long long k = 4;
    solution(food_times,k);
    return 0;

}