#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int BFS(char** Matrix, int N, int M){
    queue < pair<int, int> > Search_Queue;
    Search_Queue.push(make_pair(0, 0));

    Matrix[0][0] = 0;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int distance = 1;
    while( Search_Queue.size() ){
        int size = Search_Queue.size();
        int X, Y;

        for(int i = 0; i < size; i++){
            
            X = Search_Queue.front().first;
            Y = Search_Queue.front().second;
            Search_Queue.pop();

            if(X == N-1 && Y == M-1) return distance;
            for(int j = 0; j < 4; j++){
                int newX = X + dx[j];
                int newY = Y + dy[j];
                if((newX > -1 && newX < N) && (newY > -1 && newY < M)){
                    if(Matrix[newX][newY] == '1'){
                        Search_Queue.push(make_pair(newX, newY));
                        Matrix[newX][newY] = 0;
                    }
                }
            }
        }

        distance++;
    }

    return distance;
}
int main(){
    int N, M;
    char** Matrix;

    cin >> N >> M;
    Matrix = (char**)malloc(sizeof(char*) * N);
    for(int i = 0; i < N; i++){
        Matrix[i] = (char*)malloc(sizeof(char) * M+1);
        cin >> Matrix[i];
    }

    cout << BFS(Matrix, N, M) << endl;

    return 0;
}