//
// Created by 이석규 on 2019/12/23.
//
#include <iostream>
#include <Algorithm>
#include <string>

using namespace std;

const int MAX = INT_MAX;
const int smallMax = 10;

int row,col;
int minCnt = MAX;
int dy[4] = {0,1,0,-1};
int dx[4] = {-1,0,1,0};

typdef struct{
    int y,x;
}Coord;

//기울이는 방향 0:서, 1:북, 2:동, 3:남
void tilt(string board[smallMax],int dir, int cnt, Coord R, Coord B)
{
    if(++cnt>10) // 기저사
        return;

    string copy[MAX];
    for (int i = 0; i < col; i++) {
        copy[i]= board[i]; // 보드판 복사
    }

    bool red = false, blue = false; // 목적지에 도달했는가례

    //0 : R먼저 1: B 먼저
    int order = 0;
    switch (dir){
        case 0: // 서쪽
            if(B.x<R.x) // B가 R보다 왼쪽에 있을 경우
                order =1;
            break;
        case 1: // 북쪽
            if(B.y<R.y) // B가 R보다 위에있을 경우
                order =1 ;
            break;
        case 2: // 동쪽
            if(B.x>R.x) // B가 R보다 동쪽에 있을 경우
                break;
        case 3:
            if(B.y> R.y) // B가 R보다 아래에 있을 경우
                order = 1;
            break;
    }
    if( order == 0 )
    {
        while(1) // R
        {
            int nextY = R.y + dy[dir];
            int nextX = R.y + dy[dir];
            if(copy[nextY][nextX]=='#') // 막히면 그만 움직인다.
                break;
            if(copy[nextY][nextX]=='0') { // 목적지에 도달하면
                copy[R.y][R.x] = '.';
                R.y = R.x = -1;
                red = true;
                break;
            }
            copy[R.y][R.x] = '.';
            copy[nextY][nextX] = 'R';
            R.y = nextY;
            R.x = nextX;
        }
        while (1) //B

        {
            int nextY = B.y + dy[dir];
            int nextX = B.x + dx[dir];
            if (copy[nextY][nextX] == '#' || copy[nextY][nextX] == 'R') //R과 B는 동일선상에 있을 수 없다
                break;
            if (copy[nextY][nextX] == 'O')
            {
                copy[B.y][B.x] = '.';
                B.y = B.x = -1;
                blue = true;
                break;
            }

            copy[B.y][B.x] = '.';
            copy[nextY][nextX] = 'B';
            B.y = nextY;
            B.x = nextX;
        }
    }
    else
    {
        while (1) //B
        {
            int nextY = B.y + dy[dir];
            int nextX = B.x + dx[dir];
            if (copy[nextY][nextX] == '#')
                break;
            if (copy[nextY][nextX] == 'O')
            {
                copy[B.y][B.x] = '.';
                B.y = B.x = -1;
                blue = true;
                break;
            }
            copy[B.y][B.x] = '.';
            copy[nextY][nextX] = 'B';
            B.y = nextY;
            B.x = nextX;
        }
        while (1) //R
        {
            int nextY = R.y + dy[dir];
            int nextX = R.x + dx[dir];
            if (copy[nextY][nextX] == '#' || copy[nextY][nextX] == 'B')
                break;
            if (copy[nextY][nextX] == 'O')
            {
                copy[R.y][R.x] = '.';
                R.y = R.x = -1;
                red = true;
                break;
            }
            copy[R.y][R.x] = '.';
            copy[nextY][nextX] = 'R';
            R.y = nextY;
            R.x = nextX;
        }
    }
    if (blue) //파랑이 빠지면 안됨
        return;
    else if (red)
    {
        minCnt = min(cnt, minCnt);
        return;
    }
    for (int i = 0; i < 4; i++)
        //같은 방향이면 벽이므로 무의미, 반대방향이면 그 전 위치로 가므로 무의미
        if (i != dir || i != (3 - dir))
            tilt(copy, i, cnt, R, B); //변경된 상태인 보드를 넘긴다
}


}


int main(void)
{
    Coord R,B;
    string Board[MAX];
    cin>>col>>row;

    if (col < 3 || col>10 || row < 3 || row>10)
        exit(-1);

    for (int i = 0; i < col; i++) {
        cin>>board[i];
        for (int j = 0; j < row; j++) {
            if(board[i][j]=='R')
            {
                R.y = i, R.x = j;
            }
            else if(board[i][j]=='B')
            {
                B.y = i, B.x = j;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        tilt(board, i, 0, R, B);
    }
    if(minCnt == MAX)
    {
        cout<<-1<<endl;
    }else{
        cout<<minCnt<<endl;
    }
    return 0;

}
