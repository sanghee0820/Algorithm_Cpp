#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;


void BFS(int** Matrix, int x, int y, int N, int M){
    queue<pair<int,int> > adj_queue;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    adj_queue.push(make_pair(x,y));
    Matrix[y][x] = 0;

    while(!adj_queue.empty()){
        int tempx, tempy;

        tempy = adj_queue.front().second;
        tempx = adj_queue.front().first;

        adj_queue.pop();

        for(int i = 0; i < 4; i++){
            int newx, newy;
            newx = tempx + dx[i];
            newy = tempy + dy[i];
            if( (newx > -1 && newx < M) && (newy > -1 && newy < N) ) {
                if( Matrix[newy][newx]){
                    adj_queue.push(make_pair(newx, newy));
                    Matrix[newy][newx] = 0;
                }
            }
        }

    }
}
int main(){

    int Test_N;

    cin >> Test_N;


    while(Test_N--){

        int N, M, K;
        int** Matrix;
        cin >> M >> N >> K;

        Matrix = (int**)malloc(sizeof(int*) * N);
        for(int j = 0; j < N; j++) Matrix[j] = (int*)malloc(sizeof(int) * M);
        for(int j = 0; j < K; j++){
            int X, Y;
            cin >> X >> Y;
            Matrix[Y][X] = 1;
        }

        int worm = 0;
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                if( Matrix[j][k] ){
                    BFS(Matrix, k, j, N, M);
                    worm++;
                }
            }
        }
        cout << worm << endl;
        
    }


    return 0;
}