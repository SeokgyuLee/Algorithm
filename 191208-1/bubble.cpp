#define MAX 10
#include <iostream>
#include <stack>

using namespace std;

char map[MAX][MAX];
int N,M ;// N - 세로, M - 가
stack<pair<int,int>> stk;
// 동, 서, 남, 북
int moveY[4] ={0,0,-1,1};
int moveX[4] ={1,-1,0,0};

bool finishFlag = false;

pair<int,int> red;
pair<int,int> blue;

int main() {
    int cnt=0;
    cin>> N>>M;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin>>map[N][M];
            if(map[N][M]=='R')
                red = make_pair(N,M);
            if(map[N][M]=='B')
                blue = make_pair(N,M);
        }
    }

    while(!finishFlag&&cnt<=10) // Red가 0을 지나가면 finishFlag가 true로 바뀜, cnt는 기우는 회수
    {
        for (int i = 0; i < 4; ++i)
        {
            if(map[red.first+moveY[i]][red.second+moveX[i]]=='.') {
                stk.push(make_pair(red.first + moveY[i], red.second + moveX[i]));
            }
        }

        stk.pop();
    }
    /*
     * R에서 4방향을 돈 다음 .이 있는 곳으로 일단 직진,
     * #을 만나면 한칸 뒤로 빠지고 cnt++,
     *
     *
     *
     */
}













