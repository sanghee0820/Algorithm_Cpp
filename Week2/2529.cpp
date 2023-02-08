#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

char* func;
long long max_number = 0;
long long min_number = 100000000000;
char number[11] = "0123456789";
int check[10];


void DFS(int cnt, int N){
    if( cnt == N + 1){
        long long solution = 0;
        for(int i = 0; i < N; i++){
            switch(func[2*i + 1]){
                case('<'):{
                    if(func[2*i] < func[2*i + 2]){
                        solution += pow(10,N - i) * (func[2*i] - 48);
                        break;
                    }
                    else{
                        return;
                    }
                }
                case('>'):{
                    if(func[2*i] > func[2*i + 2]){
                        solution += pow(10,N - i) * (func[2*i] - 48);
                        break;
                    }
                    else{
                        return;
                    }
                }
                default: break;
            }
        }
        solution += pow(10, 0) * (func[2*N] - 48);
        if( max_number < solution) max_number = solution;
        if( min_number > solution) min_number = solution;
        return;
    }

    for(int i = 0; i < 10; i++){
        if( check[i] != 0 ) continue;
        func[cnt*2] = number[i];
        if(cnt > 0){
            switch(func[2*cnt - 1]){
                    case('<'):{
                        if(func[2*cnt - 2] < func[2*cnt]){
                            break;
                        }
                        else{
                            continue;
                        }
                    }
                    case('>'):{
                        if(func[2*cnt - 2] > func[2*cnt]){
                            break;
                        }
                        else{
                            continue;
                        }
                    }
                    default: break;
            }
        }
        check[i] = 1;
        DFS(cnt + 1, N);
        check[i] = 0;
    }
}
int main(){
    int N;
    cin >> N;
    func = (char*)malloc(sizeof(char) * N * 2 + 1);
    for(int i = 0 ; i < N * 2 + 1; i++){
        if( i % 2 == 1) cin >> func[i];
        else func[i] = '0';
    }
    DFS(0, N);

    cout.width(N + 1);
    cout.fill('0');
    cout << max_number << endl;

    cout.width(N + 1);
    cout.fill('0');
    cout << min_number;

    return 0;
}