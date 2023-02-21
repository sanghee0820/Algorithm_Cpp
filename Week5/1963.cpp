#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
using namespace std;

bool Prime[10000];
bool Visit[10000];


void Eratosthenes(){
    for (int i = 2; i < 10000; i++)
    {
        for (int j = 2; i*j < 10000; j++)
        {
            Prime[i*j] = false;
        }
    }

}

void BFS(int start, int end){
    queue<int> Search_Queue;

    Search_Queue.push( start );
    Visit[start] = true;
    int count = 0;
    while(Search_Queue.size()){
        int size = Search_Queue.size();
        for(int i = 0; i < size; i++){

            int Cur = Search_Queue.front();
            Search_Queue.pop();

            if(Cur == end){
                cout << count << endl;
                return;
            }

            for(int j = 0; j < 4; j++){
                int Next;
                for(int k = 0; k < 10; k++){
                    string s = to_string(Cur);
                    s[j] = k + '0';
                    Next = stoi(s);
                    if(Prime[Next] == false) continue;
                    if(Visit[Next] == true) continue;
                    if(Next > 9999 || Next < 1000) continue;

                    Visit[Next] = true;
                    Search_Queue.push(Next);
                }
            }
        }
        count ++;
    }
    cout << "Impossible" << endl;
}
int main(){
    int N;
    int input[2];

    memset(Prime, true, sizeof(Prime));
    cin >> N;
    Eratosthenes();
    for(int i = 0; i < N; i++){
        cin >> input[0] >> input[1];

        memset(Visit, false, sizeof(Visit));
        BFS(input[0], input[1]);
    }
    return 0;
}