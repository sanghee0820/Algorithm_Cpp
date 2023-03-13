#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int** Matrix;
bool visited[1001][1001][2];
queue< pair<pair<int,int>, pair<int,int> > > q; // Pair < x, y > , Pair < Crashed, distance >

int bfs(){
    visited[0][0][0] = true;
    visited[0][0][1] = true;
    q.push( make_pair(make_pair(0,0),make_pair(0,1))); // <0,0> < No crashed, distance = 0>


    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int crashed = q.front().second.first;
        int distance = q.front().second.second;
        q.pop();

        if(x == N-1 && y == M-1) {
            return distance;
        }

        for(int a = 0; a<4; a++)
        {
            int next_x = x + dx[a];
            int next_y = y + dy[a];
            //맵을 벗어나지 않았고, next_x,next_y에 방문한 적이 없을 때.
            if( (next_x >=0 && next_x <=N-1) && (next_y >=0 && next_y <= M-1) && visited[next_x][next_y][crashed]==false){
                if(crashed ==0 && Matrix[next_x][next_y] == 0) // crashed = false , No wall
                {
                    visited[next_x][next_y][crashed] =true;
                    q.push( make_pair( make_pair(next_x,next_y), make_pair(0,distance+1) ));
                }
                else if(crashed ==0 && Matrix[next_x][next_y] == 1) // crashed  = false, Wall;
                {
                    visited[next_x][next_y][crashed] = true;
                    q.push( make_pair( make_pair(next_x,next_y), make_pair(1,distance+1) ));
                }
                else if(crashed ==1 && Matrix[next_x][next_y] == 0) // crashed = true, Wall;
                {
                    visited[next_x][next_y][crashed] = true;
                    q.push( make_pair( make_pair(next_x,next_y), make_pair(1,distance+1) ));
                }
            }
        }
    }
    return -1;
}

int main(){
    cin >> N >> M;
    Matrix = (int**)malloc(sizeof(int*) * N);

    for(int i = 0 ; i < N ; i++)
    {
        Matrix[i] = (int*)malloc(sizeof(int) * M);
        string temp;
        cin >> temp;
        for(int j = 0 ; j < M ; j++)
        {
            Matrix[i][j] = temp[j] - '0';
        }
    }
    cout << bfs() ;

    return 0;
}